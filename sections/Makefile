CC = gcc

sectiondemo: sectiondemo.o add.o
	$(CC) -o sectiondemo sectiondemo.o add.o

sectiondemo.o: sectiondemo.c 
	$(CC) -c -o sectiondemo.o sectiondemo.c 
add.o: add.c 
	$(CC) -c -o add.o add.c 

clean:
	rm -rf *.o sectiondemo  
