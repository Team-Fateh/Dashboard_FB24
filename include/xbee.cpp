#include<Arduino.h>
#include<variable_def.h>

void send_xbee(){
  Serial3.print(millis()); //millis
  Serial3.print(",");
  Serial3.print(RPM); //RPM
  Serial3.print(",");
  Serial3.print(temp); //Engine_Temp
  Serial3.print(",");
  Serial3.print(gear); //Gear
  Serial3.print(",");
  // Serial3.print(Speed_FR);   //speed_FR
  // Serial3.print(",");
  // Serial3.print(Speed_FL);   //speed_FL
  // Serial3.print(",");
  // Serial3.print(Speed_RR);   //speed_RR
  // Serial3.print(",");
  // Serial3.print(Speed_RL);   //speed_Rl
  // Serial3.print(",");
  Serial3.print("0");   //brake pressure
  Serial3.print(",");
  Serial3.print(volts); //Battery Voltage
  Serial3.print(",");
  Serial3.print(0);   //radiator
  Serial3.print(",");
  Serial3.print(0);   //datalogging
  Serial3.print(",");
  Serial3.print("0");   //brake temp
  Serial3.print(",");
  Serial3.print("0");   //front left load cell
  Serial3.print(",");
  Serial3.print("0");   //front right load cell
  Serial3.print(",");
  Serial3.print("0");   //rear left load cell
  Serial3.print(",");
  Serial3.print("0");   //rear right load cell
  Serial3.print(",");
  Serial3.print(fax);   //accelerometer x-axis
  Serial3.print(",");
  Serial3.print(fay);   //accelerometer y-axis
  Serial3.print(",");
  Serial3.print(faz);   //accelerometer z-axis
  Serial3.print(",");   
  // Serial.print(GPS); //GPS
  Serial3.print(",");
  Serial3.println("0");   //steering angle  
}