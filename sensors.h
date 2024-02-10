#ifndef EPL_SENSORS_H
#define EPL_SENSORS_H

#include "Arduino.h"
#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h"
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

//mpu6050
struct GyroModule
{
  MPU6050 mpu;
  int x, y, z;
  int gx, gy, gz;
  
  void updateValues();
  void printValues();
};

struct GpsModule
{
  double latitude, longitute;
  unsigned int numberOfSat;
  double hdop;
  char date[16];
  char time[16];


  // Static members need to be scoped properly
  static const int RXPin = 4;
  static const int TXPin = 3;
  static const uint32_t GPSBaud = 9600;
  
  TinyGPSPlus gps;
  SoftwareSerial ss;

  GpsModule();
  void updateValues();
  void smartDelay(unsigned long ms);
};

#endif
