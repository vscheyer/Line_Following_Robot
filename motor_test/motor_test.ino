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
int goSpeed = 25;
int turnSpeed = 0;
int speedR = 0;
int speedL = 0;

void setup() {
  AFMS.begin();
  myMotorR->setSpeed(goSpeed);
  myMotorL->setSpeed(goSpeed);
  pinMode(sensorPinR, INPUT);
  pinMode(sensorPinL, INPUT);
  Serial.begin(400); 
}

void loop() {

  sensorValueR = analogRead(sensorPinR);
  sensorValueL = analogRead(sensorPinL);
  Serial.print(sensorValueR);
  Serial.print(' ');
  Serial.print(sensorValueL);
  Serial.print(' ');
  Serial.print(speedR);
  Serial.print(' ');
  Serial.println(speedL);
  

  if (sensorValueR < 700 && sensorValueL < 700) {
    myMotorR->setSpeed(goSpeed);
    myMotorL->setSpeed(goSpeed);
    myMotorR->run(FORWARD);
    myMotorL->run(FORWARD);
    speedR = goSpeed;
    speedL = goSpeed;
  
  }
  else if (sensorValueR < 700 && sensorValueL > 700){
    myMotorR->setSpeed(goSpeed);
    myMotorL->setSpeed(turnSpeed);
    myMotorR->run(FORWARD);
    myMotorL->run(FORWARD);
    speedR = goSpeed;
    speedL = turnSpeed;
    
  }
  else if (sensorValueR > 700 && sensorValueL <700){
    myMotorR->setSpeed(turnSpeed);
    myMotorL->setSpeed(goSpeed);
    myMotorR->run(FORWARD);
    myMotorL->run(FORWARD);
    speedR = turnSpeed;
    speedL = goSpeed;
    
  }
}
