// Practice Switch 2

#define PIN_RED D7
#define PIN_GRE D8
#define PIN_SWL D2
#define PIN_SWR D4

bool cState_swl = false;
bool cState_swr = false;
bool lState_swl = false;
bool lState_swr = false;
bool valRed = false;
bool valGre = false;

void setup() {
  pinMode(PIN_RED,OUTPUT);
  pinMode(PIN_GRE,OUTPUT);
  pinMode(PIN_SWL,INPUT);
  pinMode(PIN_SWR,INPUT);
}

void loop() {
  cState_swl = digitalRead(PIN_SWL);
  cState_swr = digitalRead(PIN_SWR);
  delay(50);
  
  if (cState_swl && (cState_swl != lState_swl)) {
    valRed = !valRed;
    digitalWrite(PIN_RED,valRed);  
  }

  if (cState_swr && (cState_swr != lState_swr)) {
    valGre = !valGre;
    digitalWrite(PIN_GRE,valGre);  
  }

  lState_swl = cState_swl;
  lState_swr = cState_swr;
}
