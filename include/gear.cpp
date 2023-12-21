#include <Arduino.h>
#include <variable_def.h>

void gear_val()
{
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    pinMode(4,INPUT_PULLUP);
    pinMode(6,INPUT_PULLUP);
    pinMode(7,INPUT_PULLUP);
    pinMode(8,INPUT_PULLUP);

    if(digitalRead(2)==LOW) {gear='1';}
    else if(digitalRead(3)==LOW) {gear='2';}
    else if(digitalRead(4)==LOW) {gear='3';}
    else if(digitalRead(5)==LOW) {gear='4';}
    else if(digitalRead(6)==LOW) {gear='5';}
    else if(digitalRead(7)==LOW) {gear='6';}
    else if(digitalRead(8)==LOW) {gear='N';}
    else {gear='X';}
}






