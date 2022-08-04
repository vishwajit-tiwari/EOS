#Race Condition => Data Corruption Solution is Mutex

CC = gcc

all: mutexdemo

mutexdemo: mutexdemo.o 
	$(CC) -o mutexdemo mutexdemo.o -lpthread

# -lpthread to remove linker error

mutexdemo.o: mutexdemo.c 
	$(CC) -c -o mutexdemo.o mutexdemo.c 

clean:
	rm -rf *.o mutexdemo

