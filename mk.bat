#!/bin/csh
make kernel KERNCONF=WYCVM
if ($? == 0) then
	cp /usr/obj/nfs/vm.FreeBSD/sys/WYCVM/kernel.debug 0_wyc
	if ($? == 0) then
		echo "*** kernel copied"
		echo "*** rebooting the machine ...."
		reboot
	endif
endif

