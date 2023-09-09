#include <linux/kernel.h>
#include <linux/gpio.h> 
#define ON 1 
#define OFF 0 
void my_htob(char* ouput, char *input);
void rvereseArray(char arr[], int start, int end);

asmlinkage long sys_mysyscall(char val[])
{
//	printk(KERN_INFO "Welcome to ~val : %ld\n", val);
//	return val * val;
	int ret = 0;
	char input[5];
	int arr[9];
	ret = gpio_request(res_dec, "led0");
	printk("ret value is %d", ret);
	printk("val value is %s", val);	
	//nResult = kstrtol(val,16, res_dec);
//	printk("val pr2 value is %d:", 255);
	if(ret < 0) {
		printk("Failed Request gpio %d error", 6);
		return ret;
	}

//	ret=gpio_direction_output(res_dec, OFF);
	if(ret < 0) 
		printk("Failed Rdirection_output request gpio %d error", 6);
		return ret;
	}			
	
//	gpio_set_value(res_dec, 1);
	
	if(ret < 0) {
		printk("Failed  set_value gpio %d error", 6);
		return ret;
	}					
//j	gpio_free(res_dec);
//	free(a);


	for (int i = 0; i < 8; i++) {
		printk("%d", arr[i]);
	}
	printk("\n");

	rvereseArray(arr, 0, 7);
	printk("\n");
    for (int i = 0; i < 8; i++) {
        printk("%d", arr[i]);
    }

	puts("0:1:2:3:4:5:6:7\n");
	for (int i = 0; i<=7; i++)
	{
	   if(arr[i] == 0)
	   {
	       putc('O');
	       gpio_set_value(i+6, 0);
	   }
	   else
	   {
	       putc('X');
	       gpio_set_value(i+6, 1);
	   }

	   gpio_free(i+6);
	return 0;
}

void my_htob(char* ouput, char *input) {
	int n;
	printf("1 : %s\n", input);
	printf("1-1 : %c\n", *input);
	char *ptr = strtok(input, "x");
	ptr = strtok(NULL, " ");
	printf("2 : %d\n", ptr[0]);
	for(int i = 1; i >=0; i--)
	{
	    n = (int)ptr[i] - 48;
	    if (n > 9) n -= 7;
	    printf("n %d is %c\n", n, ptr[i]);
    	for (int j = (i+1)*4 -1; j >= i*4; j--) {

    		ouput[j] = (n % 2);
    		n /= 2;
    	}
	}
	//printf("output is %s\n", ouput);

}

void rvereseArray(char arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}  
