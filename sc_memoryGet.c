#include "mySimpleComputer.h"


int sc_memoryGet(int address,int *value)
{
	if ((address>=0) && (address<SIZE))
	{
		*value=Memory[address];
		return 0;
	}
	else
		return -1;
}
