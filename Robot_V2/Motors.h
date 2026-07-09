#ifndef MOTORS_H
#define MOTORS_H

void setupMotors();
void motorsOn();
void motorsOff();
void leftBackwards();
void leftForwards();
void rightBackwards();
void rightForwards();
void moveBackward();
void moveForward();
void setSpeedLeft(int x);
void setSpeedRight(int x);
void stopMotors();
void turnLeft();
void turnRight();

#endif