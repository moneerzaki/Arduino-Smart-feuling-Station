// Servo.cpp

// Constants for PWM timing
#include "Config.h"
#include "Servo.h"


const int pulseMin = 500;   // Minimum pulse width in µs
const int pulseMax = 2500;  // Maximum pulse width in µs
const int pwmFreqHz = 50;   // 50Hz for servo (20ms period)

// Stores which pin is attached
int attachedPin = -1;


// =================== Custom Servo Functions ===================

// Mimics Servo.attach(pin)
void attach(int pin) {
  attachedPin = pin;

  if (pin == 11) {
    DDRB |= (1 << PB5);  // Pin 11 is PB5 (OC1A) → Set as output

    // Set Fast PWM mode 14: TOP = ICR1
    TCCR1A = (1 << COM1A1) | (1 << WGM11);             // Non-inverting PWM on OC1A
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler = 8, Mode 14

    // Set TOP for 50Hz: 16MHz / 8 = 2MHz → 2MHz / 50Hz = 40000 ticks
    ICR1 = 40000;
  }
  else if (pin == 12) {
    DDRB |= (1 << PB6);  // Pin 12 is PB6 (OC1B)

    // Similar Timer1 setup but for OC1B
    TCCR1A = (1 << COM1B1) | (1 << WGM11);
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);
    ICR1 = 40000;
  }
}

// Mimics Servo.write(angle)
void write(int angle) {
  int pulseWidth = map(angle, 0, 180, pulseMin, pulseMax);  // µs
  int ticks = pulseWidth * 2;  // 2 MHz timer = 2 ticks/µs

  if (attachedPin == 11) {
    OCR1A = ticks;
  } else if (attachedPin == 12) {
    OCR1B = ticks;
  }
}