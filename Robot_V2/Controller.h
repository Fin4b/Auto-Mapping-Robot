#pragma once
#include <Bluepad32.h>

extern ControllerPtr myController;
void onConnectedController(ControllerPtr ctl);
void onDisconnectedController(ControllerPtr ctl);
void setupController();
void updateController();
int calculateSpeed(int stickY);
