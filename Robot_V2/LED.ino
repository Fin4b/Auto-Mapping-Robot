#define BLUE 32
#define GREEN 33
#define RED 5

int currentR = 0;
int currentG = 0;
int currentB = 0;


void setupLED()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void setRGB(int r, int g, int b) {
    currentR = r;
    currentG = g;
    currentB = b;
    analogWrite(RED,   r);
    analogWrite(GREEN, g);
    analogWrite(BLUE,  b);
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