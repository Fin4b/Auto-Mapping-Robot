#include <MPU6050_light.h>
#include <Wire.h>

MPU6050 mpu(Wire);
float yawOffset = 0.0;

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
