#include "AutoMode.h"
#include <Arduino.h>
#include "Motors.h"
#include "LED.h"
#include "ServoControl.h"
#include "UltraSonic.h"

const long minDistance = 10;

void autoLoop()
{
   motorsOn();
  long dis = getDistance();
  if(dis > 0 && dis < minDistance)
  {
    turnLedRed();
    stopMotors();
    delay(100);
    moveBackward();
    delay(500);
    stopMotors();
    turnLedPurple();
    servoScan();
    setModeColour();
  }
  else
  {
    moveForward();
  }
}