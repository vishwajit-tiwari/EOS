CC = arm-linux-gnueabi-gcc

hello_arm: hello.o
	$(CC) -o hello_arm hello.o

hello.o: hello.c 
	$(CC) -c -o hello.o hello.c 

clean:
	rm -rf *.o hello_arm clean
