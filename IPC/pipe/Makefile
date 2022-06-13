
CC = gcc

pipedemo: pipedemo.o
	$(CC) -o pipedemo pipedemo.o

pipedemo.o: pipedemo.c
	$(CC) -c -o pipedemo.o pipedemo.c 

clean:
	rm -rf *.o pipedemo 

