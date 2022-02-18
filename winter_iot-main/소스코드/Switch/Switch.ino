// Switch : GPIO 0
#define PIN_SWL D2
#define PIN_SWR D4

void setup()
{
  Serial.begin(9600); // 스위치 값 모니터링을 위한 부분 
  pinMode(PIN_SWL, INPUT);
  pinMode(PIN_SWR, INPUT);
}

void loop()
{
  bool valSWL = digitalRead(PIN_SWL); // read signal from left switch
  bool valSWR = digitalRead(PIN_SWR); // read signal from right switch

  Serial.print("Left Switch : ");
  Serial.print(valSWL);
  Serial.print(", Right Switch : ");
  Serial.println(valSWR);

  delay(200);
}
