all: sigbus

sigbus: sigbus_catcher.o emulate_FileRepConnClient_CloseConnection.o
	gcc -g sigbus_catcher.o emulate_FileRepConnClient_CloseConnection.o -o sigbus

sigbus_catcher.o:
	gcc -g -c sigbus_catcher.c -o sigbus_catcher.o

emulate_FileRepConnClient_CloseConnection.o:
	nasm -f elf64 -o emulate_FileRepConnClient_CloseConnection.o emulate_FileRepConnClient_CloseConnection.s

clean:
	rm *.o sigbus
