.PHONY: clean all

CC = gcc
FLAGS = -Wall -o 
SRC = main.c sc_memoryInit.c sc_memorySet.c sc_memoryGet.c sc_memorySave.c
OBJ = $(SRC:.c=.o)

all: 
	$(CC) $(FLAGS) main $(SRC)
	
clean:
	rm -f *.o
