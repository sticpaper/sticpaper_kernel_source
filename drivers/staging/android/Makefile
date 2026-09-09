# SPDX-License-Identifier: GPL-2.0
ccflags-y += -I$(src)			# needed for trace events

obj-y					+= ion/
ifdef CONFIG_MOON_COMMON_KERNEL
obj-$(CONFIG_ASHMEM)			+= moon_ashmem.o
else
obj-$(CONFIG_ASHMEM)			+= ashmem.o
endif
obj-$(CONFIG_DEBUG_KINFO)	+= debug_kinfo.o
