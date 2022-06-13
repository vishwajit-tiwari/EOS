
CC = gcc

all: sender receiver

sender: sender.o
	$(CC) -o sender sender.o
	
receiver: receiver.o
	$(CC) -o receiver receiver.o

sender.o: sender.c 
	$(CC) -c -o sender.o sender.c 

receiver.o: receiver.c 
	$(CC) -c -o receiver.o receiver.c 

clean:
	rm -rf *.o sender receiver

