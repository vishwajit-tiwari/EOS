
CC= gcc

syscalldemo: syscalldemo.o
	$(CC) -o syscalldemo syscalldemo.o 
syscalldemo.o: syscalldemo.c 
	$(CC) -c -o syscalldemo.o syscalldemo.c 

clean:
	rm -rf *.o syscalldemo desdlog.txt 
	