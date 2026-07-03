volatile long countLeft = 0;
volatile long countRight = 0;

void setupEncoder()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

attachInterrupt(digitalPinToInterrupt(2),addLeft,CHANGE);
attachInterrupt(digitalPinToInterrupt(3),addRight,CHANGE);
}
void addLeft()
{
  countLeft ++;
}
void addRight()
{
  countRight ++;
}