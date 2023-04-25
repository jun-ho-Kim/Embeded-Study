#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//포인터 산술 연산  
	int arr[10];
	int num = sizeof(arr) / sizeof(arr[0]);
	
	for(int i = 0; i <num; ++i)
		arr[i] = (i+1) * 100;
	
	int* ptr = arr;
	
	printf("%p %p %p\n", ptr, arr, &arr[0]); // 000000000062FDE0 000000000062FDE0 000000000062FDE0
	
	ptr += 2;
	
	printf("%p %p %p\n", ptr, arr + 2, &arr[2]); // 000000000062FDE8 000000000062FDE8 000000000062FDE8
	
	printf("%d %d %d\n", *ptr + 1, *arr + 3, &arr[3]); // 301 103 6487532
	
	for(int i = 0, *ptr = arr; i<num; ++i)
	{
		printf("%u %d\n", *ptr++, arr[i]);
	}
	
	return 0;
}
