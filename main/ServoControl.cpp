// ServoControl.cpp

// #include <Arduino.h>
// #include <Servo.h>
#include "Config.h"
#include "Servo.h"


// Servo myServo;

// global variables....
const int distanceThreshold = 20;
// int pos = 0;


void setupServo() {
  // myServo.attach(servoPin, 500, 2500);
  attach(servoPin); 
  // myServo.write(0);  // Initial position
  write(0); 

}

void rotateServoIfNeeded(long distance) {
  // if (distance < distanceThreshold) myServo.write(90);  // Rotate to 90°}
  // else myServo.write(0); 
  if (distance < distanceThreshold) write(90);  // Rotate to 90°}
  else write(0); 


}
