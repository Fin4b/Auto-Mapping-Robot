#include "SR04.h"

#define TRIG_PIN A1
#define ECHO_PIN A2

SR04 distance = SR04(ECHO_PIN, TRIG_PIN);

long getDistance()
{
  return distance.Distance();
}

long measure()
{
  long a = getDistance();
  delay(25);
  long b = getDistance();
  delay(25);
  long c = getDistance();

  long med = median(a,b,c);
  return med;
}

long median(long a, long b, long c) 
{
  if ((a >= b && a <= c) || (a >= c && a <= b))
    return a;

  if ((b >= a && b <= c) || (b >= c && b <= a))
    return b;

  return c;
}
