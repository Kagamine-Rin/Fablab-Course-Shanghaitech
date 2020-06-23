#ifndef __SAVELOAD_H
#define __SAVELOAD_H

#include <EEPROM.h>
#include "Utils.h"

static const int total_saved = 8;
static const int total_saved_len = total_saved * sizeof(int);

int saved_game_time[8] = {0};
int lang = 0; // 0 - Eng; 1 - Jap

typedef union
{
	int data;
	byte bytes[4];
} saved_int;

void load_all_data()
{
	saved_int curr_data;
	for(int i=0; i<total_saved; i++)
	{
		for(int j=0; j<4; j++)
		{
			curr_data.bytes[j] = EEPROM.read(i * 4 + j);
		}
		saved_game_time[i] = curr_data.data;
	}
	lang = saved_game_time[0];
}

void save_all_data()
{
	saved_game_time[0] = lang;
	saved_int curr_data;
	for(int i=0; i<total_saved; i++)
	{
		curr_data.data = saved_game_time[i];
		for(int j=0; j<4; j++)
		{
			EEPROM.write(i * 4 + j, curr_data.bytes[j]);
		}
	}
}

void clear_saved_data()
{
	lang = 0;
	for(int i=0; i<=7; i++)
		saved_game_time[i] = 0;
	for(int i = 0; i < total_saved_len; i++)
    	EEPROM.write(i, 0);
    Serial.println("Cleared!!");
}

#endif