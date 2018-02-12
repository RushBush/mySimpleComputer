#include "mySimpleComputer.h"



int main()
{

	sc_memoryInit();
	for (int i=0;i<SIZE;i++)
		sc_memorySet(i,i+1);
	sc_memorySave("ssss.txt");
	return 0;
}

