#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>          
#include <linux/errno.h>       
#include <linux/types.h>       
#include <linux/fcntl.h>       
#include <linux/moduleparam.h>
#include <linux/gpio.h>

#define CALL_DEV_NAME	"calldev"
#define CALL_DEV_MAJOR	230      
#define gpioName(a,b) 	#a#b     //"led""0" == "led0"
#define GPIOLEDCNT		8
#define GPIOKEYCNT 		8
#define OFF				0
#define ON				1

static int gpioLed[GPIOLEDCNT] = {6,7,8,9,10,11,12,13};
static int gpioKey[GPIOKEYCNT] = {16,17,18,19,20,21,22,23};
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
int call_open (struct inode *inode, struct file *filp)
{
    int num0 = MAJOR(inode->i_rdev); 
    int num1 = MINOR(inode->i_rdev); 
    printk( "call open -> major : %d\n", num0 );
    printk( "call open -> minor : %d\n", num1 );

    return 0;
}

loff_t call_llseek (struct file *filp, loff_t off, int whence )
{
    printk( "call llseek -> off : %08X, whenec : %08X\n", (unsigned int)off, whence );
    return 0x23;
}

ssize_t call_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	char kbuf[8]={0};
	long keyVal=0;
//	int ret;
	int i;
    printk( "call read -> buf : %08X, count : %08X \n", (unsigned int)buf, count );
	keyVal = gpioKeyGet();
	for(i=0;i<count;i++)
    {
        kbuf[i] = (keyVal >> i) & 0x01;
		printk("keyBuf[%d] : %d\n",i,kbuf[i]);
    }


	for(i=0;i<count;i++)
		put_user(kbuf[i],buf++);
//	ret=copy_to_user(buf,kbuf,count);
    return count;
}

ssize_t call_write (struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	char kbuf[8];
	long ledVal=0;
//	int ret;
	int i;

    printk( "call write -> buf : %08X, count : %08X \n", (unsigned int)buf, count );
	for(i=0;i<count;i++)
  		get_user(kbuf[i],buf++);
//	ret=copy_from_user(kbuf,buf,count);
	for(i=7;i>=0;i--)
	{
		ledVal |= kbuf[i] << i; 
	}
	printk("ledVal : %ld\n",ledVal);
	gpioLedSet(ledVal);
    return count;
}

//int call_ioctl (struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
static long call_ioctl (struct file *filp, unsigned int cmd, unsigned long arg)
{

    printk( "call ioctl -> cmd : %08X, arg : %08X \n", cmd, (unsigned int)arg );
    return 0x53;
}

int call_release (struct inode *inode, struct file *filp)
{
    printk( "call release \n" );
    return 0;
}

struct file_operations call_fops =
{
    .owner    = THIS_MODULE,
    .open     = call_open,     
    .read     = call_read,     
    .write    = call_write,    
	.unlocked_ioctl = call_ioctl,
    .llseek   = call_llseek,   
    .release  = call_release,  
};

int call_init(void)
{
    int result;

    printk( "call call_init \n" );    

    result = register_chrdev( CALL_DEV_MAJOR, CALL_DEV_NAME, &call_fops);
    if (result < 0) return result;

	result = gpioLedInit();
	if(result < 0)
//		return result;
  		return -EBUSY;
	result = gpioKeyInit();
	if(result < 0)
		return result;

    return 0;
}

void call_exit(void)
{
    printk( "call call_exit \n" );    
    unregister_chrdev( CALL_DEV_MAJOR, CALL_DEV_NAME );
	gpioLedSet(0);
	gpioLedFree();
	gpioKeyFree();
}

module_init(call_init);
module_exit(call_exit);

MODULE_AUTHOR("KCCI-AIOT KSH");
MODULE_DESCRIPTION("led key test module");
MODULE_LICENSE("Dual BSD/GPL");
