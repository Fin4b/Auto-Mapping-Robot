#include "Encoders.h"
#include <Bluepad32.h>
#include <Wire.h>
#include <MPU6050_light.h>
#include <ESP32Servo.h>
#include "Motors.h"

  void setup() {
     Serial.begin(115200);
    delay(2000);
    Serial.println("Booting...");
  Serial.begin(115200);
  Serial.println("Booting...");
  setupServo();
  setupMotors();
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
