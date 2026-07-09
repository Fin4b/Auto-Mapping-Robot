//#include "Encoders.h"
#include <Bluepad32.h>
#include <Wire.h>
#include <MPU6050_light.h>
#include <ESP32Servo.h>
#include "Motors.h"
#include "SR04.h"
ControllerPtr myController = nullptr;
MPU6050 mpu(Wire);
#define TRIG_PIN 17
#define ECHO_PIN 16
Servo Servo1;

SR04 distance = SR04(ECHO_PIN, TRIG_PIN);


enum Mode { AUTO,MANUAL,NAVIGATE};
Mode currentMode = AUTO;
Mode lastMode = AUTO;

struct RobotData
{
  float yaw;
  long encRight;
  long encLeft;
  long scanning_Dis[7];
};

RobotData robotData;

  void setup() {
     Serial.begin(115200);
    delay(2000);
    Serial.println("Booting...");
 /* Serial.begin(115200);
  Serial.println("Booting...");
  setupServo();
  setupMotors();
  setupLED();
  setupIMU();
  setupEncoder();
  setupController(); 
  Serial.println("Setup complete");
  */
}


void loop() 
{
  
  /*
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
 

 */
}
