#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <err.h>
#include <sys/param.h>
#include <sys/cpuset.h>
#include <sys/stat.h>

void cpu_bind(void)
{
	int i;
	cpuset_t myset;

	/* Get CPU mask for the current thread */
	if (cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, -1, sizeof(myset), &myset) == -1)
		err(1, "getaffinity failed");

	/* Find first available CPU - don't assume CPU0 is always available */
	for (i = 0; i < CPU_SETSIZE; i++)
		if (CPU_ISSET(i, &myset))
			break; 

	if (i == CPU_SETSIZE)
		err(1, "Not allowed to run on any CPUs?  How did I print this, then?");

	/* Set new CPU mask */
	printf ("Setting affinity to CPU %d\n", i);
	CPU_ZERO(&myset);
	CPU_SET(i, &myset);

	if (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, -1, sizeof(myset), &myset) == -1)
		err(1, "setaffinity failed");
}

char const * const fifo = "/tmp/fifo";

int main(int argc, char *argv[])
{
	int	fh;
	unsigned char	c;

	cpu_bind();
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
