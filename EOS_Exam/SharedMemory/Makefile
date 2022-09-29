#Makefile for shared memory

CC = gcc -g 

all: p1 p2

p1: p1.o
	$(CC) -o p1 p1.o -lrt -lpthread

p2: p2.o 
	$(CC) -o p2 p2.o -lrt -lpthread

# -lrt to avoid linker error

p1.o: p1.c 
	$(CC) -c -o p1.o p1.c 

p2.o: p2.c 
	$(CC) -c -o p2.o p2.c 

clean:
	rm -rf *.o p1 p2 


