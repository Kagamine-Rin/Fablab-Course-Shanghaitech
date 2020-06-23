#ifndef __UTILS_H
#define __UTILS_H

/* Static pins defination */
static const int a_threshold = 1000;

static const int pin_1 = A3;
static const int pin_2 = 2;
static const int pin_3 = 1;
static const int pin_4 = 0;

static const int golden_1 = A0;
static const int golden_2 = A1;
static const int golden_3 = A2;

static const int tonePin = 9;

/* Initalization */
void init_pins()
{
	pinMode(pin_2, INPUT);
	pinMode(pin_3, INPUT);
	pinMode(pin_4, INPUT);

	pinMode(tonePin, OUTPUT);
	pinMode(5, OUTPUT);
}

/* Button utilities */

int get_button()
{
	/*
	Serial.print(analogRead(pin_1));
	Serial.print(" ");
	Serial.print(digitalRead(pin_2));
	Serial.print(" ");
	Serial.print(digitalRead(pin_3));
	Serial.print(" ");
	Serial.print(digitalRead(pin_4));
	Serial.print("\n");
	*/

	if(analogRead(pin_1) >= a_threshold)
		return 1;
	else if(digitalRead(pin_2) == HIGH)
		return 2;
	else if(digitalRead(pin_3) == HIGH)
		return 3;
	else if(digitalRead(pin_4) == HIGH)
		return 4;

	return 0;
}
/*
int get_golden()
{
	int bit = 0;
	if(analogRead(golden_1) >= a_threshold)
		bit += 4;
	if(analogRead(golden_2) >= a_threshold)
		bit += 2;
	if(analogRead(golden_2) >= a_threshold)
		bit += 1;
	return bit;
}
*/
/* Sound utilities */

/*
static int tune[] =
{
  1047, -1, 784, -1, 659, -1, 880, 988, 880, 784, 932, 784, 659, 587, 659
};

static float duration[]=
{
  0.0625, 0.125, 0.0625, 0.125, 0.0625, 0.0625, 0.08333, 0.08333, 0.08333, 0.08333, 0.08333, 0.08333, 0.0625, 0.0625, 0.125
};

void play_sound()
{
	digitalWrite(13, HIGH);
	for(int x=0;x<15;x++)
	  {
	    if(tune[x] > 0)
	      tone(tonePin,tune[x]);
	    delay(2500*duration[x]);
	    noTone(tonePin);
	  }
	digitalWrite(13, LOW);
}

void beep()
{

	digitalWrite(13, HIGH);
	delay(50);
	tone(tonePin,659);
    delay(200);
    noTone(tonePin);
    delay(50);
    digitalWrite(13, LOW);
    
}
*/

#endif