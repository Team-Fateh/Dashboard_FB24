#include <Arduino.h>
#include <variable_def.h>

void gear_setup()
{
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    pinMode(4,INPUT_PULLUP);
    pinMode(6,INPUT_PULLUP);
    pinMode(7,INPUT_PULLUP);
    pinMode(8,INPUT_PULLUP);
}

void gear_val()
{
    if(digitalRead(2)==LOW) {
        Serial5.print("t");
        Serial5.print("1");
        Serial5.print(".");
        Serial5.print("txt=");
        Serial5.print("\"");
        Serial5.print("1");
        Serial5.print("\"");
        Serial5.write(0xff);
        Serial5.write(0xff);
        Serial5.write(0xff);
        gear='N';
    }
    else if(digitalRead(3)==LOW) {
        Serial5.print("t");
        Serial5.print("1");
        Serial5.print(".");
        Serial5.print("txt=");
        Serial5.print("\"");
        Serial5.print("2");
        Serial5.print("\"");
        Serial5.write(0xff);
        Serial5.write(0xff);
        Serial5.write(0xff);
        gear='2';
    }
    else if(digitalRead(4)==LOW) {
        Serial5.print("t");
        Serial5.print("1");
        Serial5.print(".");
        Serial5.print("txt=");
        Serial5.print("\"");
        Serial5.print("3");
        Serial5.print("\"");
        Serial5.write(0xff);
        Serial5.write(0xff);
        Serial5.write(0xff);
        gear='3';
    }
    else if(digitalRead(5)==LOW) {
        Serial5.print("t");
        Serial5.print("1");
        Serial5.print(".");
        Serial5.print("txt=");
        Serial5.print("\"");
        Serial5.print("4");
        Serial5.print("\"");
        Serial5.write(0xff);
        Serial5.write(0xff);
        Serial5.write(0xff);
        gear='4';   
    }
    else if(digitalRead(6)==LOW) {
        Serial5.print("t");
        Serial5.print("1");
        Serial5.print(".");
        Serial5.print("txt=");
        Serial5.print("\"");
        Serial5.print("5");
        Serial5.print("\"");
        Serial5.write(0xff);
        Serial5.write(0xff);
        Serial5.write(0xff);
        gear='5';    
    }
    else if(digitalRead(7)==LOW) {
        Serial5.print("t");
        Serial5.print("1");
        Serial5.print(".");
        Serial5.print("txt=");
        Serial5.print("\"");
        Serial5.print("6");
        Serial5.print("\"");
        Serial5.write(0xff);
        Serial5.write(0xff);
        Serial5.write(0xff);
        gear='6';
    }
    else if(digitalRead(8)==LOW) {
        Serial5.print("t");
        Serial5.print("1");
        Serial5.print(".");
        Serial5.print("txt=");
        Serial5.print("\"");
        Serial5.print("N");
        Serial5.print("\"");
        Serial5.write(0xff);
        Serial5.write(0xff);
        Serial5.write(0xff);
        gear='N';
    }
    else {gear='X';}
}






