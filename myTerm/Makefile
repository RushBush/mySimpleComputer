.PHONY: clean all

CC = gcc
FLAGS = -Wall -std=c99 -o 
SRC = main.c myTerm.c
OBJ = $(SRC:.c=.o)

all: 
	$(CC) $(FLAGS) main $(SRC)
	
clean:
	rm -f *.o
