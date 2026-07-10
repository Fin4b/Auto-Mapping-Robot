#include <Arduino.h>
#include <Bluepad32.h>

#include "ManualMode.h"
#include "Controller.h"
#include "Motors.h"
#include "Servo.h"

 int servoAngle = 90;
 int speed = 0;
 int angleIMU = 90;


 int applyDeadzone(int value, int deadzone) {
    if (abs(value) < deadzone) return 0;
    return value;
}

void manualLoop()
{
  if (!myController || !myController->isConnected())
        return;

      updateTankDrive();
      updateServo();
      updateDpad();

      delay(20);
}

void updateTankDrive()
{
  int leftStickY = applyDeadzone(myController->axisY(), 50);
  int rightStickY = applyDeadzone(myController->axisRY(),50);

  int leftSpeed = calculateSpeed(leftStickY);
  int rightSpeed = calculateSpeed(rightStickY);

  setMotorLeft(leftSpeed);
  setMotorRight(rightSpeed);
}

void setMotorLeft(int speed)
{
  setSpeedLeft(abs(speed));

  if(speed>0)
  {
    leftForwards();
  }
  else if(speed<0)
  {
    leftBackwards();
  }
}

void setMotorRight(int speed)
{
  setSpeedRight(abs(speed));

  if(speed>0)
  {
    rightForwards();
  }
  else if(speed<0)
  {
    rightBackwards();
  }
}

void updateServo()
{
  if(myController->R1() && servoAngle < 180)
  {
    servoAngle += 10;
    setServoAngle(servoAngle);
  }

  if(myController->L1() && servoAngle > 0)
  {
    servoAngle -= 10;
    setServoAngle(servoAngle);
  }
}

void updateDpad()
{
  uint8_t dpad = myController->dpad();

  if(dpad & DPAD_UP)
  {
    setSpeedLeft(200);
    setSpeedRight(200);
    moveForward();
  }


  else if(dpad & DPAD_DOWN)
    {
        setSpeedLeft(200);
        setSpeedRight(200);
        moveBackward();
    }

    else if(dpad & DPAD_LEFT)
    {
        angleIMU = max(angleIMU - 10,0);
        turn(angleIMU);
    }

    else if(dpad & DPAD_RIGHT)
    {
        angleIMU = min(angleIMU + 10,180);
        turn(angleIMU);
    }
}
  