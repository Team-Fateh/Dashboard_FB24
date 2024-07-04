//framework
#include<Arduino.h>
//functions
#include<can_tf.cpp>
#include<accelerometer.cpp>
#include<gear.cpp>
#include<loadcell.cpp>
#include<rpm_led.cpp>
#include<SD_functions.cpp>
#include<speed_rpm.cpp>
#include<speed.cpp>
#include<xbee.cpp>
#include<Radiator_check.cpp>
#include<variable_def.h>

void setup()
{
  //EEPROM.begin();
  Serial.begin(115200);//Serial monitor 
  Serial5.begin(9600);//HMI Display 
  Serial8.begin(230400);//xbee
  gear_setup();
  can_setup();
  RPM_LED_setup();
  accelero_setup();
  setup_SD(); 
  setup_speed();
  LC_setup();
  // SD_LC_setup();
 }

void loop()
{
  if(millis()-LC_Last_Time>=LC_time){
   LC_getdata();
  //  LC_showdata();
   LC_Last_Time=millis();
 }

 if(millis() - can_last_time >= can_data_rate){
   can_get_data();
   showLightDis();
   can_last_time = millis();
 }

 SpeedCount(400);
   if(millis() -hmi_last_time >= hmiTime){
   
   //**gear_2016**
  //  gear_val();
  //  Serial.println(gear);

  //  **gear_2018**
  //  dur= pulseIn(gearPin,HIGH);
  //  gear2018();
  //  Serial.println(dur);

   HMI_print(4,RPM);
   HMI_print(5,(int32_t)temp);
   HMI_print(10,volts); 
   HMI_print(6,(int32_t)Speed);
   hmi_last_time = millis();
 }

if(millis() -xbeeLastTime >= xbeeTime){
   brakeread = digitalRead(brakepin);
   brakepress =  25*brakeread;
   send_xbee();
   dataLogging();
// accelero_getdata();
// accelero_show_data();

   xbeeLastTime = millis();
 }
}
//
//