#include "mySimpleComputer.h"



int main()
{
	int a;
	sc_memoryInit();
	sc_memorySet(10,1);
	sc_memoryGet(10,&a);
	printf("%d\n",a);
	sc_memorySave("1.txt");
	sc_memoryInit();
	sc_memoryLoad("1.txt");
	sc_memoryGet(10,&a);
	printf("%d\n",a);
	return 0;
}

