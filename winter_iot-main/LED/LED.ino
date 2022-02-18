// LED : GPIO 1
#define PIN_RED D7 
#define PIN_GRE D8 
#define SW1 D2
#define SW2 D4
void setup(){
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GRE, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);}
void loop(){
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_GRE, HIGH);
  delay(100);
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_GRE, LOW);  
  delay(100);
  }
