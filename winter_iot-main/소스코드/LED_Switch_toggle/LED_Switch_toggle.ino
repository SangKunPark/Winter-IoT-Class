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
  
  bool valRED = 0;
  bool valGRE = 0;
void loop(){
  
  bool valSWL = digitalRead(PIN_SWL); // read signal from left switch
  bool valSWR = digitalRead(PIN_SWR); // read signal from right switch
  if(valSWL == 1){
    if (valRED == 1){
      valRED =0;
    }
    else {
      valRED =1;
    }
  }
  if(valSWR == 1){
    if (valGRE == 1){
      valGRE =0;
    }
    else {
      valGRE =1;
    }
  }
  if (valRED == 1){
  digitalWrite(PIN_RED, HIGH);
  }
  else {
  digitalWrite(PIN_RED, LOW);
  }
  if (valGRE == 1) {
  digitalWrite(PIN_GRE, HIGH);
  }
  else {
  digitalWrite(PIN_GRE, LOW);
  }

  delay(300);
  }
