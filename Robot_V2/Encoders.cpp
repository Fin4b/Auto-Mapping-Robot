#include <Arduino.h>
#include "Encoders.h"

volatile long countLeft = 0;
volatile long countRight = 0;

void setupEncoder()
{
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);

attachInterrupt(digitalPinToInterrupt(18),addLeft,CHANGE);
attachInterrupt(digitalPinToInterrupt(19),addRight,CHANGE);
}
void IRAM_ATTR addLeft()
{
  countLeft ++;
}
void IRAM_ATTR addRight()
{
  countRight ++;
}