#pragma once

enum Mode { AUTO,MANUAL,NAVIGATE};
extern Mode currentMode;
extern Mode lastMode;

struct RobotData {
  float yaw;
  long encRight;
  long encLeft;
  long scanning_Dis[7];
};
extern RobotData robotData;