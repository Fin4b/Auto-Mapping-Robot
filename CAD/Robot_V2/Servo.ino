#include <Servo.h>

  int servoPin = A0;
  Servo Servo1;

void setupServo()
{
  Servo1.attach(servoPin);
  Servo1.write(90);
  delay(500);
}

void servoScan()
{
  Servo1.write(0);
  blinkLED();
  delay(400);
  long dis_0 = measure();

  Servo1.write(30);
  blinkLED();
  delay(400);
  long dis_30 = measure();

  Servo1.write(60);
  blinkLED();
  delay(400);
  long dis_60 = measure();

  Servo1.write(90);
  blinkLED();
  delay(400);
  long dis_90 = measure();

  Servo1.write(120);
  blinkLED();
  delay(400);
  long dis_120 = measure();

  Servo1.write(150);
  blinkLED();
  delay(400);
  long dis_150 = measure();

  Servo1.write(180);
  blinkLED();
  delay(400);
  long dis_180 = measure();

  Servo1.write(0);
  blinkLED();
  delay(400);

  int bestAngle = direction(dis_0,dis_30,dis_60,dis_90,dis_120,dis_150,dis_180);
  turn(bestAngle);

}

int direction (long a, long b, long c, long d, long e, long f,long g)
{
  long dis[7] = {a,b,c,d,e,f,g};
  int angle[7] = {0,30,60,90,120,150,180};
  long bestDir = dis[0];
  int bestAngle = angle[0];
  for (int i=0;i<7;i++)
    {
      if (dis[i]>bestDir)
      {
        bestDir = dis[i];
        bestAngle = angle[i];
      }
    }
return bestAngle;
    
  
}














