#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Trey Young");
MODULE_DESCRIPTION("A simple Linux kernel module");

// Define the proc_dir_entry struct of type *proc_entry
static struct proc_dir_entry *proc_entry;

// Define the proc_ops struct for the proc entry
// ssize_t	(*proc_read)(struct file *, char __user *, size_t, loff_t *);
static ssize_t proc_reader(struct file* filePointer, char __user *user_space_buffer, size_t count, loff_t* offset){
    printk("proc_reader called!\n");
    return 0; // Return 0 to indicate no data read
};

static struct proc_ops driver_proc_ops = {
    .proc_read = proc_reader,
};

static int trey_module_init(void) // returns an integer
{
    printk("init function has started!\n");
    
    // Create a proc entry named "trey_driver" in the /proc filesystem
    proc_entry = proc_create("trey_driver", 0, NULL, &driver_proc_ops);

    if (proc_entry == NULL){
        printk("Error creating proc entry!\n");
        return -1; // Return an error code if proc entry creation fails
    }
    printk("init function has finished!\n");
    return 0;
}

static void trey_module_exit(void) // returns void
{
    printk("exit function has started!\n");

    // Remove the proc entry created in the init function
    proc_remove(proc_entry);
    printk("Goodbye, world! This module has been unloaded!\n");
}

// Register the init and exit functions (load and unload module)
module_init(trey_module_init);
module_exit(trey_module_exit);