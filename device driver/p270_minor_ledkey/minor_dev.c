#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/fs.h>          
#include <linux/errno.h>       
#include <linux/types.h>       
#include <linux/fcntl.h>       

#include <asm/uaccess.h>
#include <asm/io.h>

#define   MINOR_DEV_NAME        "minordev"
#define   MINOR_DEV_MAJOR            230
#define   MINOR_WRITE_ADDR        0x0378
#define   MINOR_READ_ADDR         0x0379


#include <linux/moduleparam.h>
#include <linux/gpio.h>
#define gpioName(a,b) #a#b     //"led""0" == "led0"
#define GPIOLEDCNT 8
#define GPIOKEYCNT 8
#define OFF 0
#define ON 1

int gpioLed[GPIOLEDCNT] = {6,7,8,9,10,11,12,13};
int gpioKey[GPIOKEYCNT] = {16,17,18,19,20,21,22,23};
static int onevalue = 1;
static char * twostring = NULL;
module_param(onevalue, int ,0);
module_param(twostring,charp,0);

int gpioLedInit(void);
void gpioLedSet(long);
void gpioLedFree(void);
int gpioKeyInit(void);
int gpioKeyGet(void);
void gpioKeyFree(void);

int	gpioLedInit(void)
{
	int i;
	int ret = 0;
	for(i=0;i<GPIOLEDCNT;i++)
	{
		ret = gpio_request(gpioLed[i], gpioName(led,i));
		if(ret < 0) {
			printk("Failed Request gpio%d error\n", 6);
			return ret;
		}
	}
	for(i=0;i<GPIOLEDCNT;i++)
	{
		ret = gpio_direction_output(gpioLed[i], OFF);
		if(ret < 0) {
			printk("Failed direction_output gpio%d error\n", 6);
       	 return ret;
		}
	}
	return ret;
}

void gpioLedSet(long val) 
{
	int i;
	for(i=0;i<GPIOLEDCNT;i++)
	{
		gpio_set_value(gpioLed[i], (val>>i) & 0x01);
	}
}
void gpioLedFree(void)
{
	int i;
	for(i=0;i<GPIOLEDCNT;i++)
	{
		gpio_free(gpioLed[i]);
	}
}

int gpioKeyInit(void) 
{
	int i;
	int ret=0;;
	for(i=0;i<GPIOKEYCNT;i++)
	{
		ret = gpio_request(gpioKey[i], gpioName(key,i));
		if(ret < 0) {
			printk("Failed Request gpio%d error\n", 6);
			return ret;
		}
	}
	for(i=0;i<GPIOKEYCNT;i++)
	{
		ret = gpio_direction_input(gpioKey[i]);
		if(ret < 0) {
			printk("Failed direction_output gpio%d error\n", 6);
       	 return ret;
		}
	}
	return ret;
}
int	gpioKeyGet(void) 
{
	int i;
	int ret;
	int keyData=0;
	for(i=0;i<GPIOKEYCNT;i++)
	{
		ret=gpio_get_value(gpioKey[i]) << i;
		keyData |= ret;
	}
	return keyData;
}
void gpioKeyFree(void) 
{
	int i;
	for(i=0;i<GPIOKEYCNT;i++)
	{
		gpio_free(gpioKey[i]);
	}
}

int minor0_open (struct inode *inode, struct file *filp)
{
    printk( "call minor0_open\n" );
    return 0;
}

ssize_t minor0_write (struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
    unsigned char status;    
    char kbuf[8];
    long ledVal=0;
    int i; 
    

    for( i = 0; i < count; i++ )
    {
        get_user( kbuf[i], buf++ ); 
        outb( status , MINOR_WRITE_ADDR );   
    }    
    for(i=7;i>=0;i--)
    {
        ledVal |= kbuf[i] << i;
    }
    printk("ledVal : %ld\n", ledVal);
    gpioLedSet(ledVal);
    return count;
}

int minor0_release (struct inode *inode, struct file *filp)
{
    printk( "call minor0_release\n" );    
    return 0;
}

int minor1_open (struct inode *inode, struct file *filp)
{
    printk( "call minor1_open\n" );
    return 0;
}

ssize_t minor1_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
    char kbuf[8]={0};
    long keyVal=0;
    int i;

     printk( "call read -> buf : %08X, count : %08X \n", (unsigned int)buf, count );

    unsigned char status;
    
    keyVal = gpioKeyGet();
    
    for( i = 0; i < count; i++ )
    {
        kbuf[i]=(keyVal >> i) * 0x01;
        printk("keyBuf[%d] : %d\n",i,kbuf[i]);
        status = inb( MINOR_READ_ADDR );
    }

    for( i = 0; i < count; i++ )
        put_user( kbuf[i], buf++ );

    return count;
}

int minor1_release (struct inode *inode, struct file *filp)
{
    printk( "call minor1_release\n" );
    return 0;
}

struct file_operations minor0_fops =
{
    .owner    = THIS_MODULE,
    .write    = minor0_write,
    .open     = minor0_open,
    .release  = minor0_release,
};

struct file_operations minor1_fops =
{
    .owner    = THIS_MODULE,
    .read     = minor1_read,
    .open     = minor1_open,
    .release  = minor1_release,
};

int minor_open (struct inode *inode, struct file *filp)
{
    printk( "call minor_open\n" );
    switch (MINOR(inode->i_rdev)) 
    {
    case 0: filp->f_op = &minor0_fops; break;
    case 1: filp->f_op = &minor1_fops; break;
    default : return -ENXIO;
    }
    
    if (filp->f_op && filp->f_op->open)
        return filp->f_op->open(inode,filp);
        
    return 0;
}

struct file_operations minor_fops =
{
    .owner    = THIS_MODULE,
    .open     = minor_open,     
};

int minor_init(void)
{
    int result;

    result = register_chrdev( MINOR_DEV_MAJOR, MINOR_DEV_NAME, &minor_fops);
    printk("test");
    if (result < 0) return result;

    result = gpioLedInit();
    if(result < 0)
        return -EBUSY;
    result = gpioKeyInit();
    if(result < 0)
        return result;

    return 0;
}

void minor_exit(void)
{
    unregister_chrdev( MINOR_DEV_MAJOR, MINOR_DEV_NAME );
}

module_init(minor_init);
module_exit(minor_exit);

MODULE_AUTHOR("KCCI-AIOT KSH");
MODULE_DESCRIPTION("led key test module");
MODULE_LICENSE("Dual BSD/GPL");
