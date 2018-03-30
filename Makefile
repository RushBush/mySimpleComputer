PHONY: all clean
SRC=src/

all: hello
	
hello: main.o myReadkey.o myTerm.o myBigChars.o mySimpleComputer.o
	gcc main.o myReadkey.o myTerm.o myBigChars.o mySimpleComputer.o -o main
main.o: $(SRC)main.c
	gcc -c $(SRC)main.c
myReadkey.o: $(SRC)myReadkey.c
	gcc -c $(SRC)myReadkey.c
myTerm.o: $(SRC)myTerm.c
	gcc -c $(SRC)myTerm.c
myBigChars.o: $(SRC)myBigChars.c
	gcc -c $(SRC)myBigChars.c
mySimpleComputer.o: $(SRC)mySimpleComputer.c
	gcc -c $(SRC)mySimpleComputer.c 
	   	
clean:
	rm -rf *.o hello
