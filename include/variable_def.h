#ifndef VARIABLE_H
#define VARIABLE_H

#include"HX711.h"
#include"MPU6050.h"
#include<SD.h>

// #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
//     #include "Wire.h"
// #endif

// ***CAN variables***

#define can_data_rate 400
int64_t can_last_time = 0;
#include <FlexCAN_T4.h>
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

#endif