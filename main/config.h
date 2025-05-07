// Config.h

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>


/////////////// Gate ////////////////////////

// RGB pins 
const int greenLED = 12; 
const int redLED = 13; 

// Servo pin
const int servoPin = 11;

// Ultrasonic sensor pins
const int trigPinGate = 9;
const int echoPinGate = 10;
/////////////////////////////////////////////

// int red = 0;

//////////////// Lane1 ///////////////////////
// ultra sonic lane
const int trigPinLane = A0; 
const int echoPinLane = A1; 

// LCD  (already configured no need to assign)
// A4, A5 are assigned automatically 
extern LiquidCrystal_I2C lcd;

void initializeLCD();


// Keypad setup
extern const byte ROWS;
extern const byte COLS;
extern char keys[4][4];
extern byte rowPins[4];
extern byte colPins[4];
extern Keypad keypad;

///////////////////////////////////////////


#endif
