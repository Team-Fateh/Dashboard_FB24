#include <Arduino.h>
#include <variable_def.h>

//GEAR 2016

void gear_setup()
{
    // pinMode(g_pin1,INPUT_PULLUP); gear_2016
    // pinMode(g_pin2,INPUT_PULLUP);
    // pinMode(g_pin3,INPUT_PULLUP);
    // pinMode(g_pin4,INPUT_PULLUP);
    // pinMode(g_pin5,INPUT_PULLUP);
    // pinMode(g_pin6,INPUT_PULLUP);
    // pinMode(g_pinN,INPUT_PULLUP);
    pinMode(gearPin,INPUT);//gear_2018
}

// void gear_val()
// {
//     if(digitalRead(g_pin1)==LOW) {
//         Serial5.print("t");
//         Serial5.print("1");
//         Serial5.print(".");
//         Serial5.print("txt=");
//         Serial5.print("\"");
//         Serial5.print("1");
//         Serial5.print("\"");
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         gear='N';
//     }
//     else if(digitalRead(g_pin2)==LOW) {
//         Serial5.print("t");
//         Serial5.print("1");
//         Serial5.print(".");
//         Serial5.print("txt=");
//         Serial5.print("\"");
//         Serial5.print("2");
//         Serial5.print("\"");
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         gear='2';
//     }
//     else if(digitalRead(g_pin3)==LOW) {
//         Serial5.print("t");
//         Serial5.print("1");
//         Serial5.print(".");
//         Serial5.print("txt=");
//         Serial5.print("\"");
//         Serial5.print("3");
//         Serial5.print("\"");
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         gear='3';
//     }
//     else if(digitalRead(g_pin4)==LOW) {
//         Serial5.print("t");
//         Serial5.print("1");
//         Serial5.print(".");
//         Serial5.print("txt=");
//         Serial5.print("\"");
//         Serial5.print("4");
//         Serial5.print("\"");
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         gear='4';   
//     }
//     else if(digitalRead(g_pin5)==LOW) {
//         Serial5.print("t");
//         Serial5.print("1");
//         Serial5.print(".");
//         Serial5.print("txt=");
//         Serial5.print("\"");
//         Serial5.print("5");
//         Serial5.print("\"");
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         gear='5';    
//     }
//     else if(digitalRead(g_pin6)==LOW) {
//         Serial5.print("t");
//         Serial5.print("1");
//         Serial5.print(".");
//         Serial5.print("txt=");
//         Serial5.print("\"");
//         Serial5.print("6");
//         Serial5.print("\"");
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         gear='6';
//     }
//     else if(digitalRead(g_pinN)==LOW) {
//         Serial5.print("t");
//         Serial5.print("1");
//         Serial5.print(".");
//         Serial5.print("txt=");
//         Serial5.print("\"");
//         Serial5.print("N");
//         Serial5.print("\"");
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         Serial5.write(0xff);
//         gear='N';
//     }
//     else {gear='X';}
// }


//GEAR 2018

void gear2018(){
    if(dur>=700&&dur<=900)
    {
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
        gear ='1';
    }

    if(dur>=920&&dur<=1210)
    {
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
        gear ='N';
    }

    if(dur>=1220&&dur<=1500)
    {
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
        gear ='2';
    }

    if(dur>=1520&&dur<=2000)
    {
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
        gear ='3';
    }


    if(dur>=2020&&dur<=2500)
    {
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
        gear ='4';
    }

    if(dur>=2520&&dur<=3000)
    {
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
        gear ='5';
    }
    
    if(dur>=3020&&dur<=3500)
    {
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
        gear ='6';
    }
} 






