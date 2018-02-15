#include "mySimpleComputer.h"


int sc_regSet(int reg,int value)
{
	if (reg>0)
	{
		if (value==1)
		{
			BIT_SET(reg_flags,reg);
		}
		else if (value==0)
		{
			BIT_UNSET(reg_flags,reg);
		}
		else
			return 0;
	}
	else
		return -1;
	return 0;
}
