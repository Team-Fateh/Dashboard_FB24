#include <variable_def.h>
#include<Arduino.h>


void HMI_print(int placeholder, int32_t value){
    Serial5.print("t");
    Serial5.print(placeholder);
    Serial5.print(".");
    Serial5.print("txt=");
    Serial5.print("\"");
    Serial5.print(value);
    Serial5.print("\"");
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.write(0xff);
}

 void HMI_print(int placeholder, float value){
     Serial5.print("t");
     Serial5.print(placeholder);
     Serial5.print(".");
     Serial5.print("txt=");
     Serial5.print("\"");
     Serial5.print(value);
     Serial5.print("\"");
     Serial5.write(0xff);
     Serial5.write(0xff);
     Serial5.write(0xff);
 }

void hmiCANRed(){
    Serial5.print("r1.pco=");       
    Serial5.print("63488");
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.print("r1.bco=");       
    Serial5.print("63488");
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.print("t1");           //63488 Red colour
    Serial5.print(".");
    Serial5.print("pco");
    Serial5.print("=");
    Serial5.print("63488");
    Serial5.write(0xff);
    Serial5.write(0xff);
}
void hmiCANGreen(){
    Serial5.print("r1.pco=");       
    Serial5.print("1024");
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.print("r1.bco=");       
    Serial5.print("1024");
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.print("t1");          //1024 Green colour
    Serial5.print(".");
    Serial5.print("pco");
    Serial5.print("=");
    Serial5.print("1024");
    Serial5.write(0xff);
    Serial5.write(0xff);
    Serial5.write(0xff);
}