// Ultrasonic.cpp

#include <Arduino.h>
#include "Config.h"

void setupUltrasonic() {
  pinMode(trigPinGate, OUTPUT);
  pinMode(echoPinGate, INPUT);
  pinMode(trigPinLane, OUTPUT);
  pinMode(echoPinLane, INPUT);

}

long readDistanceGate() {
  digitalWrite(trigPinGate, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinGate, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinGate, LOW);

  long duration = pulseIn(echoPinGate, HIGH);
  long distance = duration * 0.034 / 2;

  delay(10); 
  return distance;
}


long readDistanceLane() {
  digitalWrite(trigPinLane, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinLane, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLane, LOW);

  long duration = pulseIn(echoPinLane, HIGH);
  long distance = duration * 0.034 / 2;

  delay(10); 
  return distance;
}
