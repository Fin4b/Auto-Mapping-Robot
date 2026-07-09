
 
 int servoAngle = 90;
 int speed = 0;
 int angleIMU = 90;
 uint8_t dpad = myController->dpad();

 int applyDeadzone(int value, int deadzone) {
    if (abs(value) < deadzone) return 0;
    return value;
}

void manualLoop()
{
  bool rightBumper = false;
  bool leftBumper = false;
  

      int leftStickY = applyDeadzone(myController->axisY(), 50);
      int rightStickY = applyDeadzone(myController->axisRY(),50);
      int directionLeft =(leftStickY > 0) ? -1: 1;
      int directionRight = (rightStickY > 0) ? -1: 1;
      int baseSpeedLeft = map(abs(leftStickY), 0, 512, 0, 127);
      int baseSpeedRight = map(abs(rightStickY), 0, 512, 0, 127);
      int throttleLeft = (baseSpeedLeft > 0) ? map(myController->throttle(),0, 1023, 0 ,128) : 0;
      int throttleRight = (baseSpeedRight > 0) ? map(myController->throttle(),0, 1023, 0 ,128) : 0;
      int brakingLeft = (baseSpeedLeft > 0) ? map(myController->brake(),0,1023,0,127) : 0;
      int brakingRight = (baseSpeedRight > 0) ? map(myController->brake(),0,1023,0,127) : 0;
      int speedLeft = (baseSpeedLeft + throttleLeft - brakingLeft)* directionLeft;
      int speedRight = (baseSpeedRight + throttleRight - brakingRight)* directionRight;
      setSpeedLeft(speedLeft);
      setSpeedRight(speedRight);

      if (directionRight == 1) 
      {
        rightBackwards();
      }

      else if(directionRight == -1)
      {
        rightForwards();
      }

      else 
      {
        stopMotors();
      }


      if (directionLeft == 1) 
      {
        leftBackwards();
      }

      else if(directionLeft == -1)
      {
        leftForwards();
      }

      else 
      {
        stopMotors();
      }

 


  if (rightBumper == true && servoAngle<180)
  {
    servoAngle +=10;
    setServoAngle(servoAngle);
  }

  if (leftBumper == true && servoAngle>0)
  {
    servoAngle -=10;
    setServoAngle(servoAngle);
  }

  if (dpad & DPAD_UP)
{
    moveForward();
}
else if (dpad & DPAD_DOWN)
{
    moveBackward();
}
else if (dpad & DPAD_LEFT & angleIMU>0)
{
  angleIMU -= 10;
    turn(angleIMU);
}
else if (dpad & DPAD_RIGHT & angleIMU<180)
{
    angleIMU += 10;
    turn(angleIMU);
}
else
{
    stopMotors();
    
}

 







delay(100);

}