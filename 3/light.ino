/* Arduino example code to display custom characters on I2C character LCD. More info: www.makerguides.com */

// Include the library:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create lcd object of class LiquidCrystal_I2C:
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.

byte level[][8]={{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10}, 
                {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
                {0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C},
                {0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E}};

int sensorValue = 0;
int buttonValue = 0;
int detail = 0;
int lastLength = 0;
char str[20] = "";

void setup() {
  // put your setup code here, to run once:
  // Initialize LCD and turn on the backlight:
  lcd.init();
  lcd.backlight();

  // Create new characters:
  lcd.createChar(1, level[0]);
  lcd.createChar(2, level[1]);
  lcd.createChar(3, level[2]);
  lcd.createChar(4, level[3]);

  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(1)
  {
    sensorValue = analogRead(A0);
    buttonValue = analogRead(A1);
    /*
    Serial.print(sensorValue);
    Serial.print("   ");
    Serial.print(buttonValue);
    Serial.print('\n');
    */

    if(buttonValue < 1000)
    {
      delay(50);
      continue;
    }
    lcd.clear();
    detail = map(sensorValue, 1023, 0, 0, 80);

    int fulls = detail / 5;
    int parts = detail % 5;

    int i; // loop var
    for(i=0; i<fulls; i++) str[i]=255;
    if(parts>0) str[i]=8+parts;
    
    lcd.setCursor(0, 0);
    lcd.print(str);
    lcd.setCursor(0, 1);
    lcd.print(str);

    // clear the string
    for(i=0; i<20; i++) str[i]='\0';
    delay(50);
  }
}
