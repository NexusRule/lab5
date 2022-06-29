/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/fxxsj/OneDrive/Desktop/lab5/src/lab5.ino"
void setup();
void loop();
#line 1 "c:/Users/fxxsj/OneDrive/Desktop/lab5/src/lab5.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#define PHOTO A5
#define LIGHT D5
int DIO = 0;
int maxcal;
int mincal;

void setup()
{
  pinMode(A5, INPUT);
  pinMode(D5, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  //auto-cal
  DIO = analogRead(A5);
  if (DIO < maxcal)
  {
    maxcal = DIO;
  }
  else if (DIO > mincal) {
    mincal = DIO;
  }
  Serial.println(maxcal);
  Serial.print("max - ");
  //now for the LED
  int JOTARO = map(DIO, mincal, maxcal, 0, 255);
  analogWrite(D5, JOTARO);
}