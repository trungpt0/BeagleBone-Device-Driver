# Setup BeagleBone Black Cross Compile

## Setup host
- First, let's install the package to build.
 $ sudo apt-get install build-essential gcc-arm-linux-gnueabi git lzop u-boot-tools bison flex libssl-dev libncurses-dev sshfs lzma gettext libmpc-dev libncurses5-dev:amd64
- Create a new directory BBB.
 $ mkdir ~/BBB
 $ cd ~/BBB
 - Clone Linux kernel to build.
 $ git clone git://github.com/beagleboard/linux.git
 $ cd linux/
 $ git checkout "your board's linux version"

## Linux Kernel Cross Compilation
 $ make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- bb.org_defconfig
 $ make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- menuconfig
 $ make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- LOADADDR=0x80000000 uImage dtbs
 $ make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- LOADADDR=0x80000000 uImage dtbs
 $ mkdir ../tmp/
 $ make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- INSTALL_MOD_STRIP=1 INSTALL_MOD_PATH=../tmp modules_install

# Congratulation!