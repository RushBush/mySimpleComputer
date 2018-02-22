#include "myTerm.h"


int mt_clrscr()
{
	printf("\E[H\E[J");
	return 0;
}

int mt_gotoXY(int x,int y)
{
	if ((x>=0) && (y>=0))
	{
		printf("\E[%d;%dH",x,y);
		return 0;
	}
	else
		return -1;
}


int mt_getscreensize(int *rows,int *cols)
{
	struct winsize w;
	
	if (!ioctl(STDOUT_FILENO, TIOCGWINSZ, &w))
	{
		*rows=w.ws_row;
		*cols=w.ws_col;
		return 0;
	}
	else
		return -1;
	
}
