#include "buzzer.h"

#define PIN_BUZ D3

int ArraySize = sizeof(jinglebell_M)/sizeof(int);
                 
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_BUZ, OUTPUT);
}

void BuzzerPlay(int PIN, int FREQ, int LENGTH)
{ // BuzzerPlay( , [Hz], [ms])
  int duty_cycle = 50;
  if(FREQ == 0)
  { 
    noTone(PIN);
  }
  else
  {
    analogWriteFreq(FREQ);
    analogWrite(PIN, duty_cycle);
  }
  delay(LENGTH*250);
}

void loop() 
{
  for(int i=0; i<ArraySize; i++)
  {
    BuzzerPlay(PIN_BUZ, jinglebell_M[i],jinglebell_R[i]);
  }
  delay(10000);
}
