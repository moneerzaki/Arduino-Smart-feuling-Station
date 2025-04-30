// main.ino

#include "Config.h"

// Function prototypes
void setupUltrasonic();
long readDistanceGate();
void setupServo();
void rotateServoIfNeeded(long distance);
long median (long a, long b, long c)
{
    if ((a >= b && a <= c) || (a <= b && a >= c)) return a;
    if ((b >= a && b <= c) || (b <= a && b >= c)) return b;
    return c;

}

void setup() {
  Serial.begin(9600);
  setupUltrasonic();
  setupServo();
  // lcd 
  // keypad 
  
}





void Gate(){
    long d1 = readDistanceGate();
    long d2 = readDistanceGate();
    long d3 = readDistanceGate();
    long final_dist = median(d1, d2, d3); 

    Serial.print("Distance: ");
    Serial.print(final_dist);
    Serial.println(" cm");

    rotateServoIfNeeded(final_dist);
}

void loop() {
  
  Gate();
  // Lane(); 

  delay(10);
}
