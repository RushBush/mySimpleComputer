#include "myTerm.h"

int main()
{
	mt_clrscr();
	mt_gotoXY(5,5);
	printf("HELLO\n");
	int a,b;
	mt_getscreensize(&a,&b);
	printf("%d %d\n",a,b);
	mt_setfgcolor(BLACK);
	printf("HELLO  "); 
	mt_setfgcolor(RED);
	printf("HELLO  "); 
	mt_setfgcolor(GREEN);
	printf("HELLO  "); 
	mt_setfgcolor(YELLOW);
	printf("HELLO  "); 
	mt_setfgcolor(BLUE);
	printf("HELLO  "); 
	mt_setfgcolor(MAGENTA);
	printf("HELLO  "); 
	mt_setfgcolor(CYAN);
	printf("HELLO  "); 
	mt_setfgcolor(LIGHT_GRAY);
	printf("HELLO  "); 
	mt_setfgcolor(DARK_GRAY);
	printf("HELLO  "); 
	mt_setfgcolor(LIGHT_RED);
	printf("HELLO  "); 
	mt_setfgcolor(LIGHT_GREEN);
	printf("HELLO  "); 
	mt_setfgcolor(LIGHT_YELLOW);
	printf("HELLO  "); 
	mt_setfgcolor(LIGHT_BLUE);
	printf("HELLO  "); 
	mt_setfgcolor(LIGHT_MAGENTA);
	printf("HELLO  "); 
	mt_setfgcolor(LIGHT_CYAN);
	printf("HELLO  "); 
	mt_setfgcolor(WHITE);
	printf("HELLO  "); 
	mt_setfgcolor(DEFAULT);
	
	printf("\n");
	
	mt_setbgcolor(BLACK);
	printf("HELLO  "); 
	mt_setbgcolor(RED);
	printf("HELLO  ");
	mt_setbgcolor(GREEN);
	printf("HELLO  ");
	mt_setbgcolor(YELLOW); 
	printf("HELLO  ");
	mt_setbgcolor(BLUE);
	printf("HELLO  ");
	mt_setbgcolor(MAGENTA);
	printf("HELLO  ");
	mt_setbgcolor(CYAN);
	printf("HELLO  ");
	mt_setbgcolor(LIGHT_GRAY);
	printf("HELLO  ");
	mt_setbgcolor(DARK_GRAY);
	printf("HELLO  ");
	mt_setbgcolor(LIGHT_RED);
	printf("HELLO  ");
	mt_setbgcolor(LIGHT_GREEN);
	printf("HELLO  ");
	mt_setbgcolor(LIGHT_YELLOW);
	printf("HELLO  ");
	mt_setbgcolor(LIGHT_BLUE);
	printf("HELLO  ");
	mt_setbgcolor(LIGHT_MAGENTA);
	printf("HELLO  ");
	mt_setbgcolor(LIGHT_CYAN);
	printf("HELLO  ");
	mt_setbgcolor(WHITE);
	printf("HELLO  ");
	
	mt_setbgcolor(DEFAULT);
	
	return 0;
}

