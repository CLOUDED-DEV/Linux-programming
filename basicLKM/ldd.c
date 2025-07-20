#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Trey Young");
MODULE_DESCRIPTION("A simple Linux kernel module");

static int trey_module_init(void) // returns an integer
{
    printk("Hello, world! This module has been loaded!\n");
    return 0;
}

static void trey_module_exit(void) // returns void
{
    printk("Goodbye, world! This module has been unloaded!\n");
}

// Register the init and exit functions (load and unload module)
module_init(trey_module_init);
module_exit(trey_module_exit);