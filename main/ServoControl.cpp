// ServoControl.cpp

#include <Arduino.h>
#include <Servo.h>
#include "Config.h"


Servo myServo;

// global variables....
const int distanceThreshold = 20;
// int pos = 0;


void setupServo() {
  myServo.attach(servoPin, 500, 2500);
  myServo.write(0);  // Initial position
}

void rotateServoIfNeeded(long distance) {
  if (distance < distanceThreshold) myServo.write(90);  // Rotate to 90°}
  else myServo.write(0); 
}
