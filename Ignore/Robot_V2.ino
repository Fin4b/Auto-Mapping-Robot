enum Mode { AUTO,MANUAL,NAVIGATE};
Mode currentMode = AUTO;

void setup() {

  setupServo();
  setupMotors();
  setupLED();
  setupIMU();
  setupEncoder();
}


void loop() 
{


 if (currentMode != lastMode) 
 {
   setModeColour();
   lastMode = currentMode;
 }
 switch(currentMode)
 {
    case AUTO:c:\Users\finni\Documents\Arduino\Robot_V2\UltraSonic.ino
      turnLedGreen();
      autoLoop();
      break;

    case MANUAL:
      turnLedBlue();
      manualLoop();
      break;

    case NAVIGATE:
      turnLedPurple();
      navigateLoop();
      break;

      default: turnLedGreen();autoLoop();

 }

 
}
