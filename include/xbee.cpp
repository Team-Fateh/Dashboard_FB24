#include<Arduino.h>
#include<variable_def.h>

void send_xbee(){
  Serial8.print(millis()); //millis
  Serial8.print(",");
  Serial8.print(RPM); //RPM
  Serial8.print(",");
  Serial8.print(temp); //Engine_Temp
  Serial8.print(",");
  Serial8.print(gear); //Gear
  Serial8.print(",");
  Serial3.print("0");   //speed_FR
  Serial3.print(",");
  // Serial3.print(Speed_FL);   //speed_FL
  // Serial3.print(",");
  // Serial3.print(Speed_RR);   //speed_RR
  // Serial3.print(",");
  // Serial3.print(Speed_RL);   //speed_Rl
  // SerSerial8al3.print(",");
  Serial8.print("0");   //brake pressure
  Serial8.print(",");
  Serial8.print(volts); //Battery Voltage
  Serial8.print(",");
  Serial8.print("0");   //radiator
  Serial8.print(",");
  Serial8.print("1");   //datalogging
  Serial8.print(",");
  Serial8.print("0");
  Serial.print(",");//Throttle
  Serial8.print("0");   //brake temp
  Serial8.print(",");
  Serial8.print("0");   //front left load cell
  Serial8.print(",");
  Serial8.print("0");   //front right load cell
  Serial8.print(",");
  Serial8.print("0");   //rear left load cell
  Serial8.print(",");
  Serial8.print("0");   //rear right load cell
  Serial8.print(",");
  Serial8.print(fax);   //accelerometer x-axis
  Serial8.print(",");
  Serial8.print(fay);   //accelerometer y-axis
  Serial8.print(",");
  // Serial8.print(faz);   //accelerometer z-axis
  // Serial8.print(",");   
  // SerSerial8al.print(GPS); //GPS
  Serial8.println("0");   //steering angle  
}