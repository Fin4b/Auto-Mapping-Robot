#include <ESP32Servo.h>
#include <Arduino.h>

#include "Servo.h"
#include "IMU.h"
#include "LED.h"
#include "Ultrasonic.h"
#include "RobotData.h"

int servoPin = 4;
Servo Servo1;

void setupServo()
{
  Servo1.attach(servoPin,500,2400);
  Servo1.write(90);
  delay(500);
}

void servoScan()
{
  int angles[7] = {0,30,60,90,120,150,180};

  for(int i=0;i<7;i++)
  {
    Servo1.write(90);
    blinkLED();
    delay(400);

    robotData.scanning_Dis[i] = measure();
  }

  

  Servo1.write(90);
  blinkLED();
  delay(400);

  
  int bestAngle = direction(robotData.scanning_Dis);
  turn(bestAngle);

}

int direction(long dis[])
{
    int angles[7] = {0,30,60,90,120,150,180};

    long bestDir = dis[0];
    int bestAngle = angles[0];

    for (int i = 1; i < 7; i++)
    {
        if (dis[i] > bestDir)
        {
            bestDir = dis[i];
            bestAngle = angles[i];
        }
    }

    return bestAngle;
}

void setServoAngle(int x)
{
  Servo1.write(x);
}
