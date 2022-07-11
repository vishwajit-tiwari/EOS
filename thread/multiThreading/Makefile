CC = gcc

all: multiThreads

multiThreads: multiThreads.o
	$(CC) -o multiThreads multiThreads.o -lpthread

# -lpthread to remove linker error

multiThreads.o: multiThreads.c 
	$(CC) -c -o multiThreads.o multiThreads.c 

clean:
	rm -rf *.o multiThreads

