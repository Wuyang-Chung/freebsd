#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int	fh;
	char	*msg = "Hello, this is just a test.";
	char	*p;
	char	c = 't';
	int	i;

	fh = open("/tmp/fifo", O_RDWR);
	for (i=0; i<10; i++) {
		p = msg;
		while (*p != 0) {
			write(fh, p++, 1);
			read(fh, &c, 1);
			putchar(c);
		}
		putchar('\n');
	}
	c = 0xAA;
	write(fh, &c, 1);
	close(fh);
	return 0;
}
