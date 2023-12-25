
#include<Arduino.h>
#include<SD.h>
#include<EEPROM.h>
#include <SPI.h>
#include<variable_def.h>

void setup_SD(){
  if (!SD.begin(chipSelect)) { 
    Serial.println("Card failed, or not present");
    while (1);
  }    
}

void startLog()
{
  datalog= 1;
  filecreate=1;
}

void sd_switch_pin_setup(){
  pinMode(sd_pin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sd_pin),startLog,FALLING);
}

void writeData(const char * path,String data){
  Serial.printf("Writing to file: %s\n",path);
  myFile = SD.open(path, FILE_WRITE);
  if(!myFile){
    Serial.println("Failed to open file");
    return;
  }
  if (myFile.println(data)) {
    Serial.print("Data logged to SD card");
  }
  else Serial.println("Data logging failed");
  myFile.close();
}

/*
  reads all the data from the file
*/
void readData(const char * path){
  Serial.printf("Reading file: %s\n",path);
  myFile = SD.open(path, FILE_READ);
  if(myFile){
    while(myFile.available()){
      Serial.println(myFile.read());
    }
    myFile.close();
  }
  else{
    Serial.print("error oppening the file :");
  }
}

void appendFile(const char *path,String data){
    myFile=SD.open(path, FILE_WRITE_BEGIN); //**DOUBT**
    if(!myFile){
      Serial.println("Error in opening the file");
      return;
    }
    if(myFile.print(data)){ //doubt
        Serial.println("Data logged to SD card.");
    }
    else {
        Serial.println("Append failed");
    }
    myFile.close();
}

void dataLogging(){
  setup_SD();
  if (datalog == 1){
    if (filecreate == 1){
        EEPROM_val=EEPROM.read(i);
        tempo = (int)EEPROM_val;
        tempo++;
        eeprom_val = (String)tempo;
        const char* file_no = eeprom_val.c_str();
        f= name+file_no+ext;
        file_name = f.c_str() ;
        EEPROM.write(i,tempo);
        //The Teensy EEPROM library handles the commit internally.
        myFile=SD.open(file_name,FILE_WRITE);
        myFile.write("Time,RPM,Temperature,Gear,SpeedRPM,Brake Pressure,Battery Voltage,Data Logging,Accelerometer X,Accelerometer\n");
        myFile.close();
        filecreate = 0;
    }
    String temp_SD = (String)temp ;
    String RPM_SD = (String)RPM ;
    String gear_SD = (String)gear;
    String speed_SD = (String)Speed;
    String speedRPM_SD = (String)SpeedRPM;
    String battery_SD = (String)volts;
    // String rad_SD = (String)radCheck;
    String data_SD = (String)datalog;
    // String brake_SD = (String)brake;
    String accelx_SD = (String)fax;
    String accely_SD = (String)fay;
    String comma = "," ;
    String end = "\n";
    int m = millis();
    String mystr = m+comma+RPM_SD+comma+temp_SD+comma+gear_SD
                    +comma+comma+speedRPM_SD+comma+battery_SD
                    +comma+data_SD+comma+accelx_SD+comma+accely_SD+end; //+brake_SD
    appendFile(file_name, mystr);
    if(digitalRead(sd_pin)==0){
      datalog=0;
    }
  }
}

