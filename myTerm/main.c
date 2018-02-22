#include "myTerm.h"

int main()
{
	mt_clrscr();
	mt_gotoXY(5,5);
	printf("HELLO\n");
	int a,b;
	mt_getscreensize(&a,&b);
	printf("%d %d",a,b);
	return 0;
}

