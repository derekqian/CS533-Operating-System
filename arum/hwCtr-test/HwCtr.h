#if !defined(HwCtr_h)
#define HwCtr_h

#include <linux/fs.h>

struct hwctr_dev {
   char events[1024];
   struct cdev hwctr_cdev;
} hdev;

static struct file_operations fops;

static int  
   HwCtr_init( void );

static void 
   HwCtr_finish( void );

static loff_t  
   d_llseek( struct file *filp, loff_t whence, int size );

static ssize_t 
   d_read ( struct file *filp, char *buf, size_t count, loff_t *whence );

static ssize_t 
   d_write ( struct file *filp, const char *buf, size_t count, loff_t *whence);

static int
   d_open  ( struct inode *inode, struct file *filp);

static int
   d_close ( struct inode *inode, struct file *filp);

static int
   d_ioctl (struct inode *i, struct file *f, unsigned int x, unsigned long y);

static unsigned long 
   get_cr4( void );

static int
   setup_cdev (struct hwctr_dev *dev);

#define DEVNAME		"HwCtr"
#ifndef HWCTR_NR_DEVS
#define HWCTR_NR_DEVS	1
#endif

#ifndef HWCTR_MAJOR
#define HWCTR_MAJOR	0
#endif

#define UNUSED		0
#define IN_USE		1
#define MAX_COUNTERS	32
#define MAX_EVENTS	64

#endif
