#!/bin/csh
make kernel KERNCONF=WYCVM
if ($? == 0) then
	cp /usr/obj/nfs/freebsd-vm/sys/WYCVM/kernel.debug 0_wyc
	if ($? == 0) then
		reboot
	endif
endif

