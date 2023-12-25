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
  EEPROM.begin();
  Serial.begin(115200);//Serial monitor 
  Serial5.begin(9600);//HMI Display 
  Serial3.begin(230400);//xbee
  can_setup();
  accelero_setup();
  SD_LC_setup();
  LC_setup();
  RPM_LED_setup();
  // setup_SD(); This is called under datalogging function 
  sd_switch_pin_setup();
  setup_speed();
  millis();
 }

void loop() 
{
  //CAN
  if(millis() - can_last_time >= can_data_rate){
    can_get_data();
    can_show_data();
    can_last_time = millis();
  }
  
  //acceleromter 
  accelero_getdata();
    // accelero_show_data();  

  //gear
  gear_setup();
  gear_val(); 

  //speed
  SpeedCount(SPEED_UPDATE_FREQ);

  //Radiator_check
  check_rad();

  //RPM_LED
  showLightDis();

  //SD_datalogging 
  dataLogging();

  //xbee
  if((millis() -xbeeLastTime ) > xbeeTime){
    send_xbee();
    HMI_print(4,RPM);
    HMI_print(5,(int32_t)temp);
    HMI_print(10,volts); 
    HMI_print(6,(int32_t)Speed);
    xbeeLastTime = millis();  
  }

  //**No function end in flexcanT4 library**

  //hmi 
  // if(millis() -hmi_last_time >= hmiTime){
  //   can2.end();
  //   can2.begin(CAN_FREQ);
  // }

  if(canThisTime - canLastTime >= canCheckTime){ 
    hmiCANRed();
  }

  Serial.print(millis());
  Serial.print(",");
  Serial.print(RPM);            //RPM 
  Serial.print(",");    
  Serial.print(temp);           //temp
  Serial.print(",");    
  Serial.print(gear);           //gear
  Serial.print(",");    
  Serial.print(Speed);          //speed
  Serial.print(",");    
  Serial.print(volts);          //battery_voltage
  Serial.print(",");    
  Serial.print(datalog  );      //datalog_check
  Serial.print(",");    
  Serial.print(radCheck);       //radiator_check
  Serial.print(",");    
  Serial.print(fax);            //accelerometer x-axis
  Serial.print(",");    
  Serial.print(fay);            //accelerometer y-axis
  Serial.print(",");            
  Serial.print(faz);            //accelerometer z-axis
  Serial.print(",");    
  Serial.print(reading_FL);     //Front_left_LC
  Serial.print(",");    
  Serial.print(reading_FR);     //Front_right_LC
  Serial.print(",");    
  Serial.print(reading_RL);     //Rear_left_LC
  Serial.print(",");  
  Serial.println(reading_RR);   //Rear_right_LC
}