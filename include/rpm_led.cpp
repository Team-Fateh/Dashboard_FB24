#include <variable_def.h>
#include <WS2812Serial.h>

// Usable pins:
//   Teensy 4.1:  1, 8, 14, 17, 20, 24, 29, 35, 47, 53
void LED_setup()
{
 leds.begin();
}

void showLightDis(){                                //Discrete Blue to Green to Red
   ledDur=millis();
   if(ledDur-ledOldDur>=100) 
   ledOldDur=millis();
   if (ledDur-ledOldDur<=50)
   red =255;
   else red =0;
   
   light=map(RPM, 0,11000, 0,19);
   
   if(RPM>=0&&RPM<=3500)
   {
      for (int i=0; i<=light; i++){
        void colorWipe(int color ) {
        for (int i=0; i < leds.numPixels(); i++) {
        leds.setPixel(i, color);
        leds.show();
         delayMicroseconds(0);
         //leds[i]=CRGB(0,0,255);
        }
        }
      }
   }
   if(RPM>3500&&RPM<=7000)
   {
      for (int i=0; i<=6; i++)
      {
        void colorWipe(int color, int wait) {
        for (int i=0; i < leds.numPixels(); i++) {
        leds.setPixel(i, color);
         leds.show();
    
         //leds[i]=CRGB(0,0,255);
      }
        }
      }
   }
      for (int i=7; i<=light; i++)
      {
        void colorWipe(int color) {
        for (int i=0; i < leds.numPixels(); i++) {
         leds.setPixel(i, color);
         leds.show();
        
         //leds[i]=CRGB(0,255,0);
      }
   }
      }
   if(RPM>7000&&RPM<=9500)
   {
      for (int i=0; i<=6; i++)
      { void colorWipe(int color, 0) {
      for (int i=0; i < leds.numPixels(); i++) {
     leds.setPixel(i, color);
     leds.show();}
      }
      }

     
         //leds[i]=CRGB(0,0,255);
      }
      for (int i=7; i<=12; i++)
      { void colorWipe(int color) {
       for (int i=0; i < leds.numPixels(); i++) {
       leds.setPixel(i, color);
      leds.show();
       }
       }
      
       }  //leds[i]=CRGB(0,255,0);}
      for (int i=13; i<=light; i++)
      { void colorWipe(int color) {
       for (int i=0; i < leds.numPixels(); i++) {
     leds.setPixel(i, color);
     leds.show();
       }
     
         //leds[i]=CRGB(255,0,0);
      }
   }
   if(RPM>9500){
      for (int i=0; i<=light; i++)
      {
        void colorWipe(int red) {
        for (int i=0; i < leds.numPixels(); i++) {
        leds.setPixel(i, red);
        leds.show();
        
         //leds[i]=CRGB(red,0,0);
      } 
   }  
      }
   }
   leds.show();
}
      

// void loop() {
//   // change all the LEDs in 1.5 seconds
  

//   colorWipe(RED, microsec);
//   colorWipe(GREEN, microsec);
//   colorWipe(BLUE, microsec);
  
// }

// void colorWipe(int color, int wait) {
//   for (int i=0; i < leds.numPixels(); i++) {
//     leds.setPixel(i, color);
//     leds.show();
//     delayMicroseconds(wait);
//   }
// }