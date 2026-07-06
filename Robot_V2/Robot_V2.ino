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
  robotData.yaw = updateIMU();
  robotData.encRight = countRight;
  robotData.encLeft = countLeft;

 if (currentMode != lastMode) 
 {
   setModeColour();
   lastMode = currentMode;
 }
 switch(currentMode)
 {
    case AUTO:
      autoLoop();
      break;

    case MANUAL:
      manualLoop();
      break;

    case NAVIGATE:
      navigateLoop();
      break;

      default: autoLoop();

 }

 
}
