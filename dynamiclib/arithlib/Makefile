# To create Dynamic library we write "ar" "crv" "name_library"

CC = gcc

arithprog: main.o add.o sub.o mul.o div.o 
	$(CC) -o arithprog main.o add.o sub.o mul.o div.o
# To create library 
	$(CC) -shared -fPIC -o libarith.so add.o sub.o mul.o div.o 	
# To extract .o files from library (or .a file)	
#	ar -x libarith.so
main.o: main.c 
	$(CC) -c -o main.o main.c 
add.o: add.c 
	$(CC) -c -o add.o add.c 
sub.o: sub.c 
	$(CC) -c -o sub.o sub.c 
mul.o: mul.c 
	$(CC) -c -o mul.o mul.c 
div.o: div.c 
	$(CC) -c -o div.o div.c 

clean:
	rm -rf *.o arithprog libarith.so clean
