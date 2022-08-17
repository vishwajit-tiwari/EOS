# Makefile for shared memory

CC = gcc -g 

all: p1 p2

p1: process1.o
	$(CC) -o p1 process1.o -lrt

p2: process2.o
	$(CC) -o p2 process2.o -lrt

# -lrt to avoid linker error

process1.o: process1.c 
	$(CC) -c -o process1.o process1.c

process2.o: process2.c 
	$(CC) -c -o process2.o process2.c 

clean:
	rm -rf *.o p1 p2

