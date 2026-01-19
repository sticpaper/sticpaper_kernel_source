// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/miscdevice.h>
#include <linux/mman.h>

static int set_metis_dummy(const char *buf, const struct kernel_param *kp)
{
	return 0;
}

static int get_metis_dummy(char *buf, const struct kernel_param *kp)
{
	return 0;
}

static const struct kernel_param_ops ops_metis_dummy = {
	.set = set_metis_dummy,
	.get = get_metis_dummy,
};

/* set metis viptask moduleparam ops */
module_param_cb(add_mi_viptask_enqueue_boost, &ops_metis_dummy, NULL, 0644);
module_param_cb(del_mi_viptask_enqueue_boost, &ops_metis_dummy, NULL, 0644);
module_param_cb(add_mi_viptask_sched_lit_core, &ops_metis_dummy, NULL, 0644);
module_param_cb(del_mi_viptask_sched_lit_core, &ops_metis_dummy, NULL, 0644);
module_param_cb(add_mi_viptask_sched_priority, &ops_metis_dummy, NULL, 0644);
module_param_cb(del_mi_viptask_sched_priority, &ops_metis_dummy, NULL, 0644);

/* set metis opt-other moduleparam ops */
module_param_cb(metis_viptask, &ops_metis_dummy, NULL, 0644);
module_param_cb(min_cluster_freqs, &ops_metis_dummy, NULL, 0644);
module_param_cb(user_min_freq, &ops_metis_dummy, NULL, 0644);

/* set metis userspace moduleparam ops */
module_param_cb(fperiod, &ops_metis_dummy, NULL, 0644);
module_param_cb(in_perf_mod, &ops_metis_dummy, NULL, 0644);
module_param_cb(mi_boost_duration, &ops_metis_dummy, NULL, 0644);
module_param_cb(limit_bgtask_sched, &ops_metis_dummy, NULL, 0644);
module_param_cb(is_break_enable, &ops_metis_dummy, NULL, 0644);

/* set metis feature moduleparam ops */
module_param_cb(mi_freq_enable, &ops_metis_dummy, NULL, 0644);
module_param_cb(mi_link_enable, &ops_metis_dummy, NULL, 0644);
module_param_cb(mi_switch_enable, &ops_metis_dummy, NULL, 0644);
module_param_cb(mi_fboost_enable, &ops_metis_dummy, NULL, 0644);
module_param_cb(mpc_fboost_enable, &ops_metis_dummy, NULL, 0644);
module_param_cb(thermal_break_enable, &ops_metis_dummy, NULL, 0644);
module_param_cb(vip_link_enable, &ops_metis_dummy, NULL, 0644);

static int metis_open(struct inode *inode, struct file *file)
{
	return 0;
}

static int metis_release(struct inode *ignored, struct file *file)
{
	return 0;
}

static int metis_mmap(struct file *file, struct vm_area_struct *vma)
{
	return 0;
}

static long metis_ioctl(struct file *fp, unsigned int cmd,
				 unsigned long arg)
{
	return 0;
}

static const struct file_operations metis_fops = {
	.owner = THIS_MODULE,
	.open = metis_open,
	.release = metis_release,
	.mmap = metis_mmap,
	.unlocked_ioctl = metis_ioctl,
};

static struct miscdevice metis_misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "metis",
	.fops = &metis_fops,
};

static int xiaomi_metis_init(void)
{
	misc_register(&metis_misc);
	return 0;
}
late_initcall(xiaomi_metis_init);
