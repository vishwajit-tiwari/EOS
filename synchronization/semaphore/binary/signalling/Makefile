# Signalling Semaphore Solution To => Race Condition / Shared Resource

CC = gcc

all: sigSem

sigSem: sigSem.o
	$(CC) -o sigSem sigSem.o -lpthread

# -lpthread to avoid linker error

sigSem.o: sigSem.c 
	$(CC) -c -o sigSem.o sigSem.c 

clean:
	rm -rf *.o sigSem