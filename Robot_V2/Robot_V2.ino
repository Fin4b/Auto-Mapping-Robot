enum Mode { AUTO,MANUAL,NAVIGATE};
Mode currentMode = AUTO;
Mode lastMode = AUTO;

void setup() {

  setupServo();
  setupMotors();
  setupLED();
  setupIMU();
  setupEncoder();
  setupController();
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
    case AUTO:
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
