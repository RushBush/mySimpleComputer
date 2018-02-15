#include "mySimpleComputer.h"



int main()
{
	int a;
	sc_regInit();
	sc_regSet(4,1);
	printf("%d\n",reg_flags);
	sc_regGet(4,&a);
	printf("%d ",a);
	return 0;
}

