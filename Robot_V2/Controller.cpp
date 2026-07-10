#include <Arduino.h>
#include<Bluepad32.h>

#include "RobotData.h"
#include "Controller.h"

ControllerPtr myController = nullptr;
void onConnectedController(ControllerPtr ctl) 
{
    myController = ctl;
}

void onDisconnectedController(ControllerPtr ctl)
{
    myController = nullptr;
}

void setupController() 
{
    BP32.setup(&onConnectedController, &onDisconnectedController);
}

void updateController() 
{
    BP32.update();
    if (myController && myController->isConnected()) 
    {
        if (myController->a()) currentMode = AUTO;  Serial.println("Auto mode");
        if (myController->x()) currentMode = MANUAL;  Serial.println("Manual mode");
        if (myController->y()) currentMode = NAVIGATE;  Serial.println("Navigate mode");
        if (myController->b()) stopMotors();  Serial.println("Emergency Stop");
        
        
    }
}

int calculateSpeed(int stickY)

{
  if(stickY == 0)
  {
    return 0;
  }

  int baseSpeed = map(abs(stickY),0,512,0,127);
  int throttle = map(myController->throttle(),0,1023,0,128);
  int brake = map(myController->brake(),0,1023,0,127);

  int speed = baseSpeed + throttle - brake;

  if(stickY > 0)
  {
    return -speed;
  }

  return speed;
}
