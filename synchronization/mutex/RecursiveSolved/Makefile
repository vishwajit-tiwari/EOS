#Race Condition => Data Corruption Solution is Mutex

CC = gcc -g

all: recursiveSolved

recursiveSolved: recursiveSolved.o 
	$(CC) -o recursiveSolved recursiveSolved.o -lpthread

# -lpthread to remove linker error

recursiveSolved.o: recursiveSolved.c 
	$(CC) -c -o recursiveSolved.o recursiveSolved.c 

clean:
	rm -rf *.o recursiveSolved

