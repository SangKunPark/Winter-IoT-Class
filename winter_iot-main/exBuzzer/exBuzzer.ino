#include "buzzer.h"

#define PIN_BUZ D3

int ArraySize = sizeof(Korean_National_Anthem_M)/sizeof(int);
int TaegeukgiSize = sizeof(Taegeukgi)/sizeof(char);
                 
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
  for(int i=0; i<TaegeukgiSize; i++)
  {
    if (i%30==0) Serial.println();
    Serial.print(Taegeukgi[i]); 
    Serial.print(" ");     
  }
  for(int i=0; i<ArraySize; i++)
  {
    BuzzerPlay(PIN_BUZ, Korean_National_Anthem_M[i],Korean_National_Anthem_R[i]);
  }
  delay(10000);
}
