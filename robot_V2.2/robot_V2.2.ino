#include <Arduino.h>
#include "ServoControl.h"
#include "USS.h"
#include "LED.h"
#include "Server.h"
#include "Imu.h"
#include "Motors.h"

void setup()
{
    Serial.begin(115200);

    setupServo();
    setupUSS();
    setupLED();
    setupIMU();
    setupServer();
    setupMotors();
    



    Serial.println("Starting scan...");
}

void loop()
{
    /*updateIMU();
    
     long distance = getDistance();

    if (distance<20)
    {
        servoScan();
    }
        updateLED();
        updateServo();
        updateServer();*/
        moveForward();
        delay(500);
        moveBackward();


    


    
    
}