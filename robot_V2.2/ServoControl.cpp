#include <Arduino.h>
#include "ESP32Servo.h"
#include "ServoControl.h"
#include "USS.h"
#include "LED.h"

int servoPin = 4;
Servo Servo1;
int angles[7] = {0,30,60,90,120,150,180};
unsigned long servoTimer = 0;
bool scanning = false;
int currentAngle = 0;
long measurements[7];

void setupServo()
{
  Servo1.attach(servoPin,500,2400);
  Servo1.write(90);
  delay(500);
}

void servoScan()
{
  if(!scanning)
  {
    turnLedYellow();
    blinkLED();
    scanning = true;
    currentAngle = 0;

    setServoAngle(angles[currentAngle]);
    servoTimer = millis();
  }
}

void setServoAngle(int x)
{
  if(x>=0 && x<=180)
  {
   Servo1.write(x);
  }
}

void updateServo()
{
  if (!scanning)
  {
    return;
  }

  if(millis()-servoTimer>=400)
  {
    measurements[currentAngle] = measure();
    currentAngle++;

    if (currentAngle>=7)
    {
      scanning = false;
      currentAngle = 0;

      stopBlink();
      turnLedGreen();
      setServoAngle(90);
      Serial.println("----- SCAN COMPLETE -----");
      delay(200);

    for (int i = 0; i < 7; i++)
    {
        Serial.print(angles[i]);
        Serial.print(" degrees: ");
        Serial.print(measurements[i]);
        Serial.println(" cm");
    }
      return;
    }

    setServoAngle(angles[currentAngle]);
    servoTimer = millis();

  }
  
}

int getAngles(int i)
{
  return angles[i];
}

long getMeasurements(int i)
{
  return measurements[i];
}