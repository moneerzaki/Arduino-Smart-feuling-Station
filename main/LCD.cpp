// LCD.cpp

#include "config.h"

// Define LCD (address 0x27 is common for 16x2 I2C LCDs)
LiquidCrystal_I2C lcd(0x27, 16, 2);


void initializeLCD() {
  // lcd.init();          // Initialize LCD
  // lcd.backlight();     // Turn on backlight
  // // lcd.clear();
  // lcd.setCursor(0, 0);
  // lcd.print("Press a key:");

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LCD Initialized");
  delay(1000);

}