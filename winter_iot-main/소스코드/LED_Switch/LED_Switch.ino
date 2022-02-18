// LED : GPIO 1
#define PIN_RED D7 
#define PIN_GRE D8 
#define PIN_SWL D2
#define PIN_SWR D4
void setup(){
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GRE, OUTPUT);
  pinMode(PIN_SWL, INPUT);
  pinMode(PIN_SWR, INPUT);}
void loop(){
  
  bool valSWL = digitalRead(PIN_SWL); // read signal from left switch
  bool valSWR = digitalRead(PIN_SWR); // read signal from right switch
  if (valSWL == 1){
  digitalWrite(PIN_RED, HIGH);
  }
  else {
  digitalWrite(PIN_RED, LOW);
  }
  if (valSWR == 1) {
  digitalWrite(PIN_GRE, HIGH);
  }
  else {
  digitalWrite(PIN_GRE, LOW);
  }

  delay(100);
  }
