
CC = gcc

thread_attr: thread_attr.o
	$(CC) -o thread_attr thread_attr.o -lpthread

# -lpthread to remove linker error

thread_attr.o: thread_attr.c 
	$(CC) -c -o thread_attr.o thread_attr.c 

clean:
	rm -rf *.o thread_attr 

