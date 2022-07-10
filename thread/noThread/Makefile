
CC = gcc

nothread: nothread.o
	$(CC) -o nothread nothread.o
	
# -lpthread to remove linker error

nothread.o: nothread.c 
	$(CC) -c -o nothread.o nothread.c 

clean:
	rm -rf *.o nothread 

