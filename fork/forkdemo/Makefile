
CC = gcc

forkdemo: forkdemo.o
	$(CC) -o forkdemo forkdemo.o

forkdemo.o: forkdemo.c 
	$(CC) -c -o forkdemo.o forkdemo.c 

clean:
	rm -rf *.o forkdemo

