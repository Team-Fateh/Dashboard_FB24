#include <FlexCAN_T4.h>
#include <variable_def.h>
#include <WS2812Serial.h>

// Usable pins:
//   Teensy 4.1:  1, 8, 14, 17, 20, 24, 29, 35, 47, 53
void RPM_LED_setup()
{
 leds.begin();
}

void showLightDis(){                                //Discrete Blue to Green to Red
   ledDur=millis();
   if(ledDur-ledOldDur>=100) ledOldDur=millis();
   if (ledDur-ledOldDur<=50) red =RED;
   else red = WHITE;
   
   light=map(RPM, 0,11000, 0,19);
   
   if(RPM>=0&&RPM<=3500)
   {
      for (int i=0; i<=light; i++)
      {
         leds.setPixel(i,BLUE);
         leds.show();
      }
   }

   if(RPM>3500&&RPM<=7000)
   {
      for (int i=0; i<=6; i++)
      {
         leds.setPixel(i,BLUE);
         leds.show();
      }
      for (int i=7; i<=light; i++)
      {
         leds.setPixel(i,GREEN);
         leds.show();
      }//leds[i]=CRGB(0,255,0)
   }
   
      
   if(RPM>7000&&RPM<=9500)
   {
      for (int i=0; i<=6; i++)
      {  
         leds.setPixel(i,BLUE);
         leds.show();
      }
      for (int i=7; i<=12; i++)
      {  
         leds.setPixel(i,GREEN);
         leds.show();
      }
      for (int i=13; i<=light; i++)
      {  
         leds.setPixel(i,RED);
         leds.show();
      }
   }
   if(RPM>9500)
   {
      for (int i=0; i<=light; i++){
         leds.setPixel(i,red);
         leds.show(); 
      } 
   }  
   leds.show();
}
      

