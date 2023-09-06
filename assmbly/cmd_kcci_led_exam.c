#include <common.h>
#include <command.h>
#include <asm/io.h>

#define BCM2711_GPIO_GPFSEL0 	0xFE200000 	
#define BCM2711_GPIO_GPFSEL1 	0xFE200004 
#define BCM2711_GPIO_GPFSEL2 	0xFE200008 
#define BCM2711_GPIO_GPSET0 	0xFE20001C
#define BCM2711_GPIO_GPCLR0 	0xFE200028
#define BCM2711_GPIO_GPLEV0 	0xFE200034
#define GPIO6_9_SIG_OUTPUT 		0x09240000	//gpio6~9 output
//#define GPIO10_13_SIG_OUTPUT 	0x00012249  //txd,rxd
#define GPIO10_13_SIG_OUTPUT 	0x00000249 	//gpio10~13 output 
#define GPIO6_13_SET_CLR_BIT    0x00003fc0

void led_init(void)
{
	unsigned long temp;
	temp = readl(BCM2711_GPIO_GPFSEL0);		//read
	printf("led_init tmp %ld\n", temp);
//	temp = temp & 0xc003ffff;				//clear
	temp = temp & ~0x3ffc0000;				//gpio6~9 clear	

	printf("tmp 1 %ld\n", temp);
	temp = temp | GPIO6_9_SIG_OUTPUT;		//modify
	
	printf("tmp 2 %ld\n", temp);
	writel(temp,BCM2711_GPIO_GPFSEL0);		//write 	

	printf("tmp write 1 %ld\n", temp);
	
	temp = readl(BCM2711_GPIO_GPFSEL1);
	
	printf("tmp 3 %ld\n", temp);
//	temp = temp & 0xfffff000;
	temp = temp & ~0x00000fff;				//gpio10~13 clear
	
	printf("tmp 4 %ld\n", temp);
	temp = temp | GPIO10_13_SIG_OUTPUT;
	printf("tmp 5 %ld\n", temp);
	writel(temp,BCM2711_GPIO_GPFSEL1);  
	printf("tmp write 2 %ld", temp);	
}
void led_write(unsigned long led_data)  //led_data : 0x00~0xff
{
	
	printf("led data 1 %ld", led_data);
	writel(GPIO6_13_SET_CLR_BIT, BCM2711_GPIO_GPCLR0); 	//led0~7 all off
	led_data = led_data << 6;

	printf("led data 2 %ld", led_data);
	writel(led_data, BCM2711_GPIO_GPSET0);  //ledX on
}
void key_init(void)
{
	writel(0x00ff, BCM2711_GPIO_GPLEV0);
}
void key_read(unsigned long *key_data)
{
	unsigned long tmp; 
	tmp = key_data && 0x00ff;	
	printf("key read tmp is %ld", tmp);
	key_read <<10;		
	printf("key read is %ld", tmp);
	
	
		
}
static int do_KCCI_LED(struct cmd_tbl *cmdtp,int flag, int argc, char * const argv[])
{
	unsigned long led_data;
  	if(argc != 2)
	{
		cmd_usage(cmdtp);
		return 1;
	}
	printf("*LED TEST START\n");
  	led_init();
	key_init();
	//key_init();
	led_data = simple_strtoul(argv[1],NULL,16);
  	led_write(led_data);

	
	do {
	unsigned long read_key;

	read_key = readl(BCM2711_GPIO_GPLEV0);
	printf("read key is %d", (unsigned int)read_key);
	key_read(&read_key);		
	
	} while (1);
	
	printf("*LED TEST END(%s : %#04x)\n\n ",argv[0],(unsigned int)led_data);
	return 0;
}
U_BOOT_CMD(
	led,2,0,do_KCCI_LED,
	"kcci LED Test.",
	"number - Input argument is only one.(led [0x00~0xff])\n");
