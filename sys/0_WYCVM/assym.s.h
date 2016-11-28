#if !defined(WYC)	//wyc: SI will not parse the code below
#define	BC32SEL	0x68
#define	BI_ENDCOMMON	0xc
#define	BI_ESYMTAB	0x44
#define	BI_KERNELNAME	0x4
#define	BI_KERNEND	0x48
#define	BI_NFS_DISKLESS	0x8
#define	BI_SIZE	0x30
#define	BI_SYMTAB	0x40
#define	BI_VERSION	0x0
#define	BOOTINFO_SIZE	0x88
#define	EFAULT	0xe
#define	ENAMETOOLONG	0x3f
#define	ENOENT	0x2
#define	GPROC0_SEL	0x9
#define	KCSEL	0x20
#define	KDSEL	0x28
#define	KERNBASE	0xc0000000
#define	KERNLOAD	0x400000
#define	KPSEL	0x8
#define	LA_EOI	0xb0
#define	LA_ISR	0x100
#define	MAXCOMLEN	0x13
#define	MAXPATHLEN	0x400
#define	MCLBYTES	0x800
#define	MD_LDT	0x0
#define	NFSDISKLESS_SIZE	0x224
#define	NPDEPG	0x400
#define	NPDEPTD	0x400
#define	NPGPTD	0x1
#define	NPTEPG	0x400
#define	PAGE_MASK	0xfff
#define	PAGE_SHIFT	0xc
#define	PAGE_SIZE	0x1000
#define	PCB_CR0	0x3c
#define	PCB_CR2	0x40
#define	PCB_CR3	0x44
#define	PCB_CR4	0x48
#define	PCB_DBREGS	0x2
#define	PCB_DR0	0x4c
#define	PCB_DR1	0x50
#define	PCB_DR2	0x54
#define	PCB_DR3	0x58
#define	PCB_DR6	0x5c
#define	PCB_DR7	0x60
#define	PCB_DS	0x28
#define	PCB_EBP	0x8
#define	PCB_EBX	0x10
#define	PCB_EDI	0x0
#define	PCB_EIP	0x14
#define	PCB_ESI	0x4
#define	PCB_ESP	0xc
#define	PCB_ES	0x2c
#define	PCB_EXT	0x84
#define	PCB_FLAGS	0x78
#define	PCB_FSD	0x18
#define	PCB_FS	0x30
#define	PCB_GDT	0x64
#define	PCB_GSD	0x20
#define	PCB_GS	0x34
#define	PCB_IDT	0x6c
#define	PCB_LDT	0x74
#define	PCB_ONFAULT	0x80
#define	PCB_PSL	0x88
#define	PCB_SAVEFPU	0x94
#define	PCB_SIZE	0xc0
#define	PCB_SS	0x38
#define	PCB_TR	0x76
#define	PCB_VM86CALL	0x10
#define	PCB_VM86	0x8c
#define	PC_COMMON_TSSD	0x270
#define	PC_COMMON_TSS	0x208
#define	PC_CPUID	0x20
#define	PC_CURPCB	0x10
#define	PC_CURPMAP	0x204
#define	PC_CURRENTLDT	0x280
#define	PC_CURTHREAD	0x0
#define	PC_FPCURTHREAD	0x8
#define	PC_FSGS_GDT	0x27c
#define	PC_IDLETHREAD	0x4
#define	PC_PRIVATE_TSS	0x28c
#define	PC_PRVSPACE	0x200
#define	PC_SIZEOF	0x400
#define	PC_TSS_GDT	0x278
#define	PDESHIFT	0x2
#define	PDESIZE	0x4
#define	PDRMASK	0x3fffff
#define	PDRSHIFT	0x16
#define	PMC_FN_USER_CALLCHAIN	0x9
#define	PM_ACTIVE	0x20
#define	PTESHIFT	0x2
#define	PTESIZE	0x4
#define	P_MD	0x2b8
#define	P_VMSPACE	0x130
#define	SIGF_HANDLER	0x10
#define	SIGF_UC	0x20
#define	TD0_KSTACK_PAGES	0x4
#define	TDF_ASTPENDING	0x800
#define	TDF_NEEDRESCHED	0x10000
#define	TDP_CALLCHAIN	0x400000
#define	TD_FLAGS	0x8c
#define	TD_LOCK	0x0
#define	TD_MD	0x2d0
#define	TD_PCB	0x27c
#define	TD_PFLAGS	0x94
#define	TD_PROC	0x4
#define	TD_TID	0x54
#define	TF_CS	0x38
#define	TF_EFLAGS	0x3c
#define	TF_EIP	0x34
#define	TF_ERR	0x30
#define	TF_TRAPNO	0x2c
#define	TSS_ESP0	0x4
#define	UC_EFLAGS	0x54
#define	UC_GS	0x14
#define	USRSTACK	0xbfbff000
#define	VM86_FRAMESIZE	0x58
#define	VM_MAXUSER_ADDRESS	0xbfc00000
#define	VM_PMAP	0xb8
#define	V_INTR	0xc
#define	V_SYSCALL	0x8
#define	V_TRAP	0x4
#endif
