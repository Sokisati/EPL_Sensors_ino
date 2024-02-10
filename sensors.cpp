#include "sensors.h"

void GyroModule::updateValues()
{
  mpu.getMotion6(&x, &y, &z, &gx, &gy, &gz);

  //values are (for some reason) is between -17000 and 17000, we need them to be between 0 and 360 
  x = map(x, -17000, 17000, 0, 360); 
  y = map(y, -17000, 17000, 0, 360); 
  z = map(z, -17000, 17000, 0, 360); 
}

void GyroModule::printValues()
{
  
  Serial.print("Axis X = ");
  Serial.print(x);
  Serial.print("  ");
  Serial.print("Axis Y = ");
  Serial.print(y);
  Serial.print("  ");
  Serial.print("Axis Z  = ");
  Serial.println(z);
}

void GpsModule::updateValues()
{
  numberOfSat = gps.satellites.value();
  latitude = gps.location.lat();
  longitute = gps.location.lng();
  hdop = gps.hdop.hdop();
  sprintf(date, "%02d/%02d/%02d ", gps.date.month(), gps.date.day(), gps.date.year());
  sprintf(time, "%02d:%02d:%02d ", gps.time.hour(), gps.time.minute(), gps.time.second());
}

GpsModule::GpsModule() : ss(RXPin, TXPin)
{
  ss.begin(GpsModule::GPSBaud);
}

void GpsModule::smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

