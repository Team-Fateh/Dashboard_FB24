#include "I2Cdev.h"
#include "MPU6050.h"
#include<variable_def.h>

void accelero_setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE //???
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    // initialize device
    accelgyro.initialize();

    // verify connection
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}


void accelero_getdata(){
  accelgyro.getAcceleration(&Ax, &Ay, &Az);
  ax=Ax+ox;
  ay=Ay+oy;
  az=Az+oz;
  /**  ROLLING AVERAGE TECHNIQUE
       Smooth out the noisy fluctuations by considering the average of the some past readings instead of relying solely on the current reading   .
**/

  totalX = totalX - readingsX[currentIndexX];   // Subtract the oldest reading
  readingsX[currentIndexX] = ax;               // Store the new reading
  totalX = totalX + readingsX[currentIndexX]; // Add the new reading

  totalY = totalY - readingsY[currentIndexY]; 
  readingsY[currentIndexY] = ay;       
  totalY = totalY + readingsY[currentIndexY];

  totalZ= totalZ - readingsZ[currentIndexZ];  
  readingsZ[currentIndexZ] = az;     
  totalZ = totalZ + readingsZ[currentIndexZ];

  currentIndexX++;
  if (currentIndexX >= numReadings) {
    currentIndexX = 0;
  }
currentIndexY++;
  if (currentIndexY >= numReadings) {
    currentIndexY = 0;
  }
  currentIndexZ++;
  if (currentIndexZ >= numReadings) {
    currentIndexZ = 0;
  }

  // Calculate the moving average

  averageX = totalX / numReadings;
  averageY = totalY / numReadings;
  averageZ = totalZ / numReadings;
  fax= (averageX/16384);
  fay= (averageY/16384);
  faz= (averageZ/16384);
}

void accelero_show_data(){
  Serial.print(ax);
  Serial.print(",");
  Serial.print(ay);
  Serial.print(",");
  Serial.println(az);
  delay(500);
}
