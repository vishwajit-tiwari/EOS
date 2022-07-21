# Mutual Exclution Semaphore to solve Racecondition

CC = gcc

all: mutualExSemaphore

mutualExSemaphore: mutualExSemaphore.o 
	$(CC) -o mutualExSemaphore mutualExSemaphore.o -lpthread

# -lpthread to remove linker error

mutualExSemaphore.o: mutualExSemaphore.c 
	$(CC) -c -o mutualExSemaphore.o mutualExSemaphore.c 

clean:
	rm -rf *.o mutualExSemaphore
