#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>

/**
 * Module Information
*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("trungpt0");
MODULE_DESCRIPTION("Dynamically allocating the Major and Minor number");
MODULE_VERSION("1.0");

// Creating a devive
dev_t dev = 0;
/**
 * Module initialization function
*/
static int __init dyna_alloc_init(void)
{
    // Allocating Major number
    if ((alloc_chrdev_region(&dev, 0, 1, "PTS_Device")) != 0) {
        pr_info("Cannot allocating Major number for device\n");
        return -1;
    }

    pr_info("Major = %d Minor = %d", MAJOR(dev), MINOR(dev));
    pr_info("Kernel Module Inserted Successfully!\n");

    return 0;
}

/**
 * Module exit function
*/
static void __exit dyna_alloc_exit(void)
{
    unregister_chrdev_region(dev, 1);
    pr_info("Kernel Module Removed Successfully!\n");
}

/**
 * Register initialization and exit functions of the module
*/
module_init(dyna_alloc_init);
module_exit(dyna_alloc_exit);