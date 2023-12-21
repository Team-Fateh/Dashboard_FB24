#include <Arduino.h>
#include <can_tf.cpp>
#include <variable_def.h>

void setup()
 {
    Serial.begin(9600);
    can_setup();
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
    
}