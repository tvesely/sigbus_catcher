all: sigbus

sigbus: sigbus_asm.o emulate_FileRepConnClient_CloseConnection.o
	gcc sigbus_asm.o emulate_FileRepConnClient_CloseConnection.o -o sigbus

sigbus_asm.o:
	gcc -c sigbus_asm.c -o sigbus_asm.o

emulate_FileRepConnClient_CloseConnection.o:
	nasm -f elf64 -o emulate_FileRepConnClient_CloseConnection.o emulate_FileRepConnClient_CloseConnection.s

clean:
	rm *.o sigbus
