/*
#include <TinyGPS++.h>
#include <TinyGPSPlus.h>
#include <MPU6050.h>
*/
#include "sensors.h"

//gyro module
GyroModule gyroModule;

//gps module
GpsModule gpsModule;



void setup() 
{
  Serial.begin(9600);
  Serial.println("wow");
  //For I2C comm.
  Wire.begin();
  gyroModule.mpu.initialize();


}

void loop()
{
  gpsModule.updateValues();
  Serial.println(gpsModule.date);
  gpsModule.smartDelay(100);
 

}
