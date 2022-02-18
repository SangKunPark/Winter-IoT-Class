// Maximum value of PWM
#define MAX_PWM 1023

#define PIN_RED D3
#define PIN_GRE D5
#define PIN_SWL D2
#define PIN_SWR D4

bool cState_swl = false;
bool cState_swr = false;
bool lState_swl = false;
bool lState_swr = false;
int valDuty = 0;


void setup(){
  pinMode(PIN_SWL,INPUT);
  pinMode(PIN_SWR,INPUT);
}

void loop() {
  cState_swl = digitalRead(PIN_SWL);
  cState_swr = digitalRead(PIN_SWR);
  delay(50);
  
  if (cState_swl && (cState_swl != lState_swl)) {
    valDuty = valDuty + 100;
    if(valDuty > MAX_PWM) valDuty = MAX_PWM;
    
    analogWrite(PIN_RED, valDuty);
    analogWrite(PIN_GRE, valDuty);
  }

  if (cState_swr && (cState_swr != lState_swr)) {
    valDuty = valDuty - 100;
    if(valDuty < 0) valDuty = 0;
    
    analogWrite(PIN_RED, valDuty);
    analogWrite(PIN_GRE, valDuty);
  }
  
  lState_swl = cState_swl;
  lState_swr = cState_swr;
}
