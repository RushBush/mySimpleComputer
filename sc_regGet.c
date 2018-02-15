#include "mySimpleComputer.h"


int sc_regGet(int reg,int *value)
{
	if (reg>0)
	{
		*value=BIT_GET(reg_flags,reg);
	}
	else
		return -1;
	return 0;
}

