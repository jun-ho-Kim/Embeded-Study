#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/gpio.h>
#include <linux/moduleparam.h>

#define CALL_DEV_NAME   "kerneltimer_dev"   
#define CALL_DEV_MAJOR  230
#define gpioName(a,b)   #a#b     //"led""0" == "led0"
#define GPIOLEDCNT      8
#define GPIOKEYCNT      8
#define OFF             0
#define ON              1
#define DEBUG           1

static int timerVal = 100;	//f=100HZ, T=1/100 = 10ms, 100*10ms = 1Sec
module_param(timerVal,int ,0);
static int ledVal = 0;
module_param(ledVal,int ,0);
struct timer_list timerLed;

void kerneltimer_timeover(unsigned long arg);
void kerneltimer_func(struct timer_list *t);
int gpioLed[GPIOLEDCNT] = {6,7,8,9,10,11,12,13};
int gpioKey[GPIOKEYCNT] = {16,17,18,19,20,21,22,23};

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
int gpioKeyGet(void)
{
    int i;
    int ret;
    int keyData=0;
    for(i=0;i<GPIOKEYCNT;i++)
    {
        ret=gpio_get_value(gpioKey[i]) << i;
        keyData |= ret;
    }
    ledVal = keyData;
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
void kerneltimer_registertimer(unsigned long timeover)
{
	timer_setup( &timerLed,kerneltimer_func,0);
	timerLed.expires = get_jiffies_64() + timeover;  //10ms *100 = 1sec
	add_timer( &timerLed );
}
void kerneltimer_func(struct timer_list *t)
{
    timerVal=100;
	gpioLedSet(ledVal);
#if DEBUG
	printk("ledVal : %#04x\n",(unsigned int)(ledVal));
#endif
	//ledVal = ~ledVal & 0xff; 
    ledVal = ledVal& 0xff;
	gpioLedSet(ledVal);
    mod_timer(t,get_jiffies_64() + timerVal);
}

int call_open(struct inode *inode, struct file *filp)
{
    int num0 = MAJOR(inode->i_rdev);
    int num1 = MINOR(inode->i_rdev);
    printk( "call open -> major : %d\n", num0 );
    printk( "call open -> minor : %d\n", num1 );
    
    return 0;
}

ssize_t call_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
    printk( "call read -> buf : %08X, count : %08X \n", (unsigned int)buf, count );
    *buf=gpioKeyGet();
    
    return count;
}

ssize_t call_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
    timerVal = 100;
    printk( "call read -> buf : %08X, count : %08X \n", (unsigned int)buf, count );
    gpioLedSet(*buf);
#if DEBUG
	printk("timerVal : %d , sec : %d \n",timerVal,timerVal/HZ );
#endif
	kerneltimer_registertimer(timerVal);
    return count;
}

ssize_t call_release(struct inode *inode, struct file *filp)
{
    printk("call release \n");
    return 0;
}


struct file_operations call_fops =
{
    .owner = THIS_MODULE,
    .open = call_open,
    .read = call_read,
    .write = call_write,
    .release = call_release,
};

int kerneltimer_init(void)
{
    int result;
    printk("call call_init \n");

    result = register_chrdev(CALL_DEV_MAJOR, CALL_DEV_NAME, &call_fops);
    if(result < 0) return result;

	gpioLedInit();
    gpioKeyInit();

	return 0;
}
void kerneltimer_exit(void)
{
    printk("ledkeydev ledkeydev_exit \n");
	if(timer_pending(&timerLed))
		del_timer(&timerLed);
    unregister_chrdev(CALL_DEV_MAJOR, CALL_DEV_NAME);
	gpioLedSet(0);
    gpioLedFree();
    gpioKeyFree();
}
module_init(kerneltimer_init);
module_exit(kerneltimer_exit);
MODULE_AUTHOR("KCCI-AIOT KSH");
MODULE_DESCRIPTION("led key test module");
MODULE_LICENSE("Dual BSD/GPL");
