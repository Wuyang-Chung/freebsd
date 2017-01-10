#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char const * const fifo = "/tmp/fifo";

int main(int argc, char *argv[])
{
	int	fh;
	unsigned char	c;

	mkfifo(fifo, 0600);
	fh = open(fifo, O_RDWR);
	while(1) {
		read(fh, &c, 1);
		if (c == 0xAA)
			break;
		write(fh, &c,1);
	}
	close(fh);
	unlink(fifo);
	return 0;
}
