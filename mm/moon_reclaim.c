#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/swap.h>

static u64 get_mem_cgroup_moon_reclaim(struct cgroup_subsys_state *css,
		struct cftype *cft)
{
	return 0;
}

static int set_mem_cgroup_moon_reclaim(struct cgroup_subsys_state *css,
		struct cftype *cft, u64 value)
{
	struct mem_cgroup *memcg = mem_cgroup_from_css(css);
	unsigned long nr_to_reclaim = value, nr_reclaim = 0;

	nr_reclaim = try_to_free_mem_cgroup_pages(memcg,
		nr_to_reclaim, GFP_KERNEL, true);
	pr_info("[moon]: reclaim memory: %lu\n", nr_reclaim);

	return 0;
}

static struct cftype moon_files[] = {
	{
		.name = "moon_reclaim",
		.read_u64 = get_mem_cgroup_moon_reclaim,
		.write_u64 = set_mem_cgroup_moon_reclaim,
	},
	{ },	/* terminate */
};

static int __init moon_reclaim_init(void)
{
	cgroup_add_legacy_cftypes(&memory_cgrp_subsys, moon_files);
	pr_info("[moon]: create mem cgroup on memory.moon_reclaim\n");
	return 0;
}
module_init(moon_reclaim_init);
