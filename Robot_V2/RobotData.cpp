#include <Arduino.h>
#include "RobotData.h"
#include "Encoders.h"
#include "IMU.h"


Mode currentMode = AUTO;
Mode lastMode = AUTO;
RobotData robotData;