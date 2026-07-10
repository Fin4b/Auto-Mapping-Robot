#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>

#include "IMU.h"
#include "Motors.h"
MPU6050 mpu(Wire);
float yawOffset = 0.0;
const int turnSpeed = 150;

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
  return mpu.getAngleZ()- yawOffset + 90;
}

void turn (int x)
{

  updateIMU();
  if (x<90)
  {
    setSpeedLeft(turnSpeed);
    setSpeedRight(turnSpeed);
    while(abs(updateIMU()-x)>3)
    {
      turnLeft();
      delay(2);
    }
    stopMotors();
  }

  else if (x>90)
  {
      setSpeedLeft(turnSpeed);
      setSpeedRight(turnSpeed);

    while(abs(updateIMU()-x)>3)
    {
      turnRight();
      delay(2);
    }
    stopMotors();
  }

  else {moveForward();}
}

