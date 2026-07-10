#pragma once

void onConnectedController(ControllerPtr ctl);
void onDisconnectedController(ControllerPtr ctl);
void setupController();
void updateController();
int calculateSpeed(int stickY);
