#include <Servo.h>
#include "SR04.h"

// Sensor pins
#define TRIG_PIN 12
#define ECHO_PIN 11

// Motor driver pins
int enableA = 5;
int enableB = 6;

int in1 = 7;   // Motor 1 — 10=forward, 01=reverse
int in2 = 8;

int in3 = 3;   // Motor 2 — 10=forward, 01=reverse
int in4 = 4;

// Servo
int servoPin = 10;
Servo Servo1;

// Distances
long a;
int dis_mid  = 0;
int dis_left = 0;
int dis_right = 0;

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

void setup() {
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(9600);

  Servo1.attach(servoPin);
  Servo1.write(90);
  delay(1000);
}

void moveBackward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}

void moveForward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(enableA, LOW);  // Cut power to both channels
  digitalWrite(enableB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void loop() {
  digitalWrite(enableA, HIGH);
  digitalWrite(enableB, HIGH);

  moveForward();
  delay(100);

  a = sr04.Distance();
  Serial.print("Distance: ");
  Serial.println(a);

  if (a < 25) {
    moveBackward();
    delay(500);
    stopMotors();
    delay(1000);
    Servo1.write(0);
    delay(500);
    dis_left = sr04.Distance();

    Servo1.write(90);
    delay(500);
    dis_mid = sr04.Distance();

    Servo1.write(180);
    delay(500);
    dis_right = sr04.Distance();

      Servo1.write(90);
    delay(300);  // Was 10000 — just needs to settle

    Serial.print("L: "); Serial.print(dis_left);
    Serial.print(" M: "); Serial.print(dis_mid);
    Serial.print(" R: "); Serial.println(dis_right);

    if (dis_left > dis_right && dis_left > dis_mid) {
      Serial.println("Left");
      delay(1000);
      turnLeft();
      delay(600);  // Give the turn time to execute
    } else if (dis_right > dis_left && dis_right > dis_mid) {
      Serial.println("Right");
      delay(1000);
      turnRight();
      delay(600);  // Give the turn time to execute
    }

    stopMotors();

  }
  }