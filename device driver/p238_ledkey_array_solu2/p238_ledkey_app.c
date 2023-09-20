#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_FILENAME  "/dev/ledkey_dev"

void print_led(unsigned char);
void print_key(unsigned char);
int main(int argc,char * argv[])
{
    int dev;
    char ledBuff[8] = {0};
    char keyBuff[8] = {0};
	unsigned long ledVal;
	unsigned long keyVal=0;
	char oldBuff = 0;
    int ret;
	int i;
	if(argc < 2)
	{
		printf("USAGE : %s [ledval] \n",argv[0]);
		return 1;
	}
	ledVal = strtoul(argv[1],0,16);
	for(i=0;i<8;i++)
	{
		ledBuff[i] = (ledVal >> i) & 0x01;	
		printf("ledBuff[%d] : %d\n",i,ledBuff[i]);
	}
    dev = open( DEVICE_FILENAME, O_RDWR|O_NDELAY );
	if(dev<0)
	{
		perror("open()");
		return 2;
	}
    ret = write(dev,ledBuff,sizeof(ledBuff));
	if(ret < 0)
	{
		perror("write()");
		return 3;
	}
	print_led(ledVal);

	do {
		keyVal = 0;
		read(dev,keyBuff,sizeof(keyBuff));
    	for(i=7;i>=0;i--)
    	{
       		keyVal |= keyBuff[i] << i;
    	}
//		printf("keyVal : %ld\n",keyVal);
		if((keyVal != 0) && (oldBuff != keyVal))
		{
			printf("key : %ld\n",keyVal);
			print_key(keyVal);
    		write(dev,keyBuff,sizeof(keyBuff));
//			print_led(keyVal);
			oldBuff = keyVal;
			if(keyVal == 128) //key:8
				break;
		}
	} while(1);

    close(dev);
    return 0;
}
void print_led(unsigned char led)
{
	int i;
	puts("1:2:3:4:5:6:7:8");
	for(i=0;i<=7;i++)
	{
		if(led & (0x01 << i))
			putchar('O');
		else
			putchar('X');
		if(i < 7 )
			putchar(':');
		else
			putchar('\n');
	}
	return;
}

void print_key(unsigned char key)
{
	int i;
	puts("1:2:3:4:5:6:7:8");
	for(i=0;i<=7;i++)
	{
		if(key & (0x01 << i))
			putchar('O');
		else
			putchar('X');
		if(i < 7 )
			putchar(':');
		else
			putchar('\n');
	}
	return;
}
