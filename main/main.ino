// main.ino

#include "Config.h"

// global variables: 
  int currstate = 0;
  char st1,st2,st3; 
  long st4; 

// Function prototypes
void setupUltrasonic();
long readDistanceGate();
long readDistanceLane();
void setupServo();
void rotateServoIfNeeded(long distance);

// get an accurate reading from the US sensor 
long median (long a, long b, long c)
{
    if ((a >= b && a <= c) || (a <= b && a >= c)) return a;
    if ((b >= a && b <= c) || (b <= a && b >= c)) return b;
    return c;

}

// print str1 in first row & str2 in second row
void printlcd(String str1, String str2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(str1); //Hello!
  lcd.setCursor(0, 1);
  lcd.print(str2); //"1:El 2:Oil 3:Gas"
}

// wait for the keypad keys to be pressed 
char waitForKey() {
    char key = NO_KEY;
    while (key == NO_KEY) {
       
      long d1 = readDistanceLane();
      long d2 = readDistanceLane();
      long d3 = readDistanceLane();
      long final_dist = median(d1, d2, d3); 
      while (final_dist >= 20) {
        long d1 = readDistanceLane();
        long d2 = readDistanceLane();
        long d3 = readDistanceLane();
        final_dist = median(d1, d2, d3);  
        // printlcd("Come closer!!", ""); 
        }
      key = keypad.getKey();
    }
    return key; 
}

long waitForPQ(String str) {
  String inputStr = "";
  char key;

  // Initial display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(str);
  lcd.setCursor(0, 1);
  lcd.print("F:Fin B:bk E:edt");

  while (true) {
    key = keypad.getKey();

    if (key != NO_KEY) {
      if (key >= '0' && key <= '9') {
        inputStr += key;
      }
      else if (key == 'E' || key == 'e') {
        if (inputStr.length() > 0) {
          inputStr.remove(inputStr.length() - 1);
        }
      }
      else if (key == 'F' || key == 'f') {
        if (inputStr.length() > 0) {
          return inputStr.toInt();
        }
      }
      else if (key == 'B' || key == 'b') {
        return -1;
      }

      // Update only the number section (first row after "Number: ")
      lcd.setCursor(8, 0); // after "Number: "
      lcd.print("       "); // clear previous input
      lcd.setCursor(8, 0);
      lcd.print(inputStr);
    }
  }
}
 
long calculatePrice(){
  if (st1 == '2' && st2 == '1') return st4 * 12.25;
  else if (st1 == '2' && st2 == '2') return st4 * 13.75;
  else if (st1 == '2' && st2 == '3') return st4 * 15.95;
  else if (st1 == '3') return st4 * 13.75; 
  else if (st1 == '1') return st4 * 3.75; 

}

// The whole code for the entry gate
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

// the whole code for the Lane 
void Lane(){
  long d1 = readDistanceLane();
  long d2 = readDistanceLane();
  long d3 = readDistanceLane();
  long final_dist = median(d1, d2, d3); 
  // Serial.println(final_dist); 

  if (final_dist > 20) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    currstate = 1;
    printlcd("Come closer","please :)");
  }
  else if (final_dist <= 20 && currstate == 1){
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    printlcd("Hello!", "1:El 2:Oil 3:Gas"); 
    st1 = waitForKey(); 
    if (st1 == '1' || st1 == '2' || st1 == '3') currstate = 2; 
    else currstate = 1; 
  } 
  else if (final_dist <= 20 && currstate == 2){
    if(st1 == '1') currstate = 3;
    else if(st1 == '2') printlcd("1:80 2:92 3:95", "B:back"); 
    else if(st1 == '3') printlcd("1:12.5 2:25 3:35", "B:back"); 

    if(st1!='1'){
      st2 = waitForKey(); 
      if(st2 == 'B')  currstate = 1;
      else if (st2 == '1' || st2 == '2' || st2 == '3')       
        currstate = 3; 
      else currstate = 2; 
    }
  } 
  else if (final_dist <= 20 && currstate == 3){
    printlcd("1:Price 2:Qwntty", "B:back");
    st3 = waitForKey(); 
    if(st3 == 'B')  currstate = 2;
    else if (st3 == '1' || st3 == '2')          
      currstate = 4; 
    else currstate = 3;
  } 
  else if (final_dist <= 20 && currstate == 4){
    String str;
    if(st3 == '1') str = "Price: ";
    else if(st3 == '2') str = "Qwntty: ";

    st4 = waitForPQ(str); 

    if(st4 == -1) currstate = 3;
    else{
      long price; 
      if(st3 == '2') price = calculatePrice(); 
      else price = st4; 
      printlcd(String(price) + " LE", "Thanks See You"); 
      delay(1000);
      currstate = 5;
    }
  } 
  else if(final_dist <= 20 && currstate == 5){} 

}

void setup() {
  Serial.begin(9600);
  setupUltrasonic();
  setupServo(); 
  initializeLCD();
  pinMode(redLED, OUTPUT); //for red led
  pinMode(greenLED, OUTPUT); //for green led
}

void loop() {
  
  Gate();
  // Lane(); 

  delay(10);
}




