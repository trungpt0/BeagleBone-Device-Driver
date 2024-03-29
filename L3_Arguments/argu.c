#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

/**
 * Module Information
*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("trungpt0");
MODULE_DESCRIPTION("A passing arguments device driver");
MODULE_VERSION("1.0");

/**
 * Declaration of necessary parameters for the module
*/
static int value;                   // Integer parameter
static char *name;         // String parameter
static int arr_value[4];                // Array of integer parameters
static int callback_value = 0;          // Callback integer parameter

module_param(value, int, S_IRUSR | S_IWUSR);
module_param(name, charp, S_IRUSR | S_IWUSR);
module_param_array(arr_value, int, NULL, S_IRUSR | S_IWUSR);

/**
 * Callback function to notify when the callback parameter changes
*/
static int notify_param(const char *val, const struct kernel_param *kp)
{
    int res = param_set_int(val, kp);   // User helper function for variable setting
    if (res == 0) {
        pr_info("Callback function called!\n");
        pr_info("New value of callback_value = %d\n", callback_value);
        return 0;
    }
    return -1;
}

/**
 * Kernel_param_ops structure to define callback function
*/
static const struct kernel_param_ops my_param_ops =
{
    .set = &notify_param,
    .get = &param_get_int,
};

/**
 * Register callback function and callback parameter
*/
module_param_cb(callback_value, &my_param_ops, &callback_value, S_IRUGO | S_IWUSR);

/**
 * Module initialization function
*/
static int __init argu_init(void)
{
    int i;

    pr_info("value = %d\n", value);
    pr_info("name = %s\n", name);
    pr_info("callback_value = %d\n", callback_value);

    for (i = 0; i < ARRAY_SIZE(arr_value); i++) {
        pr_info("arr_value[%d] = %d\n", i, arr_value[i]);
    }

    pr_info("Kernel Module Inserted Successfully!\n");
    return 0;
}

/**
 * Module exit function
*/
static void __exit argu_exit(void)
{
    pr_info("Kernel Module Removed Successfully!\n");
}

/**
 * Register initialization and exit functions of the module
*/
module_init(argu_init);
module_exit(argu_exit);