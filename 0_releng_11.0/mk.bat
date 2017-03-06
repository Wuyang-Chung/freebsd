#!/bin/csh

sntp -S tw.pool.ntp.org; if ($? != 0) goto error

cd /nfs/vm.FreeBSD; if ($? != 0) goto error
make kernel KERNCONF=WYCVM; if ($? != 0) goto error
cp /usr/obj/nfs/vm.FreeBSD/sys/WYCVM/kernel.debug .
if ($? == 0) echo "*** kernel copied"
echo "*** rebooting the machine ...."
reboot

error:
echo "*** error"

