#Linux Driver Development 

This section is for example modules made after Linux Driver Development, Third edition book.


* [Hello module](hello_module/) from chapter 2 "Building and Running Modules"

Very simple module that prints "Hello" to dmesg after module has been loaded and "Bye"  and current process info after module unloaded.
To build it use make with kernel make extention:
```sh
make -C /usr/src/linux-headers-`uname -r`/ M=`pwd`  clean
```
Probably you will need to install your current linux kernel headers if they are not present on the system:
```sh
sudo apt get install linux-headers-`uname -r`
```

To load/unload module use insmod and rmmod commands:
```sh
insmod ./hello.ko
rmmod hello
```




