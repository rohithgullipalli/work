#target & input files
obj-m :=chdrv.o

#variable/macro to hold kernel-headers/kerbel-source directory path
KDIR= /lib/modules/$(shell uname -r)/build

#command to convert input files into desired target
#this command uses kbuild scripts of kernel-header/source folder specified

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean: 
	$(MAKE) -C $(KDIR) M=$(PWD) clean
