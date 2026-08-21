#include "LED.h"
#include<Arduino.h>
#include "RobotData.h"

#define BLUE 32
#define GREEN 33
#define RED 5

#define RED_CH 0
#define GREEN_CH 1
#define BLUE_CH 2

int currentR = 0;
int currentG = 0;
int currentB = 0;


void setupLED()
{
  ledcSetup(RED_CH, 5000, 8);    // 5kHz, 8-bit resolution
  ledcSetup(GREEN_CH, 5000, 8);
  ledcSetup(BLUE_CH, 5000, 8);

  ledcAttachPin(RED, RED_CH);
  ledcAttachPin(GREEN, GREEN_CH);
  ledcAttachPin(BLUE, BLUE_CH);
}

void setRGB(int r, int g, int b) {
    currentR = r;
    currentG = g;
    currentB = b;
    ledcWrite(RED_CH, r);
    ledcWrite(GREEN_CH, g);
    ledcWrite(BLUE_CH, b);
}

void blinkLED() 
{
    turnLedOff();
    delay(100);
    setRGB(currentR, currentG, currentB);
    delay(100);
}

void setModeColour() 
{
 switch(currentMode)
 {
    case AUTO:
      turnLedGreen();
      break;

    case MANUAL:
      turnLedBlue();
      break;

    case NAVIGATE:
      turnLedYellow();
      break;

      default: turnLedGreen();

 }
}






void turnLedPurple() { setRGB(133, 29, 145);  }
void turnLedGreen()  { setRGB(20, 245, 16);   }
void turnLedRed()    { setRGB(255, 10, 10);   }
void turnLedBlue()   { setRGB(29, 173, 245);  }
void turnLedYellow() { setRGB(227, 159, 20);  }
void turnLedOff()   
 { 
    analogWrite(RED,0);
    analogWrite(GREEN,0);
    analogWrite(BLUE,0);
 }