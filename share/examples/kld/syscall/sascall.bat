#!/bin/tcsh

setenv SYSDIR /nfs/freebsd.wyc/sys

#cd /nfs/freebsd.wyc/share/examples/kld/syscall
make
kldunload ./module/sascall.ko
kldload   ./module/sascall.ko

