/*-
 * Copyright (c) 1999 Assar Westerlund
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include <sys/param.h>
#include <sys/proc.h>
#include <sys/module.h>
#include <sys/sysproto.h>
#include <sys/sysent.h>
#include <sys/kernel.h>
#include <sys/systm.h>
#include <sys/unistd.h>	

struct sfork_arg {
	int (*func)(void *);
	void *arg;
};

/*
 * The function for implementing the syscall.
 */
static int
sfork(struct thread *td, void *arg)
{
#if 1
	printf("sfork: Hello\n");
	return (0);
#else
	struct sfork_arg *uap = arg;
	struct fork_req fr;
	int error, pid;

	bzero(&fr, sizeof(fr));
	fr.fr_flags = RFFDG | RFPROC | RFSAS;
	fr.fr_pidp = &pid;
	fr.fr_func = uap->func;
	fr.fr_arg = uap->arg;
	error = fork1(td, &fr);
	if (error == 0) {
		td->td_retval[0] = pid;	//wyc return value to the parent
		td->td_retval[1] = 0;
	}
	return (error);
#endif
}

/*
 * The `sysent' for the new syscall
 */
static struct sysent sfork_sysent = {
	0, //2,			/* sy_narg */
	sfork			/* sy_call */
};

/*
 * The offset in sysent where the syscall is allocated.
 */
static int sfork_offset = NO_SYSCALL;

/*
 * The function called at load/unload.
 */
static int
sfork_load(struct module *module, int cmd, void *arg)
{
	int error = 0;

	switch (cmd) {
	case MOD_LOAD :
		printf("syscall loaded at %d\n", sfork_offset);
		break;
	case MOD_UNLOAD :
		printf("syscall unloaded from %d\n", sfork_offset);
		break;
	default :
		error = EOPNOTSUPP;
		break;
	}
	return (error);
}

SYSCALL_MODULE(sfork, &sfork_offset, &sfork_sysent, sfork_load, NULL);

struct sinit_arg {
	int (*func)(void *);
	void *arg;
};

/*
 * The function for implementing sinit
 */
static int
sinit(struct thread *td, void *arg)
{
	printf("sinit: Hello\n");
	return (0);
}

/*
 * The `sysent' for the new syscall
 */
static struct sysent sinit_sysent = {
	0,			/* sy_narg */
	sinit			/* sy_call */
};

/*
 * The offset in sysent where the syscall is allocated.
 */
static int sinit_offset = NO_SYSCALL;

/*
 * The function called at load/unload.
 */
static int
sinit_load(struct module *module, int cmd, void *arg)
{
	int error = 0;

	switch (cmd) {
	case MOD_LOAD :
		printf("syscall loaded at %d\n", sinit_offset);
		break;
	case MOD_UNLOAD :
		printf("syscall unloaded from %d\n", sinit_offset);
		break;
	default :
		error = EOPNOTSUPP;
		break;
	}
	return (error);
}

SYSCALL_MODULE(sinit, &sinit_offset, &sinit_sysent, sinit_load, NULL);
