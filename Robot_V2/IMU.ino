


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
  if (x<90)
  {
    setSpeedLeft(turnSpeed);
    setSpeedRight(turnSpeed);
    while(abs(updateIMU()-x)>3)
    {
      turnLeft();
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
    }
    stopMotors();
  }

  else {moveForward();}
}

