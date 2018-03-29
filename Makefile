PHONY: clean all

CC = gcc
FLAGS = -Wall -std=c99 -o 
SRC = src/myReadkey.h src/myReadkey.c src/main.c
OBJ = $(SRC:.c=.o)

all: 
	$(CC) $(FLAGS) main $(SRC)
	
clean:
	rm -f *.o
