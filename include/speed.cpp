#include <variable_def.h>
#include<Arduino.h>

void speedISR(){
  totalCounts++;
}
void setup_speed(){
  attachInterrupt(digitalPinToInterrupt(speedPin),speedISR,FALLING);
}

void SpeedCount(unsigned long period){
  if(millis()-lastTime<period)
  return;
  detachInterrupt(digitalPinToInterrupt(speedPin));
  Speed=((totalCounts*5032.832)/period)/slits;    //Speed=((totalCounts/slits)*(pi*(Wheel di)/100)*3.6)/(period/1000)
  lastTime=millis();                              // where wheel dia(cm)=44.5 cm ,
  totalCounts=0;
  attachInterrupt(digitalPinToInterrupt(speedPin),speedISR,FALLING);
}