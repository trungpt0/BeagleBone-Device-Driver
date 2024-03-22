# Cross-compilie
1. make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-
# SSH
2. sudo rsync -avz *.ko debian@192.168.7.2:/home/debian
# Insert module BeagleBone Black
1. sudo insmod skeleton.ko
2. dmesg
3. sudo rmmod skeleton.ko