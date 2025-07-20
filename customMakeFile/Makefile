obj-m += ldd.o ## append the module name to the list of modules to be built

all: ldd.c # compiles the source file specified
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

textInput: test.c
	cat test.c
	cat test.c > newFile.text
	cat newFile.text