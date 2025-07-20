# This Makefile is used to compile the ldd kernel module
obj-m += ldd.o ## append the module name to the list of modules to be built

# The all target builds the module using the kernel build system
all: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# The clean target cleans up the build artifacts (removes modules)
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean