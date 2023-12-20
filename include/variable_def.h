#ifndef VARIABLE_H
#define VARIABLE_H

//CAN variables
#include <FlexCAN_T4.h>
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;
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

#endif