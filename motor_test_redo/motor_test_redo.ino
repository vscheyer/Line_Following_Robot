#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotorR = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorL = AFMS.getMotor(2);

int sensorPinR = A0;    // select the input pin for the potentiometer
int sensorPinL = A1;
int goSpeed = 20;
int turnSpeed = 0;

void setup() {
  AFMS.begin();
  myMotorR->setSpeed(goSpeed);
  myMotorL->setSpeed(goSpeed);
  Serial.begin(9600); 
}

void loop() {
    myMotorR->setSpeed(goSpeed);
    myMotorL->setSpeed(goSpeed);
    myMotorR->run(FORWARD);
    myMotorL->run(FORWARD);
 
}
