#ifndef __MENU_H
#define __MENU_H

//    Length          +-2-4-6-8-0-2-4-|
static char* game_1 = " Super Mario";
static char* game_2 = " Left 4 Dead 2";
static char* game_3 = " FinalFantasy XV";
static char* game_4 = " Project DIVA";
static char* game_5 = " Red Alert 2";
static char* game_6 = " Legend of Zelda";
static char* game_7 = " Pokemon Sword";

static char* game_1j = " \xbd\xb0\xca\xdf\xb0 \xcf\xd8\xb5";
static char* game_2j = " Left 4 Dead 2";
static char* game_3j = " \xcc\xa7\xb2\xc5\xd9\xcc\xa7\xdd\xc0\xbc\xde\xb0 XV";
static char* game_4j = " \xcc\xdf\xdb\xbc\xde\xaa\xb8\xc4 DIVA";
static char* game_5j = " Red Alert 2";
static char* game_6j = " \xbe\xde\xd9\xc0\xde\xc9 \xc3\xde\xdd\xbe\xc2";
static char* game_7j = " \xce\xdf\xb9\xd3\xdd \xb9\xdd";

static char* m_3_0  = "  Are you sure?";
static char* m_3_1  = " \x05Yes    No";
static char* m_3_2  = "  Yes   \x05No";
static char* m_3_0_j = "  \xbc\xae\xb7 \xb6 \xbc\xcf\xbd\xb6?";
static char* m_3_1_j = " \x05\xca\xb2    \xb2\xb2\xb4";
static char* m_3_2_j = "  \xca\xb2   \x05\xb2\xb2\xb4";

static char* m_4_e = "  English";
static char* m_4_j = "  \xc6\xce\xdd\xba\xde";

static char buf[20] = "";

#include "SmartLCD.h"
#include "SaveLoad.h"

static char* game_filter(int index)
{
	if(lang != 1)
	{
		switch(index)
		{
			case 0: return game_1;
			case 1: return game_2;
			case 2: return game_3;
			case 3: return game_4;
			case 4: return game_5;
			case 5: return game_6;
			case 6: return game_7;
		}
	}
	else
	{
		switch(index)
		{
			case 0: return game_1j;
			case 1: return game_2j;
			case 2: return game_3j;
			case 3: return game_4j;
			case 4: return game_5j;
			case 5: return game_6j;
			case 6: return game_7j;
		}
	}
}

void show_timing_selection(int index)
{
	if(index == 6)
	{
		lcd_write(game_6, game_7);
		lcd_draw_arrow(1);
	}
	else
	{
		char* a = game_filter(index);
		char* b = game_filter(index + 1);
		lcd_write(a, b);
		lcd_draw_arrow(0);
	}
}

void show_timing_menu(int index, int time)
{
	sprintf(buf, "  %2d Min", time/60);
	lcd_write(game_filter(index), buf);
}

void show_left_time(int all, int cur)
{
	char str[20] = "";
	int detail = map(cur, 0, all, 0, 80);

    int fulls = detail / 5;
    int parts = detail % 5;

    int i; // loop var
    for(i=0; i<fulls; i++) str[i]=255;
    if(parts>0) str[i]=8+parts;

	sprintf(buf, "%2d%% %02d:%02d/%02d:00", 100*cur/all, cur/60, cur%60, all/60);
	lcd_write(str, buf);
}

void show_total_menu(int index)
{
	int t = saved_game_time[index];
	sprintf(buf, "%02dh %02dm %02ds", t/3600, (t/60)%60, t%60);
	lcd_write(game_filter(index), buf);
}

void show_reset_all(int index)
{
	if(lang != 1)
	{
		char* line2 = index? m_3_1: m_3_2;
		lcd_write(m_3_0, line2);
	}
	else
	{
		char* line2 = index? m_3_1_j: m_3_2_j;
		lcd_write(m_3_0_j, line2);
	}
	
}

void show_lang(int index)
{
	lcd_draw_arrow(index);
	lcd_write(m_4_e, m_4_j);
}

#endif