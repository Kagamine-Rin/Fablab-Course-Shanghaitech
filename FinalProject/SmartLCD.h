#ifndef __SMARTLCD_H
#define __SMARTLCD_H

static byte lines[2][20];

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

byte level[][8]={{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10}, 
                {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
                {0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C},
                {0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E},
            	{0x10,0x18,0x1C,0x1E,0x1E,0x1C,0x18,0x10}};

void init_LCD()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
  lcd.noBlink();
  lcd.setCursor(0, 0);
  lcd.createChar(1, level[0]);
  lcd.createChar(2, level[1]);
  lcd.createChar(3, level[2]);
  lcd.createChar(4, level[3]);
  lcd.createChar(5, level[4]);
  Serial.begin(115200);
}

void lcd_clear()
{
	lcd.clear();
	for(int i=0; i<20; i++)
	{
		lines[0][i] = 0;
		lines[1][i] = 0;
	}
}

void lcd_draw_arrow(int line)
{
	lcd.setCursor(0, line);
	lcd.write(13);
	lcd.setCursor(0, 1 - line);
	lcd.write(' ');
}

void lcd_write(char* line1, char* line2)
{
	for(int i=0; line1[i] != '\0' || lines[0][i] != '\0'; i++)
	{
		lcd.setCursor(i, 0);
		if(line1[i] == '\0')
		{
			for(int j=i; lines[0][j] != '\0'; j++)
			{
				lcd.setCursor(j, 0);
				lines[0][j] = '\0';
				lcd.write(' ');
			}
			break;
		}
		else if(lines[0][i] == '\0' || line1[i] != lines[0][i])
		{
			lcd.write(line1[i]);
			lines[0][i] = line1[i];
		}
	}
	for(int i=0; line2[i] != '\0' || lines[1][i] != '\0'; i++)
	{
		lcd.setCursor(i, 1);
		if(line2[i] == '\0')
		{
			for(int j=i; lines[1][j] != '\0'; j++)
			{
				lcd.setCursor(j, 1);
				lines[1][j] = '\0';
				lcd.write(' ');
			}
			break;
		}
		else if(lines[1][i] == '\0' || line2[i] != lines[1][i])
		{
			lcd.write(line2[i]);
			lines[1][i] = line2[i];
		}
	}
}

#endif