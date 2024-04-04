# Cross-compilie
1. $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
# SSH
2. $ sudo rsync -avz *.ko debian@192.168.7.2:/home/debian
# Insert module BeagleBone Black
1. $ sudo insmod dyna_major_minor.ko
2. $ dmesg
3. $ cat /proc/devices | grep PTS_Device
4. sudo rmmod dyna_major_minor