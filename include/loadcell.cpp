#include<Arduino.h>
#include<variable_def.h>
#include "HX711.h" 
#include <SPI.h>
#include <SD.h>

void SD_LC_setup() {
  if (!SD.begin(254)) { //BUITLIN_SDCARD-254
    Serial.println("Card failed, or not present");
    while (1);
  }
  Serial.println("card initialized.");
}

void LC_setup(){
  LC_FR.begin(LC_DT_FR,LC_SCK_FR);
  LC_FL.begin(LC_DT_FL,LC_SCK_FL);
  LC_RL.begin(LC_DT_RL,LC_SCK_RL);
  LC_RR.begin(LC_DT_RR,LC_SCK_RR);
}

void LC_getdata() {
    reading_FL =LC_FL.get_value()/calibrationfactor_FL+LC_FL_offset1+LC_FL_offset2; //In  Kg
    reading_FR =LC_FR.get_value();
    reading_RR =LC_RR.get_value();
    reading_RL =LC_RL.get_value();
}

void SD_LC_write(){
    if(datafile){
        LC_time=millis();
        datafile.print(LC_time);
        datafile.print(",");
        datafile.print(reading_FR);
        datafile.print(",");
        datafile.print(reading_FL);
        datafile.print(",");
        datafile.print(reading_FR);
        datafile.print(",");
        datafile.println(reading_FL);
        datafile.close();
    }
}

void LC_showdata(){
    if(datafile){
        Serial.print(LC_time);
        Serial.print(",");
        Serial.print(reading_FR);
        Serial.print(",");
        Serial.print(reading_FL);
        Serial.print(",");
        Serial.print(reading_FR);
        Serial.print(",");
        Serial.println(reading_FL);
    }
    else{
        Serial.println("ERROR");
        return;
    }
}



