//Light Sensor : ADC 0
#define PIN_TEMP A0
#define PIN_RED D7 
#define PIN_GRE D8 
void setup()
{
pinMode(PIN_RED, OUTPUT);
pinMode(PIN_GRE, OUTPUT);
Serial.begin(9600);
}
void loop()
{
float valTemp = analogRead(PIN_TEMP);
valTemp = valTemp * 320/1023-50;
Serial.print("Temperature : ");
Serial.print(valTemp,1);
Serial.println(" C");
if (valTemp < 25.0){
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GRE, HIGH);  
}
else{
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GRE, LOW);  
}
delay(500);
}
