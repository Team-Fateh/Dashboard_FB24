#include <FlexCAN_T4.h>
#include <variable_def.h>
#include<hmi.cpp>

int available(){
  return (_rxLength - _rxIndex);
}

int Cread(){
  if (!available()) {
    return -1;
  }

  return _rxData[_rxIndex++];
}

void can_setup(){
  can2.begin();
  can2.setBaudRate(1000000);
}

void can_get_data(){
  if(can2.read(msg)){
    hmiCANGreen();
    canLastTime=canThisTime;
    canThisTime=millis();
    for ( uint8_t i = 0; i < 8; i++ ) {
      _rxData[i]=msg.buf[i];
    }
    _rxLength=msg.len;
    packId=msg.id;
  }
  if(packId==RPM_PKT_ID){                                        //RPM_PKT_ID 218099784
      int d=0;
      _rxIndex=0;
      while (available()){
        if (d==0){                            //0th and 1st Byte are RPM data
                d++;
                rLSB=(int)Cread();
            }
        if (d==1){
                d++;
                rMSB=(int)Cread();
            }
       Cread(),d++;
      }
      RPM=((rMSB*255)+rLSB);  
    }  
  if(packId==TEMPBATT_PKT_ID){                                       
      int e=0;
      _rxIndex=0;
      while (available()){
        
        if (e==0){                            //0th and 1st Byte are RPM data
                e++;
                vLSB=(int)Cread();
            }
        if (e==1){
                e++;
                vMSB=(int)Cread();
            }
        if (e==4){                            
                e++;
                tLSB= (int)Cread();
            }
        if (e==5){
                e++;
                tMSB=(int)Cread();
            }
        Cread(),e++;
      }
      temp =((tMSB*256)+tLSB)*0.1;
      volts =((vMSB*256)+vLSB)*0.01;   
      }
}

void can_show_data()
{
Serial.print("RPM =>");
Serial.println(RPM);
Serial.print("Temp =>");
Serial.println(temp);
Serial.print("voltage =>");
Serial.println(volts);
}
