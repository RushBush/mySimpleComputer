#ifndef _GUARD_H_
#define _GUARD_H_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int Memory[SIZE];

int sc_memoryInit();
int sc_memorySet(int address,int value);
int sc_memoryGet(int address,int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);


#endif
