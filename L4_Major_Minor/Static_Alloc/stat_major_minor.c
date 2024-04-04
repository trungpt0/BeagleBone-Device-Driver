#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>

/**
 * Module Information
*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("trungpt0");
MODULE_DESCRIPTION("Statically allocating the Major and Minor number");
MODULE_VERSION("1.0");

// Creating the devive with major and minor number
dev_t dev = MKDEV(235, 0);

/**
 * Module initialization function
*/
static int __init stat_alloc_init(void)
{
    register_chrdev_region(dev, 1, "PTS_Device");
    pr_info("Major = %d Minor = %d", MAJOR(dev), MINOR(dev));
    pr_info("Kernel Module Inserted Successfully!\n");
    return 0;
}

/**
 * Module exit function
*/
static void __exit stat_alloc_exit(void)
{
    unregister_chrdev_region(dev, 1);
    pr_info("Kernel Module Removed Successfully!\n");
}

/**
 * Register initialization and exit functions of the module
*/
module_init(stat_alloc_init);
module_exit(stat_alloc_exit);