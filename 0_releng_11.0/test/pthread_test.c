#include <sys/cdefs.h>
//__FBSDID("$FreeBSD$");

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <sys/cpuset.h>

#define NUM_THREADS 4

#include <threads.h>

_Thread_local unsigned tl;

static void *
foo(void *threadid)
{
	int status;

	tl = (unsigned)threadid;
	tl += 100;
	printf("thread %4u 0x%X\n", (unsigned)tl, (unsigned)&status);
	return (void *)tl;
}

static void
sighandler(int signo /*__unused*/)
{
}

/*
 * This program invokes multiple threads and each thread calls
 * vfork() system call.
 */
int
main(void)
{
	pthread_t threads[NUM_THREADS];
	struct sigaction reapchildren;
	sigset_t sigchld_mask;
	int rc, t;
	unsigned ret;

	memset(&reapchildren, 0, sizeof(reapchildren));
	reapchildren.sa_handler = sighandler;
	if (sigaction(SIGCHLD, &reapchildren, NULL) == -1)
		err(1, "Could not sigaction(SIGCHLD)");

	sigemptyset(&sigchld_mask);
	sigaddset(&sigchld_mask, SIGCHLD);
	if (sigprocmask(SIG_BLOCK, &sigchld_mask, NULL) == -1)
		err(1, "sigprocmask");

	printf("main thread 0x%X\n", (unsigned)&threads[0]);
	for (t = 0; t < NUM_THREADS; t++) {
		rc = pthread_create(&threads[t], NULL, foo, (void *)t);
		if (rc)
			errc(1, rc, "pthread_create");
		rc = pthread_join(threads[t], (void **)&ret);
		if (rc)
			errc(1, rc, "pthread_join");
		printf("pthread_join %u\n", (unsigned)ret);
	}
	printf("%s: tl %u\n", __func__, tl);
	//pause();
	return (0);
}
