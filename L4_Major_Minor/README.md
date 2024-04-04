# Introduce
In the realm of computer systems, device drivers play a crucial role in facilitating communication between hardware devices and the operating system. Major and Minor device drivers are key components of this infrastructure.

Major and minor device drivers often work together in a hierarchical fashion. When the operating system interacts with a particular device, it first invokes the major device driver associated with that device class. The major driver then delegates specific tasks to the appropriate minor driver based on the device instance being accessed.

This modular approach allows for efficient management of diverse hardware configurations while maintaining a unified interface for the operating system and applications.

# How do Applications communicate with Hardware?
Applications <-> Device File <-> Major Minor Number <-> Device Driver <-> Hardware

# Allocating Major and Minor Number

## Statically Allocating

### Function register device number:
int register_chrdev_region(dev_t dev, unsigned int num, char *name);
- dev: Your device number MKDEV(int major, int minor); MAJOR(dev_t dev); MINOR(dev_t dev);
- num: Number of contigous device numbers you want to register
- name: Your name device number, it will be appear in /proc/devices

### Function unregister device number:
void register_chrdev_region(dev_t dev, unsigned int num);
- dev: Your device number
- num: num: Number of contigous device numbers you want to unregister

## Dynamically Allocating

### Function register device number:
int alloc_chrdev_region(dev_t *dev, unsigned int minor, unsigned int num, char *name);
- dev: Your device number
- minor: Minor number to use, it's usually 0
- num: Number of contigous device numbers you want to register
- name: Your name device number, it will be appear in /proc/devices

### Function unregister device number:
void register_chrdev_region(dev_t dev, unsigned int num);
- dev: Your device number
- num: num: Number of contigous device numbers you want to unregister