#include <ESP8266WiFi.h>
#include <FirebaseArduino.h> 

#define FIREBASE_HOST "skku-winter-iot-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH ""                                  // 데이터베이스 접속 키
#define WIFI_SSID "203_2G"                            // 와이파이 SSID
#define WIFI_PASSWORD "0000005F57*"                        // 와이파이 Password
#define PIN_RED D7 
#define PIN_GRE D8
#define PIN_TEMP A0

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

 pinMode(PIN_RED,OUTPUT);
 pinMode(PIN_GRE,OUTPUT);  
 
 //파이어베이스 연결
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  float temp = analogRead(A0);
  temp = round((temp*320/1024 - 50)*10)/10;
  Firebase.setFloat("Temperature", temp);
  if(Firebase.getString("AUTO") == "1"){
    digitalWrite(PIN_GRE,HIGH);
    if (Firebase.getFloat("Temperature") < 30.0){
      digitalWrite(PIN_RED, LOW);
    }
    else{
      digitalWrite(PIN_RED, HIGH); 
    }
    
  }
  else{
    digitalWrite(PIN_GRE,LOW);
    if (Firebase.getString("ledON") == "1"){
      digitalWrite(PIN_RED, HIGH);
    }
    else{
      digitalWrite(PIN_RED, LOW); 
    }
    
  }
 }
