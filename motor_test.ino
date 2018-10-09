#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotorR = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorL = AFMS.getMotor(2);

int sensorPinR = A0;    // select the input pin for the potentiometer
int sensorPinL = A1;
int sensorValueR = 0;  // variable to store the value coming from the sensor
int sensorValueL = 0;
int goSpeed = 30;
int turnSpeed = 0;

void setup() {
  AFMS.begin();
  myMotorR->setSpeed(goSpeed);
  myMotorL->setSpeed(goSpeed);
  pinMode(sensorPinR, INPUT);
  pinMode(sensorPinL, INPUT);
  Serial.begin(9600); 
}

void loop() {

  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  Serial.println(sensorValueR);
  Serial.println(sensorValueL);
  

  if (sensorValueR < 600 && sensorValueL < 600) {
    myMotorR->setSpeed(goSpeed);
    myMotorL->setSpeed(goSpeed);
    myMotorR->run(FORWARD);
    myMotorL->run(FORWARD);
  
  }
  else if (sensorValueR < 600 && sensorValueL > 600){
    myMotorR->setSpeed(goSpeed);
    myMotorL->setSpeed(turnSpeed);
    myMotorR->run(FORWARD);
    myMotorL->run(FORWARD);
    
  }
  else if (sensorValueR > 600 && sensorValueL < 600){
    myMotorR->setSpeed(turnSpeed);
    myMotorL->setSpeed(goSpeed);
    myMotorR->run(FORWARD);
    myMotorL->run(FORWARD);
    
  }
}
