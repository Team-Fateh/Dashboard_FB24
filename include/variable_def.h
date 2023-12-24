#ifndef VARIABLE_H
#define VARIABLE_H
#include <FlexCAN_T4.h>

#include <WS2812Serial.h>
#include"HX711.h"
#include"MPU6050.h"
#include<SD.h>

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

// ***CAN variables***

#define can_data_rate 400
int64_t can_last_time = 0;
FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> can2;
CAN_message_t msg;
int32_t packetSize;
int32_t packId;
#define RPM_PKT_ID 218099784
#define TEMPBATT_PKT_ID 218101064
int32_t rMSB=0,rLSB=0;
int32_t tMSB=0,tLSB=0;
int32_t vMSB=0,vLSB=0;
int32_t RPM;
float temp;
float volts;
int _rxLength;
int _rxIndex;
uint8_t _rxData[8];

//***Gear variables***

char gear;

//***Xbee***

unsigned long xbeeLastTime=0,xbeeTIme=50;

//***IMU_MPU6050***

#define OUTPUT_READABLE_ACCELGYRO
MPU6050 accelgyro;
int16_t ax, ay, az;
const int numReadings = 10;  
int readingsX[numReadings];
int readingsY[numReadings]; 
int readingsZ[numReadings]; 
int currentIndexX = 0;
int currentIndexY = 0;  
int currentIndexZ = 0;     
int totalX = 0;
int totalY = 0;
int totalZ = 0;
float averageX;
float averageY;
float averageZ;
float fax;
float fay;
float faz;

//**loadcell**

// HX711 circuit wiring

File datafile=SD.open("LC_Data.csv",FILE_WRITE);
// HX711 circuit wiring
#define LC_DT_FL 27
#define LC_SCK_FL 26
#define LC_DT_FR 25
#define LC_SCK_FR 24
#define LC_DT_RL 22
#define LC_SCK_RL 23
#define LC_DT_RR 37
#define LC_SCK_RR 32

HX711 LC_FR,LC_FL,LC_RR,LC_RL;

float reading_FR;
float reading_FL;
float reading_RR;
float reading_RL;

float LC_FR_offset1=0.69;
float LC_FR_offset2=0.55;
float LC_FL_offset1=0;
float LC_FL_offset2=0;
float LC_RR_offset1=0;
float LC_RR_offset2=0;
float LC_RL_offset1=0;
float LC_RL_offset2=0;

float calibrationfactor_FR=-21500;
float calibrationfactor_FL=0;
float calibrationfactor_RR=0;
float calibrationfactor_RL=0;

unsigned long LC_time;



//hmi
#define hmi_data_rate 200
long unsigned int hmi_last_time=0;

//rpm led
#define num_led 18
#define ledPin 29
#define rpm_data_rate 100
long unsigned int rpm_last_time=0;
byte drawingMemory[num_led*3];         //  3 bytes per LED
DMAMEM byte displayMemory[num_led*12]; // 12 bytes per LED

WS2812Serial leds(num_led, displayMemory, drawingMemory, ledPin, WS2812_GRB);
#define RED    0xFF0000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define WHITE  0x101010
int light=0;
int ledDur,ledOldDur,red;
char comm;

//speed
volatile unsigned int totalCounts;
    #define speedPin 34    //front right
    #define slits 28   //Front wheel
    int lastTime=0;      
    float Speed;      

//speed_rpm
#define fdr 3.118    //Final Drive Rtaio
    #define pgr 2.667    //Primary Gear Ratio
    #define gr1 2.67
    #define gr2 1.86
    #define gr3 1.42
    #define gr4 1.14
    #define gr5 0.96
    #define gr6 0.84
    #define td 49.022    //Tire dia of Housier 19.3 inches
    float SpeedRPM = 0.0;
    float wheelRPM = 0.0;





#endif
