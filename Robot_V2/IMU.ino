#include <MPU6050_light.h>
#include <Wire.h>

MPU6050 mpu(Wire);

void setupIMU()
{
  Wire.begin();
  delay(500);
  mpu.begin();
  mpu.calcOffsets();
}

float updateIMU()
{
  mpu.update();
  return mpu.getAngleZ();
}
