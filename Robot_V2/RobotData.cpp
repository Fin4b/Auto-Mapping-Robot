#include "RobotData.h"


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