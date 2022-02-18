//Light Sensor : ADC 0
#define PIN_LIGHT A0
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
int valLIGHT = analogRead(PIN_LIGHT);
if (valLIGHT <200){
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GRE, LOW);
}
else if (valLIGHT <400){
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GRE, HIGH);
}

else if (valLIGHT <600){
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GRE, LOW);
}

else {
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GRE, HIGH);
}
delay(500);
}
