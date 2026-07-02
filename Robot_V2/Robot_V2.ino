void setup() {
  setupServo();
  setupMotors();
  setupLED();
  setupIMU();
  setupEncoder();
}


void loop() 
{
  motorsOn();
  long dis = getDistance();
  if(dis<10)
  {
    stopMotors();
    delay(100);
    moveBackward();
    delay(500);
    stopMotors();
    servoScan();
  }
  else
  {
    moveForward();
  }

 
}
