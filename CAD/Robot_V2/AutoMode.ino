void autoLoop()
{
   motorsOn();
  long dis = getDistance();
  if(dis<10)
  {
    turnLedRed();
    stopMotors();
    delay(100);
    moveBackward();
    delay(500);
    stopMotors();
    turnLedPurple();
    servoScan();
    setModeColour() 
  }
  else
  {
    moveForward();
  }
}