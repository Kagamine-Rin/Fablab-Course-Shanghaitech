#ifndef __SERVO_H
#define __SERVO_H

static int curr_degrees = 0;

#include <Servo.h>
static Servo myservo;  // create servo object to control a servo

static int pin = 5;

void init_servo()
{
	myservo.attach(pin);
	myservo.write(0);
}

void servo_set(int cur, int max)
{
	int val = map(cur, max, 0, 0, 180);
	myservo.write(val);
	delay(50);
}

void direct_set(int val)
{
	myservo.write(val);
	delay(50);
}

#endif