#Race Condition => Data Corruption Solution is Mutex

CC = gcc -g

all: recursiveProblem

recursiveProblem: recursiveProblem.o 
	$(CC) -o recursiveProblem recursiveProblem.o -lpthread

# -lpthread to remove linker error

recursiveProblem.o: recursiveProblem.c 
	$(CC) -c -o recursiveProblem.o recursiveProblem.c 

clean:
	rm -rf *.o recursiveProblem

