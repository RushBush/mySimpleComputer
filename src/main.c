#include "myReadkey.h"



int main()
{	
	enum keys k;
	rk_mytermregime(0,0, 10, 1, 0);
	rk_readkey(&k);
	printf("%d ",k);

	return 0;
}

