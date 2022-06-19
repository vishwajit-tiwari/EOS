
CC = gcc

threaddemo: threaddemo.o
	$(CC) -o threaddemo threaddemo.o -lpthread

# -lpthread to remove linker error

threaddemo.o: threaddemo.c 
	$(CC) -c -o threaddemo.o threaddemo.c 

clean:
	rm -rf *.o threaddemo 

