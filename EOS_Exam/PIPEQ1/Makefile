# Makefile for PIPE IPC Communication

CC = gcc

all: p1

p1: p1.o
	$(CC) -o p1 p1.o

p1.o: p1.c 
	$(CC) -c -o p1.o p1.c 

clean:
	rm -rf *.o p1 
