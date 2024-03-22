#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("trungnpt0");
MODULE_DESCRIPTION("A skeleton device driver");

static int __init skeleton_init(void)
{
    pr_info("Hello World!\n");
    pr_info("Kernel Module Inserted Successfully!\n");
    return 0;
}

static void __exit skeleton_exit(void)
{
    pr_info("Goodbye!\n");
    pr_info("Kernel Module Removed Successfully!\n");
}

module_init(skeleton_init);
module_exit(skeleton_exit);