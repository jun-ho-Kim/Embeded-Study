#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/gpio.h>
#define CALL_DEV_NAME "ledkey_dev"
#define CALL_DEV_MAJOR 231

#define OFF 0
#define ON 1
#define GPIOLEDCNT 8
#define GPIOKEYCNT 8

int gpioLed[GPIOLEDCNT] = {6,7,8,9,10,11,12,13};
int gpioKey[GPIOKEYCNT] = {16,17,18,19,20,21,22,23};

void gpioLedFree(void);
void gpioKeyFree(void);

static int call_open(struct inode *inode, struct file *filp)
{
	int num = MINOR(inode->i_rdev);
	printk("call open-> minor : %d\n", num);
	num = MAJOR(inode->i_rdev);
	printk("call open -> major : %d\n", num);
	return 0;
}
static loff_t call_llseek(struct file *filp, loff_t off, int whence)
{
	printk("call llseek -> off : %08X, whence : %08X\n", (unsigned int)off, whence);
	return 0x23;
}
static ssize_t call_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
    int i;
    int ret;
    int keyData = 0;
    for(i=0;GPIOKEYCNT;i++)
    {
        ret=gpio_get_value(gpioKey[i]) << i;
        *buf |= ret;
    } 
	printk("call read -> buf: %08X, count : %08X \n", (unsigned int)buf, count);
	return 0x33;
}
static ssize_t call_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
    int i;
    printk("call_write *buf is %d\n", *buf);
    printk("call_write buf is %s\n", buf);
    int ret = (unsigned int)*buf;
    printk("call_write ret is %d\n", ret);
    for(i=0;i<GPIOLEDCNT;i++)
    {
        gpio_set_value(gpioLed[i], (ret>>i) & 0x01); 
    }
	printk("call write -> buf: %08X, count : %08X \n", (unsigned int)buf, count);
	return 0x43;
}
static long call_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	printk("call ioct1 -> cmd : %08X, arg: %08X\n", cmd, (unsigned int)arg);
	return 0x53;
}
static int call_release(struct inode *inode, struct file *filp)
{
    gpioLedFree();
    gpioKeyFree();

	printk("call release \n");

	return 0;
}
struct file_operations call_fops =
{
	.owner = THIS_MODULE,
	.llseek = call_llseek,
	.read = call_read,
	.write = call_write,
	.unlocked_ioctl = call_ioctl,
	.open = call_open,
	.release = call_release,
};
static int call_init(void)
{
	int result;
	printk("call call_init \n");
	result = register_chrdev(CALL_DEV_MAJOR, CALL_DEV_NAME, &call_fops);
	if(result < 0) return result;
	return 0;
}

static void call_exit(void)
{
	printk("call call_exit \n");
	unregister_chrdev(CALL_DEV_MAJOR, CALL_DEV_NAME);
}
module_init(call_init);
module_exit(call_exit);
MODULE_LICENSE("Dual BSD/GPL");
    
void gpioLedFree(void)
{
    int i;
    for(i=0; i<GPIOLEDCNT;i++)
    {
        gpio_free(gpioLed[i]);
    } 
}

void gpioKeyFree(void)
{
    int i;
    for(i=0; GPIOKEYCNT;i++)
    {
        gpio_free(gpioKey[i]);
    }
}
