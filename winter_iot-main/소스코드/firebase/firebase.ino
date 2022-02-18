#include <ESP8266WiFi.h>
#include <FirebaseArduino.h> 

#define FIREBASE_HOST "skku-winter-iot-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH ""                                  // 데이터베이스 접속 키
#define WIFI_SSID "203_2G"                            // 와이파이 SSID
#define WIFI_PASSWORD "0000005F57*"                        // 와이파이 Password
#define pinRED D7
#define pinGRE D8
#define swLEFT D2
#define swRIGHT D4
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
  Serial.println(WiFi.localIP());

 pinMode(pinRED,OUTPUT);
 pinMode(pinGRE,OUTPUT);
 pinMode(swLEFT,INPUT);
 pinMode(swRIGHT,INPUT);
  
  //파이어베이스 연결
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  //아날로그값 입력 및 온도값 계산
  float temp = analogRead(A0);
  temp = round((temp*320/1024 - 50)*10)/10;
  bool valLeft = digitalRead(swLEFT);
  bool valRight = digitalRead(swRIGHT);
  
  Serial.print("temp : ");
  Serial.println(temp);
  
  
  //온도값 데이터베이스에 업로드
  Firebase.setFloat("Temperature", temp);
  //Firebase.setFloat("HOME/LUX", LUX);
  if(valLeft == 1){
    Firebase.setInt("leftswitch", 1);
    Firebase.setInt("Green", 1);
  }
  else{
    Firebase.setInt("leftswitch", 0);
    Firebase.setInt("Green", 0);
  }
  if(valRight == 1){
    Firebase.setInt("rightswitch", 1);
    Firebase.setInt("Red", 1);
  }
  else{
    Firebase.setInt("rightswitch", 0);
    Firebase.setInt("Red", 0);
  }
  digitalWrite(pinRED, Firebase.getInt("leftswitch"));
  digitalWrite(pinGRE, Firebase.getInt("rightswitch"));
  if(Firebase.getString("AUTO") == "1"){
    digitalWrite(D2, Firebase.getInt("Red"));
    digitalWrite(D4, Firebase.getInt("Green"));
  }
  else{ 
    digitalWrite(D2, Firebase.getString("ledON")=="1");
    digitalWrite(D2, Firebase.getString("ledON")=="1");
  }
  delay(2000);
}
