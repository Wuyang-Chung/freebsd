#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int	fh;
	unsigned char	c;

	mkfifo("/tmp/fifo", 0600);
	fh = open("/tmp/fifo", O_RDWR);
	while(1) {
		read(fh, &c, 1);
		if (c == 0xAA)
			break;
		write(fh, &c,1);
	}
	close(fh);
	return 0;
}
