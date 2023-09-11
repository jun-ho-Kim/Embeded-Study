#include <linux/kernel.h>
#include <linux/gpio.h>
#define OFF 0
#define ON 1

int gpioLed[] = {6,7,8,9,10,11,12,13};

char* gpioLedName[] = {"led0", "led1", "led2", "led3", "led4", "led5", "led6", "led7"};

asmlinkage long sys_mysyscall(long val)
{
	//printk(KERN_INFO "Welcome to KCCI's Embedded system!! app value=%ld\n",val);
	//return val*val;
	int ret = 0; 
	int i; 
	int gpioCnt;
	gpioCnt = sizeof(gpioLed)/sizeof(gpioLed[0]);

	for(i=0; i<gpioCnt; i++)
	{
			ret = gpio_request(gpioLed[i], gpioLedName[i]);
			if(ret < 0)
			{
		 		printk("Failed Request gpio%d error\n", 6);
				return ret;
			}

	}


	/*	
	
	for(i=0; i<gpio_direction_output(gpioLed[i], OFF), i++) 
	{
		
			
	}
	*/

	for(i=0; i<gpioCnt;i++)
	{
		gpio_set_value(gpioLed[i], (val>>i) & 0x01);
	}
	for(i=0; i<gpioCnt;i++) 
	{ 
		gpio_free(gpioLed[i]);
	}
	

	if(ret < 0) {
		printk("Failed direction_output gpio%d error\n", 6);
        return ret;
	}
    
	return val;
}
