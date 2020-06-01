//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

char a[]={B11001010, B11011011, B10110000, ' ', B11011100, B10110000, B11011001, B11000100, '!', 0};

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");
  delay(3000);
  lcd.setCursor(0, 1);
  lcd.print(a);

}

void loop(){}
