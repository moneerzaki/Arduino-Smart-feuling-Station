// main.ino

#include "Config.h"

// Function prototypes
void setupUltrasonic();
long readDistance();
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
}

void loop() {
  long d1 = readDistance();
  long d2 = readDistance();
  long d3 = readDistance();
  long final_dist = median(d1, d2, d3); 

  Serial.print("Distance: ");
  Serial.print(final_dist);
  Serial.println(" cm");

  rotateServoIfNeeded(final_dist);

  delay(100);
}
