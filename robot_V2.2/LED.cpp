#include "LED.h"
#include <Arduino.h>

#define BLUE 25
#define RED 33
#define GREEN 32

bool blink = false;
unsigned long lastBlink = 0;
bool ledOn = false;

int currentR = 0;
int currentG = 0;
int currentB = 0;

void setupLED()
{
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    turnLedOff();
}

void setRGB(int r, int g, int b)
{
   currentR = r;
   currentG = g;
   currentB = b;
   analogWrite(RED, r);
   analogWrite(GREEN, g);
   analogWrite(BLUE, b);
   
}

void blinkLED() 
{
  blink = true;
  
}
 

void stopBlink()
{
  blink = false;
    turnLedOff();
    ledOn = false;
}
void updateLED()
{
 
    if (!blink)
        return;

    if (millis() - lastBlink >= 100)
    {
        lastBlink = millis();

        if (ledOn)
        {
            turnLedOff();
            ledOn = false;
        }
        else
        {
            setRGB(currentR, currentG, currentB);
            ledOn = true;
        }
    }
}

void turnLedPurple() { setRGB(210, 29, 145);  }
void turnLedGreen()  { setRGB(20, 245, 16);   }
void turnLedRed()    { setRGB(255, 0, 0);   }
void turnLedBlue()   { setRGB(5, 50, 255);  }
void turnLedYellow() { setRGB(255, 100, 0);  }
void turnLedWhite()  { setRGB(255, 130, 41);  }
void turnLedOrange() { setRGB(255, 40, 0);  }
void turnLedOff()   
 { 
   analogWrite(RED, 0);
   analogWrite(GREEN, 0);
   analogWrite(BLUE, 0);
 }