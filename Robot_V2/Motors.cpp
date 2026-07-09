#include <Arduino.h>
#include "Motors.h"

const int PWM_FREQ = 1000; 
const int PWM_RES = 8; 

const int enableA = 25;
const int enableB = 26;

const int in1 = 13;   // Motor 1 — 10=forward, 01=reverse
const int in2 = 27;

const int in3 = 12;   // Motor 2 — 10=forward, 01=reverse
const int in4 = 14;

void setupMotors()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  ledcSetup(0, PWM_FREQ, PWM_RES);
  ledcSetup(1, PWM_FREQ, PWM_RES);
  ledcAttachPin(enableA, 0);
  ledcAttachPin(enableB, 1);

  ledcWrite(0, 0);
  ledcWrite(1, 0);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void motorsOn()
{
   ledcWrite(0, 255);
   ledcWrite(1, 255);
}

void motorsOff()
{
   ledcWrite(0, 0);
   ledcWrite(1, 0);
}

void leftBackwards()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void rightBackwards()
{
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void leftForwards()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void rightForwards()
{
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveBackward() 
{
  Serial.println("Backward");
  leftBackwards();
  rightBackwards();
}

void moveForward() 
{
  Serial.println("Forward");
  leftForwards();
  rightForwards();
}

void setSpeedLeft(int x)
{
  ledcWrite(0,constrain(x,0,255));
}

void setSpeedRight(int x)
{
  ledcWrite(1, constrain(x,0,255));
}

void stopMotors() 
{
  Serial.println("Stopping");
 /* digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  */
}

void turnLeft() 
{
  leftBackwards();
  rightForwards();
}

void turnRight() 
{
  leftForwards();
  rightBackwards();
}
