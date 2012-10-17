#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/spinlock.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

#include "HwCtr.h"

#if defined(CONFIG_MODVERSIONS)
#define MODVERSIONS
// #include <linux/modversions.h>
#endif

                            // "fops" contains the jump table
			    // used to access individual
			    // functions within this module.
static struct file_operations fops = {
    .owner   =  THIS_MODULE,
    .llseek  =  d_llseek,
    .read    =  d_read,
    .write   =  d_write,
    .open    =  d_open,
    .release =  d_close,
    .ioctl   =  d_ioctl,
};

			    // "major_dev" contains (after init)
			    // the major device number to be used
			    // to access this module.
//static int major_dev = 0;

			    // "beginning_of_time" represents
			    // the real time stamp value when
			    // counting began.
static long beginning_of_time = 0L;

			    // "counters" represents the state
			    // of the counters currently in use.
static struct {
    long  start;	    // rtc time at start of latest measurement
    short type;		    // type of event being counted
} counters [ CONFIG_NR_CPUS ][ MAX_COUNTERS ];

			    // "events" represents the 
			    // accumulation of events over time
			    // as measured by the counters.
static struct {
    long  count;	    // number of events recorded
    long  cycles;	    // events were recorded over this many CPU cycles
    short type;	            // type of event
} events [ CONFIG_NR_CPUS ][ MAX_COUNTERS ];


int hwctr_major		= HWCTR_MAJOR; 
int hwctr_minor		= 0;

module_param(hwctr_major, int, S_IRUGO);
module_param(hwctr_minor, int, S_IRUGO);


static int 
setup_cdev (struct hwctr_dev *dev)
{
   int err = 0;
   int devno = MKDEV (hwctr_major, hwctr_minor);
   cdev_init(&dev->hwctr_cdev, &fops);
   dev->hwctr_cdev.owner = THIS_MODULE;
   dev->hwctr_cdev.ops = &fops;
   err = cdev_add(&dev->hwctr_cdev, devno, 1);
   if (err < 0){
      printk (KERN_WARNING DEVNAME ": cdev add failed\n");
   }
   return err;
}

/*************
static int
HwCtr_init( void )
{
				// find the device major number to use
    int rv = register_chrdev( major_dev, DEVNAME, &fops );
    unsigned long cr4 = (unsigned long) get_cr4();
    if (rv < 0) {
	printk( KERN_INFO DEVNAME ": Registration failed.\n" );
	return rv;
    }
    if (major_dev == 0) major_dev = rv;

				// record the device major number so 
				// an appropriate device can be created
    printk( KERN_INFO DEVNAME ": Registered at major number %d.\n", major_dev );

    printk( KERN_INFO DEVNAME ": cr4 = 0x%16.16lx\n", cr4 );

    return 0;
}
******************/
static int
HwCtr_init(void)
{
    int rv;
    dev_t dev = 0;

    if (hwctr_major) {
        dev = MKDEV(hwctr_major, hwctr_minor);
        rv = register_chrdev_region (dev, HWCTR_NR_DEVS, DEVNAME);
    } else {
        rv =alloc_chrdev_region(&dev, hwctr_minor, HWCTR_NR_DEVS, DEVNAME);
        hwctr_major = MAJOR(dev);
    }    

    unsigned long cr4 = (unsigned long) get_cr4();
    if (rv < 0) {
        printk( KERN_INFO DEVNAME ": Registration failed.\n" );
        return rv;
    }
                                // record the device major number so
                                // an appropriate device can be created
    printk( KERN_INFO DEVNAME ": Registered at major number %d.\n", 
            hwctr_major );
    printk( KERN_INFO DEVNAME ": cr4 = 0x%16.16lx\n", cr4 );

                                //initialize hwctr_dev
    memset (&hdev, 0, HWCTR_NR_DEVS * sizeof(struct hwctr_dev));
    rv = 0;
    rv = setup_cdev (&hdev);
    if (rv < 0) {
       return rv;
    }
    return 0;
}


static void
HwCtr_finish( void )
{
    dev_t devno = MKDEV(hwctr_major, hwctr_minor);

                                // free up the device major number
                                // so some other module can use it.
    cdev_del (&hdev.hwctr_cdev);
    unregister_chrdev_region( devno, HWCTR_NR_DEVS);
    printk( KERN_INFO DEVNAME ": Deregistration (major=%d) succeeded.\n", 
            hwctr_major );
}


static loff_t
d_llseek( struct file *fp, loff_t whence, int size )
{
    return 0;
}

static ssize_t
d_read( struct file *filp, char *buf, size_t count, loff_t *whence )
{
    return 0;
}

static ssize_t
d_write( struct file *filp, const char *buf, size_t count, loff_t *whence )
{
    /* the user buffer, buf, contains a string indicating the hw perf counters
     * to set.  Returns the number of counters set.  Returns a negative number
     * if an error occurs.
     */

    char * kbuf;

    kbuf = kmalloc(count * sizeof(char *), GFP_KERNEL);
    if (!kbuf) {
       return -ENOMEM;
    }
    /* copy_from_user returns amount of memory still to be copied */
    if (copy_from_user(kbuf, buf, count)) {
       return -EFAULT;
    }

    printk(  KERN_WARNING DEVNAME ": counter string: %s\n", kbuf );
    
    return count;
}

				// "ctr_in_use" is used to ensure
				// only a single process may use
				// this module at any given time.
static volatile int ctr_in_use = UNUSED;

				// "use_lock" is used to protect
				// "ctr_in_use" from concurrent
				// access.
static spinlock_t use_lock = SPIN_LOCK_UNLOCKED; 

static int
d_open( struct inode *inode, struct file *filp )
{
				// only one user is allowed to 
				// use this module at a time...
				// so set the "in use" flag
    struct hwctr_dev * dev;
    dev = container_of (inode->i_cdev, struct hwctr_dev, hwctr_cdev);
    filp->private_data = dev;

    int rv = 0;
    spin_lock(&use_lock);
    if (ctr_in_use == UNUSED) {
	ctr_in_use = IN_USE;
        printk (KERN_WARNING DEVNAME ": d_open - got lock\n");
    } else {
	rv = -EBUSY;
        return rv;
    }
    spin_unlock(&use_lock);

    
    return rv;
}

static int
d_close( struct inode *inode, struct file *filp )
{
				// we're done with the module so...
				// clear the "in use" flag
    spin_lock(&use_lock);
    ctr_in_use = UNUSED;
    spin_unlock(&use_lock);

    return 0;
}

static int
d_ioctl(struct inode *i, struct file *f, unsigned int x, unsigned long y)
{
    return 0L;
}

static unsigned long
get_cr4( void )
{
    unsigned long cr4=0;

    __asm__ __volatile__
    (
	"mov %%cr4,%%rax;"
	"mov %%rax,%0;"
	:"=r"(cr4)
	:
	: "%rax" 
    );

    return cr4;
}

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Douglas M. Pase, IBM"); 
MODULE_DESCRIPTION("Application Resource Usage Monitor (Arum) -- Hardware counters"); 
MODULE_SUPPORTED_DEVICE(DEVNAME);

module_init(HwCtr_init);
module_exit(HwCtr_finish);



// CONFIG_NR_CPUS reflects the maximum number of CPUs the kernel can manage
// int kernel_thread(int (*fn)(void *), void * arg, unsigned long flags)
// cpu_online()
// smp_processor_id()
// interruptible_sleep_on_timeout()
// set_cpus_allowed()

