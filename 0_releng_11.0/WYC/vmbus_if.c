/*
 * This file is produced automatically.
 * Do not modify anything in here by hand.
 *
 * Created from source file
 *   /nfs/vm.FreeBSD/sys/dev/hyperv/vmbus/vmbus_if.m
 * with
 *   makeobjops.awk
 *
 * See the source file for legal information
 */

#include <sys/param.h>
#include <sys/queue.h>
#include <sys/kernel.h>
#include <sys/kobj.h>
#include <sys/param.h>
#include <sys/bus.h>
#include "vmbus_if.h"

struct kobjop_desc vmbus_get_version_desc = {
	0, { &vmbus_get_version_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc vmbus_probe_guid_desc = {
	0, { &vmbus_probe_guid_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc vmbus_get_vcpu_id_desc = {
	0, { &vmbus_get_vcpu_id_desc, (kobjop_t)kobj_error_method }
};

struct kobjop_desc vmbus_get_event_taskq_desc = {
	0, { &vmbus_get_event_taskq_desc, (kobjop_t)kobj_error_method }
};

