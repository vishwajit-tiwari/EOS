# Makefile for Barrier

CC = gcc -g

all: barrier

barrier: barrier.o
	$(CC) -o barrier barrier.o -lpthread

# -lpthread to avoid linker error

barrier.o: barrier.c 
	$(CC) -c -o barrier.o barrier.c 

clean:
	rm -rf *.o barrier