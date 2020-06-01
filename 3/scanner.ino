//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

char a[17];
char info[30];

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  //lcd.autoscroll();
  lcd.setCursor(0, 0);
  lcd.print("Test ASCII:");
  delay(1000);
  lcd.clear();
  a[16]=0;

}

void loop()
{
  for(byte i=0; i<256; i++)
  {
    a[i%16] = i;
    if(i%16 == 15)
    {
      lcd.print(a);
      lcd.setCursor(0, 1);
      sprintf(info, "%d --- %d", i-15, i);
      lcd.print(info);
      lcd.setCursor(0, 0);
      
      delay(5000);
      lcd.clear();
    }
    
  }
  
}
