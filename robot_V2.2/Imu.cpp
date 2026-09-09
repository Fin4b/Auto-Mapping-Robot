#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>
#include "Motors.h"
#include "IMU.h"
MPU6050 mpu(Wire);
float yawOffset = 0.0;
const int turnSpeed = 150;
float heading = 90;

void setupIMU()
{
  Wire.begin();
  delay(500);
  mpu.begin();
  mpu.calcOffsets();
  mpu.update();
  yawOffset = mpu.getAngleZ();
}

float updateIMU()
{
  mpu.update();
  heading =  mpu.getAngleZ()- yawOffset + 90;
  return heading;
}

void turn (int target)
{
  float heading = updateIMU();
  while (abs(target - heading) > 0.5)
  {
      if(target < heading)
      {
        turnLeft();
        delay(100);
      }

      else
      {
        turnRight();
        delay(100);
      }
      updateIMU();

  }
    
}

