#ifndef _GUARD_TERM_
#define _GUARD_TERM_

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

typedef enum
{
	DEFAULT,
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	LIGHT_GRAY,
	DARK_GRAY,
	LIGHT_RED,
	LIGHT_GREEN,
	LIGHT_YELLOW,
	LIGHT_BLUE,
	LIGHT_MAGENTA,
	LIGHT_CYAN,
	WHITE
}colors;


int mt_clrscr();
int mt_gotoXY(int x,int y);
int mt_getscreensize(int *rows,int *cols);
int mt_setfgcolor(colors color);
int mt_setbgcolor(colors color);



#endif
