CC = gcc

projbin: project.o
	$(CC) -o projbin project.o -L. -larith
project.o: project.c 
	$(CC) -c -o project.o project.c 

clean:
	rm -rf *.o projbin