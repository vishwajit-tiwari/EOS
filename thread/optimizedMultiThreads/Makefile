CC = gcc

all: optimizedMulThread

optimizedMulThread: optimizedMulThread.o
	$(CC) -o optimizedMulThread optimizedMulThread.o -lpthread

# -lpthread to remove linker error

optimizedMulThread.o: optimizedMulThread.c 
	$(CC) -c -o optimizedMulThread.o optimizedMulThread.c 

clean:
	rm -rf *.o optimizedMulThread

