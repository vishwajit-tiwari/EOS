
CC = gcc

zombiedemo: zombiedemo.o
	$(CC) -o zombiedemo zombiedemo.o

zombiedemo.o: zombiedemo.c 
	$(CC) -c -o zombiedemo.o zombiedemo.c 

clean:
	rm -rf *.o zombiedemo 

