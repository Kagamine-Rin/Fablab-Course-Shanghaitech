#ifndef __MAINMENU_H
#define __MAINMENU_H

static int curr_menu_index = 0;
static int curr_menu_box[2] = {0};
static int timing_status = 0;
static int timing_seconds_all = 0;
static int timing_seconds_left = 0;
static int paused = 0;

static const int timing_scale = 10;

#include "SmartLCD.h"
#include "Utils.h"
#include "SaveLoad.h"
#include "Servo.h"
#include "Menu.h"

static char* menu_1e = "  Timekeeping";
static char* menu_2e = "  Statistics";
static char* menu_3e = "  Language";
static char* menu_4e = "  Reset All";
static char* menu_1j = "  \xbc\xde\xb6\xdd \xa6 \xca\xb6\xd9";
static char* menu_2j = "  \xc4\xb3\xb9\xb2";
static char* menu_3j = "  \xb9\xde\xdd\xba\xde \xc9 \xbe\xaf\xc3\xb2";
static char* menu_4j = "  \xbc\xae\xb7 \xb6";

char* menu_1 = menu_1e;
char* menu_2 = menu_2e;
char* menu_3 = menu_3e;
char* menu_4 = menu_4e;

static const int menu_entries = 3;
static const int game_entries = 6;

void set_lang_main(int val)
{
	if(val == 1)
	{
		menu_1 = menu_1j;
		menu_2 = menu_2j;
		menu_3 = menu_3j;
		menu_4 = menu_4j;
	}
	else
	{
		menu_1 = menu_1e;
		menu_2 = menu_2e;
		menu_3 = menu_3e;
		menu_4 = menu_4e;
	}
}

void clear_status()
{
	curr_menu_index = 0;
	curr_menu_box[1] = 0;
	timing_status = 0;
	timing_seconds_left = 0;
	timing_seconds_all = 0;
	paused = 0;
	lcd_clear();
	set_lang_main(lang);
}

void main_loop()
{
	int bu = get_button();
	//Serial.println(bu);
	// if(bu != 0)
	// 	beep();

	if(curr_menu_index == 0)
	{
		// in main menu
		switch(curr_menu_box[0])
		{
			case 0:
				lcd_write(menu_1, menu_2);
				lcd_draw_arrow(0);
				break;
			case 1:
				lcd_write(menu_2, menu_3);
				lcd_draw_arrow(0);
				break;
			case 2:
				lcd_write(menu_3, menu_4);
				lcd_draw_arrow(0);
				break;
			case 3:
				lcd_write(menu_3, menu_4);
				lcd_draw_arrow(1);
				break;
		}
		if(bu == 1)
			curr_menu_box[0] = curr_menu_box[0]-1 >= 0 ? curr_menu_box[0]-1 : menu_entries;
		if(bu == 2)
			curr_menu_box[0] = curr_menu_box[0]+1 <= menu_entries ? curr_menu_box[0]+1 : 0;
		if(bu == 3)
		{
			curr_menu_index = 1;
			curr_menu_box[1] = 0;
			lcd_clear();
		}

	}
	else if(curr_menu_index == 1)
	{
		// sub-menu, including: view time; timing games; reset all
		if(bu == 4)
		{
			clear_status();
		}
		switch(curr_menu_box[0])
		{
			case 0:
				if(timing_status == 0) // not timing yet
				{
					show_timing_selection(curr_menu_box[1]);
					if(bu == 1)
						curr_menu_box[1] = curr_menu_box[1]-1 >= 0 ? curr_menu_box[1]-1 : game_entries;
					if(bu == 2)
						curr_menu_box[1] = curr_menu_box[1]+1 <= game_entries ? curr_menu_box[1]+1 : 0;
					if(bu == 3)
					{
						timing_status = 1;
						lcd_clear();
					}
				}
				else if(timing_status == 1)
				{
					show_timing_menu(curr_menu_box[1], timing_seconds_all);
					if(bu == 1)
						timing_seconds_all = timing_seconds_all-60 >= 0 ? timing_seconds_all-60 : 0;
					if(bu == 2)
						timing_seconds_all = timing_seconds_all+60 <= 60*60 ? timing_seconds_all+60 : 3600;
					if(bu == 3)
					{
						timing_status = 2;
						lcd_clear();
					}
				}
				else
				{
					// in timing; create another loop
					timing_seconds_left = timing_seconds_all;
					direct_set(0); // init servo to 0
					while(timing_seconds_left > 0)
					{
						bu = get_button();
						if(bu == 3)
						{
							paused = 1 - paused;
						}
						else if(bu == 4)
						{
							break;
						}
						if(paused)
						{
							delay(1000);
							continue;
						}
						show_left_time(timing_seconds_all, timing_seconds_left);
						servo_set(timing_seconds_left, timing_seconds_all);
						delay(950); // compensate for the 50ms in servo.h
						timing_seconds_left -= timing_scale;
					}
					saved_game_time[curr_menu_box[1]] += (timing_seconds_all - timing_seconds_left);
					save_all_data();
					clear_status();
					// wait until card is pulled out
					direct_set(180);
					if(lang == 1)
						lcd_write("\xc3\xb0\xcc\xdf \xa6 \xc4\xd8\xc0\xde\xbc", "\xc3\xb8\xc0\xde\xbb\xb2");
					else
						lcd_write("Please pull your", "cassette out!");
					while(1)
					{
						bu = get_button();
						if(bu == 3)
							break;
						delay(100);
					}
					lcd_clear();
					direct_set(0);
				}
				break;

			case 1:
			    show_total_menu(curr_menu_box[1]);
				if(bu == 1)
					curr_menu_box[1] = curr_menu_box[1]-1 >= 0 ? curr_menu_box[1]-1 : game_entries;
				if(bu == 2)
					curr_menu_box[1] = curr_menu_box[1]+1 <= game_entries ? curr_menu_box[1]+1 : 0;
				break;

			case 3:
				show_reset_all(curr_menu_box[1]);
				if(bu == 1 || bu == 2)
					curr_menu_box[1] = 1 - curr_menu_box[1];
				else if(bu == 3)
				{
					if(curr_menu_box[1])
						clear_saved_data();
					clear_status();
				}
				break;

			case 2:
				show_lang(curr_menu_box[1]);
				if(bu == 1 || bu == 2)
					curr_menu_box[1] = 1 - curr_menu_box[1];
				else if(bu == 3)
				{
					lang = curr_menu_box[1];
					save_all_data();
					clear_status();
				}
				break;
		}
	}

	delay(150);
}


#endif