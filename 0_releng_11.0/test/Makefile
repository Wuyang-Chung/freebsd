default: client.out server.out

elf: client.elf server.elf

clean:
	rm *.out *.elf

client.out: client.c
	cc -static client.c -o client.out

server.out: server.c
	cc -static server.c -o server.out

client.elf: client.out
	readelf -a client.out > client.elf

server.elf: server.out
	readelf -a server.out > server.elf

pthread:
	cc -lpthread pthread_test.c

