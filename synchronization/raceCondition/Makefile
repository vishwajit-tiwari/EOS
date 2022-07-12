#Race Condition => Data Corruption

CC = gcc

all: racecondition

racecondition: racecondition.o 
	$(CC) -o racecondition racecondition.o -lpthread

# -lpthread to remove linker error

racecondition.o: racecondition.c 
	$(CC) -c -o racecondition.o racecondition.c 

clean:
	rm -rf *.o racecondition

