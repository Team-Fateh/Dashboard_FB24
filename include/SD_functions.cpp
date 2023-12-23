#include<Arduino.h>
#include<SD.h>
#include<EEPROM.h>
//#include<FS.h>
#include <SPI.h>

Sd2Card card;
SdVolume volume;
SdFile root;
File myFile;
const int chipSelect = BUILTIN_SDCARD;
const int buildInLEDPin = 13;


const String fileName = "data.txt";
int i = 0;


/*
  Setup function is run first and initializes all the 
  - onboard LED
  - onboard SD
*/
void setup() {
  // Setup on board LED
  pinMode(buildInLEDPin, OUTPUT);

  
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect.
  }

//------------------SD-CARD------------------
  Serial.println("Initializing SD card...");

  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  //print the card info
  cardinfo();
//-------------------------------------------

  //removes the data if there is already one
  SD.remove("data.txt");
  

}
void loop() {

  // put your main code here, to run repeatedly:
  if( i < 5){
    saveData(i+1);
    blink();
    i++;
  }
  if ( i == 5) {
    readData();
    i++;
  }
}


/*
  this function writes the data to the file

  String data : data wich will be written to the file 
*/
void saveData(String data){
  //open the file
  myFile = SD.open("data.txt", FILE_WRITE);

  //if there was no problem opening the file => wirte to it
  if (myFile) {
    Serial.print("writing to");
    Serial.println(fileName);
    myFile.println(data);
    //colse the file
    myFile.close();
  } else {
    //if the file couldn't be opend => print error message
    Serial.print("error oppening the file :");
    Serial.println(fileName); 
  }
}

/*
  reads all the data from the file
*/
void readData(){
  //open the file
  myFile = SD.open("data.txt", FILE_READ);

  if(myFile){
     //read the context of the file starting from the top
    while(myFile.available()){
    Serial.write(myFile.read());
    }
    //after reading the complete file, close the file
    myFile.close();
  } else {
    //if the file couldn't be opend => print error message
    Serial.print("error oppening the file :");
    Serial.println(fileName); 
  }

}


void appendFile(){
    myFile=SD.open("data.txt", FILE_APPEND);
    if(!file){
        return;

    }
    if(file.print(message)){
        Serial.println("Data logged to SD card.");
    }
    else {
        Serial.println("Append failed");

    }
    file.close();
    }
}

*/
// void blink() {
//   digitalWrite(buildInLEDPin, HIGH);   // turn the LED on by making the voltage HIGH
//   delay(100);               
//   digitalWrite(buildInLEDPin, LOW);    // turn the LED off by making the voltage LOW
//   delay(100);

}

/*
  Prints the card info of the sd card
*/
// void cardinfo(){
//   // print the type of card
//   Serial.print("\nCard type: ");
//   switch(card.type()) {
//     case SD_CARD_TYPE_SD1:
//       Serial.println("SD1");
//       break;
//     case SD_CARD_TYPE_SD2:
//       Serial.println("SD2");
//       break;
//     case SD_CARD_TYPE_SDHC:
//       Serial.println("SDHC");
//       break;
//     default:
//       Serial.println("Unknown");
//   }

    // print the type and size of the first FAT-type volume
//   uint32_t volumesize;
//   Serial.print("\nVolume type is FAT");
//   Serial.println(volume.fatType(), DEC);
//   Serial.println();
  
//   volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
//   volumesize *= volume.clusterCount();       // we'll have a lot of clusters
//   if (volumesize < 8388608ul) {
//     Serial.print("Volume size (bytes): ");
//     Serial.println(volumesize * 512);        // SD card blocks are always 512 bytes
//   }
//   Serial.print("Volume size (Kbytes): ");
//   volumesize /= 2;
//   Serial.println(volumesize);
//   Serial.print("Volume size (Mbytes): ");
//   volumesize /= 1024;
//   Serial.println(volumesize);

  
//   Serial.println("\nFiles found on the card (name, date and size in bytes): ");
//   root.openRoot(volume);
  
//   // list all files in the card with date and size
//   root.ls(LS_R | LS_DATE | LS_SIZE);

// }

void startLog()
{
    datalog= 1;
    filecreate=1;
}
void setup_SD(){
    datalog=1;
    filecreate=1;
}
void setup_SD(){
    pinMode(sp,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(sp),startLog,FALLING);
}
void dataLogging(){
    if (datalog == 1){
        if (filecreate == 1){
            a=EEPROM.read(i);
            tempo = (int)a;
            tempo++;
            t = (String)tempo;
            const char* n = t.c_str();
            f= b+n+c;
            file_name = f.c_str() ;
            EEPROM.write(i,tempo);
            EEPROM.commit();
            SPI.end();
            spi->begin(SPI_SCLK, SPI_MISO, SPI_MOSI, SPI_SS);  
            if(!SD.begin(HSPI_SS,*spi)){
                Serial.println("Card Mount Failed");
                return;
            }
            uint8_t cardType = SD.cardType();
            if(cardType == CARD_NONE){
                Serial.println("No SD card attached");
                return;
            }   
            writeFile(SD, file_name, "Time,RPM,Temperature,Gear,SpeedRPM,Brake Pressure,Battery Voltage,Data Logging,Accelerometer X,Accelerometer Y\n");
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
        String brake_SD = (String)brake;
        String accelx_SD = (String)g_x;
        String accely_SD = (String)g_y;
        String comma = "," ;
        String end = "\n";
        int m = millis();
        String mystr = m+comma+RPM_SD+comma+temp_SD+comma+gear_SD
                        +comma+comma+speedRPM_SD+comma+brake_SD+comma+battery_SD
                        +comma+data_SD+comma+accelx_SD+comma+accely_SD+end;
        const char * input = mystr.c_str();
        appendFile(SD, file_name, input);
        if(digitalRead(sp)==0){
        }
        else{
            datalog=0;
        }
    }
}