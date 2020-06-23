#include "MainMenu.h"
#include "SaveLoad.h"
#include "Utils.h"
#include "Servo.h"
#include "SmartLCD.h"

/* The entrance of the program. */

void setup() {
  // put your setup code here, to run once:
  load_all_data();
  init_pins();
  init_LCD();
  init_servo();
  clear_status();
}

void loop() {
  // put your main code here, to run repeatedly:
  main_loop();
}
