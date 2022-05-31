CC = arm-linux-gnueabi-gcc

hello_arm32: hello.o
	$(CC) -o hello_arm32 hello.o

hello.o: hello.c 
	$(CC) -c -o hello.o hello.c 

clean:
	rm -rf *.o hello_arm32 clean