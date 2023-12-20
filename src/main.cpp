#include <Arduino.h>
#include<variable_def.h>
#include <can_tf.cpp>


void setup()
 {
    Serial.begin(9600);
    can_setup();
 }


void loop() {
  can_get_data();
}
