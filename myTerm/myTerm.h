#ifndef _GUARD_TERM_
#define _GUARD_TERM_

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int mt_clrscr();
int mt_gotoXY(int x,int y);
int mt_getscreensize(int *rows,int *cols);
int mt_setfgcolor();
int mt_setbgcolor();



#endif
