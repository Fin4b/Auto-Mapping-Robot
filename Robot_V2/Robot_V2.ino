#include "Encoders.h"
#include "IMU.h"
#include "Motors.h"
#include "LED.h"
#include "Controller.h"
#include "UltraSonic.h"
#include "ServoControl.h"
#include "AutoMode.h"
#include "ManualMode.h"
#include "NavigateMode.h"
#include "RobotData.h"


  void setup() {
  Serial.begin(115200);
  Serial.println("Booting...");
  setupServo();
  setupMotors();
  setUpUSS();
  setupLED();
  setupIMU();
  setupEncoder();
  setupController(); 
  Serial.println("Setup complete");
  
}


void loop() 
{
  
  
  updateController();
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
