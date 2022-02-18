#include <ESP8266WiFi.h>
#include <FirebaseArduino.h> 

#define FIREBASE_HOST "skku-iot-lecture-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH ""                                  // 데이터베이스 접속 키
#define WIFI_SSID "203_2G"                            // 와이파이 SSID
#define WIFI_PASSWORD "0000005F57*"                        // 와이파이 Password
#define pinRED D7
#define pinGRE D8

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

 pinMode(D7,OUTPUT);
 pinMode(D8,OUTPUT);
  
  //파이어베이스 연결
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  //아날로그값 입력 및 온도값 계산
  float temp = analogRead(A0);
  temp = round((temp*320/1024 - 50)*10)/10;
  
  Serial.print("temp : ");
  Serial.println(temp);
  
  
  /*//온도값 데이터베이스에 업로드
  Firebase.setFloat("HOME/Temperature", temp);
  //Firebase.setFloat("HOME/LUX", LUX);
  if(temp > 30){
    Firebase.setString("State", "HIGH");
    Firebase.setInt("Green", 0);
    Firebase.setInt("Red", 1);
  }else{
    Firebase.setString("State", "LOW");
    Firebase.setInt("Green", 1);
    Firebase.setInt("Red", 0);
  }
  */
  digitalWrite(pinRED, Firebase.getInt("Red"));
  digitalWrite(pinGRE, Firebase.getInt("Green"));
  
  delay(2000);
}
