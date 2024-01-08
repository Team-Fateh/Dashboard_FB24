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
   for(int i =0; i<=num_led;i++){
   leds.setPixel(i,0);
   }
   // leds.show();

   ledDur=millis();
   if(ledDur-ledOldDur>=300) ledOldDur=millis();
   if (ledDur-ledOldDur<=150) red =RED;
   else red = 0;
   
   light=map(RPM, 0,11000, 0,num_led);
   
   if(RPM>=0&&RPM<=3500)
   {
      for (int i=0; i<=light; i++)
      {
         leds.setPixel(i,BLUE);
      }
         leds.show();
   }

   if(RPM>3500&&RPM<=7000)
   {
      for (int i=0; i<=5; i++)
      {
         leds.setPixel(i,BLUE);
      }
         leds.show();
      for (int i=6; i<=light; i++)
      {
         leds.setPixel(i,GREEN);
      }
         leds.show();
   }
   
      
   if(RPM>7000&&RPM<=9500)
   {
      for (int i=0; i<=5; i++)
      {  
         leds.setPixel(i,BLUE);
      }
         leds.show();
      for (int i=6; i<=10; i++)
      {  
         leds.setPixel(i,GREEN);
      }
         leds.show();
      for (int i=11; i<=light; i++)
      {  
         leds.setPixel(i,RED);
      }
         leds.show();
   }
   if(RPM>9500)
   {
      for (int i=0; i<=light; i++){
         leds.setPixel(i,red);
      } 
         leds.show(); 
   }  
}
      

