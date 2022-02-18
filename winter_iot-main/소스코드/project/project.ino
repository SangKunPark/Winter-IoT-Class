#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "buzzer.h"

#define FIREBASE_HOST "skku-winter-iot-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH ""                                  // 데이터베이스 접속 키
#define WIFI_SSID "203_2G"                            // 와이파이 SSID
#define WIFI_PASSWORD "0000005F57*"      

#define PIN_BUZ D3
#define LED_RED D7
#define LED_GRE D8

int POWER = 0;
int ArraySize = sizeof(jinglebell_M)/sizeof(int);

void setup() {
  Serial.begin(9600);
  
  //와이파이 연결
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  
  //파이어베이스 연결
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  //핀모드 설정
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GRE,OUTPUT);
  pinMode(PIN_BUZ, OUTPUT);
  

  //전기장판단계 설정 0 = OFF 1 = 30 2부터 2씩 증가 최대 7 단계 
}
void BuzzerPlay(int PIN, int FREQ, int LENGTH)
{ // BuzzerPlay( , [Hz], [ms])
  int duty_cycle = 50;
  if(FREQ == 0)
  { 
    noTone(PIN);
  }
  else
  {
    analogWriteFreq(FREQ);
    analogWrite(PIN, duty_cycle);
  }
  delay(LENGTH*250);
}
void loop() {
  //온도 변환
  float temp1 = analogRead(A0);
  temp1 = round((temp1*320/1024 - 50)*10)/10;

/* 온도센서를 2개 사용할수 있다면 다른 하나는 전기장판의 온도를 읽어온다.
  float temp2 = analogRead(A1);
  temp2 = round((temp*320/1024 - 50)*10)/10;
  float temp_Set = Firebase.getString("temp_Set").substring(2,Firebase.getString("temp_Set").length()-2).toFloat()  
*/
  digitalWrite(LED_GRE, Firebase.getInt("Green"));
  digitalWrite(LED_RED, Firebase.getInt("Red"));

  //파이어베이스에 데이터 전송
  Firebase.setFloat("Temperature", temp1);
  Firebase.setInt("Power", POWER);

  //파이어베이스로부터 데이터를 전송받아서 처리함

  //AUTO 모드일때 동작
  if(Firebase.getString("AUTO") == "true"){
    Firebase.setInt("Green", 1);  
    if (temp1 >= 39.5){      
      POWER = 0;
      Firebase.setInt("Red", 1);
    }
    else if (temp1 >= 39){
      POWER = 0;
      Firebase.setInt("Red", 0);
    }
    else if (temp1 >= 38.5){
      POWER = 1;
      Firebase.setInt("Red", 0);
    }
    else if (temp1 >= 38) {
      POWER = 2;
      Firebase.setInt("Red", 0);
    }
    else if (temp1 >= 37.5){
      POWER = 3;
      Firebase.setInt("Red", 0);
    }
    else if (temp1 >= 37){
      POWER = 4;
      Firebase.setInt("Red", 0);
    }
    else if (temp1 >= 36.5){
      POWER = 5;
      Firebase.setInt("Red", 0);
    }
    else if (temp1 >= 36) {
      POWER = 6;
      Firebase.setInt("Red", 0);
    }
    else if (temp1 >= 35.5){
      POWER = 7;
      Firebase.setInt("Red", 0);
    }
    else {
      POWER = 0;
      Firebase.setInt("Red", 1);
    }

  
     

       

  }
    /* 전기장판 온도에 따른 온도 조절 
  else if {Firebase.getString("Temp_Mode") == "true")
  {
    if (temp2 >= 50){
      POWER = 0;    
      Firebase.setInt("Red", 1);    
    }
    else if (temp2 >= temp_Set + 3){      
      POWER = 0;
    }
    else if (temp2 >= temp_Set + 2){
      POWER = 1;
    }
    else if (temp2 >= temp_Set + 1){
      POWER = 2;
      }
    else if (temp2 >= temp_Set){
      POWER = 3;
      }
    else if (temp2 >= temp_Set - 1){
      POWER = 4;
      }
    else if (temp2 >= temp_Set - 2){
      POWER = 5;
      }
    else if (temp2 >= temp_Set - 3){
      POWER = 6;
      }
    else {
      POWER = 7;                              
    }      
  }
     */      
//Manual 모드에서의 동작
  else{
    Firebase.setInt("Green", 0);
    if (Firebase.getString("POWER").toFloat()>= 70.0){
      POWER = 7;
    }
    else if (Firebase.getString("POWER").toFloat() >= 60.0){
      POWER = 6;
    }
    else if (Firebase.getString("POWER").toFloat() >= 50.0){
      POWER = 5;
    }
    else if (Firebase.getString("POWER").toFloat() >= 40.0){
      POWER = 4;
    }
    else if (Firebase.getString("POWER").toFloat() >= 30.0){
      POWER = 3;
    }
    else if (Firebase.getString("POWER").toFloat() >= 20.0){
      POWER = 2;
    }
    else if (Firebase.getString("POWER").toFloat() >= 10.0){
      POWER = 1;
    }
    else{
      POWER = 0;
    }
  }

  //안전 동작은 AUTO 모드 여부와 관계없이 동작 및 부저 작동
  if (Firebase.getInt("Red") == 1){
    POWER = 0;
    digitalWrite(LED_RED, Firebase.getInt("Red"));
    for(int i=0; i<ArraySize; i++){          
      BuzzerPlay(PIN_BUZ, jinglebell_M[i],jinglebell_R[i]);
    }
  }
  Firebase.setInt("Power", POWER);
// 알람작동 시간을 firebase로부터 받아오지만, 아두이노에서도 받아오게 만들수 있다. 
  if (Firebase.getString("Alarm") == "true"){
    if(Firebase.getString("Hours").toFloat() == Firebase.getString("hours").substring(2,Firebase.getString("hours").length()-2).toFloat() || Firebase.getString("Minutes").toFloat() == Firebase.getString("minutes").substring(2,Firebase.getString("minutes").length()-2).toFloat()){
        for(int i=0; i<ArraySize; i++){          
          BuzzerPlay(PIN_BUZ, jinglebell_M[i],jinglebell_R[i]);
        }
    }
  }

  delay(2000);
  
}
