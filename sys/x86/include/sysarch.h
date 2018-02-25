/*-
 * Copyright (c) 1993 The Regents of the University of California.
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
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
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

/*
 * Architecture specific syscalls (X86)
 */
#ifndef _MACHINE_SYSARCH_H_
#define _MACHINE_SYSARCH_H_

#include <sys/cdefs.h>

#define I386_GET_LDT	0
#define I386_SET_LDT	1
#define	LDT_AUTO_ALLOC	0xffffffff
#if 0 //wyc
				/* I386_IOPL */
#define I386_GET_IOPERM	3
#define I386_SET_IOPERM	4
				/* xxxxx */
#define	I386_VM86		6	/* XXX Not implementable on amd64 */
#define	I386_GET_FSBASE		7
#define	I386_SET_FSBASE		8
#define	I386_GET_GSBASE		9
#endif
#define	I386_SET_GSBASE		10 //wyc must support
#define	I386_GET_XFPUSTATE	11 //wyc must support

/* Leave space for 0-127 for to avoid translating syscalls */
#define	AMD64_GET_FSBASE	128
#define	AMD64_SET_FSBASE	129
#define	AMD64_GET_GSBASE	130
#define	AMD64_SET_GSBASE	131
#define	AMD64_GET_XFPUSTATE	132

struct i386_ioperm_args {
	unsigned int start;
	unsigned int length;
	int	enable;
};

#ifdef __i386__
struct i386_ldt_args {
	unsigned int start;
	union descriptor *descs;
	unsigned int num;
};

struct i386_vm86_args {
	int	sub_op;			/* sub-operation to perform */
	char	*sub_args;		/* args */
};

struct i386_get_xfpustate {
	void *addr;
	int len;
};
#else
struct i386_ldt_args {
	unsigned int start;
	struct user_segment_descriptor *descs __packed;
	unsigned int num;
};

struct i386_get_xfpustate {
	unsigned int addr;
	int len;
};

struct amd64_get_xfpustate {
	void *addr;
	int len;
};
#endif

#ifndef _KERNEL
union descriptor;
struct dbreg;

__BEGIN_DECLS
int i386_get_ldt(int, union descriptor *, int);
int i386_set_ldt(int, union descriptor *, int);
#if 0 //wyc
int i386_get_ioperm(unsigned int, unsigned int *, int *);
int i386_set_ioperm(unsigned int, unsigned int, int);
int i386_vm86(int, void *);	//wyc No such function defined. It should be vm86_sysarch()
int i386_get_fsbase(void **);	//wyc No such function defined
int i386_get_gsbase(void **);	//wyc No such function defined 
int i386_set_fsbase(void *);	//wyc No such function defined
int i386_set_gsbase(void *);	//wyc No such function defined
#endif
int i386_set_watch(int, unsigned int, int, int, struct dbreg *);
int i386_clr_watch(int, struct dbreg *);
int amd64_get_fsbase(void **);
int amd64_get_gsbase(void **);
int amd64_set_fsbase(void *);
int amd64_set_gsbase(void *);
int sysarch(int, void *);
__END_DECLS
#else // _KERNEL
struct thread;
union descriptor;
#ifdef __i386__
int i386_get_ldt(struct thread *, struct i386_ldt_args *);
int i386_set_ldt(struct thread *, struct i386_ldt_args *, union descriptor *);
//int i386_get_ioperm(struct thread *, struct i386_ioperm_args *);
//int i386_set_ioperm(struct thread *, struct i386_ioperm_args *);
#else
int amd64_get_ldt(struct thread *, struct i386_ldt_args *);
int amd64_set_ldt(struct thread *, struct i386_ldt_args *,
    struct user_segment_descriptor *);
int amd64_get_ioperm(struct thread *, struct i386_ioperm_args *);
int amd64_set_ioperm(struct thread *, struct i386_ioperm_args *);
#endif // __i386__
#endif // ! _KERNEL

#endif /* !_MACHINE_SYSARCH_H_ */
