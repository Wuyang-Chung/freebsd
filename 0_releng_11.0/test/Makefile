default: client.out server.out

elf: client_elf.txt server_elf.txt

clean:
	rm *.out *_elf.txt

client.out: client.c
	cc -static client.c -o client.out

server.out: server.c
	cc -static server.c -o server.out

client_elf.txt: client.out
	readelf -a client.out > client_elf.txt

server_elf.txt: server.out
	readelf -a server.out > server_elf.txt

pthread:
	cc -lpthread pthread_test.c

