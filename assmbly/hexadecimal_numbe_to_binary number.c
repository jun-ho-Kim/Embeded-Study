#include <stdio.h>
#include <string.h>

void my_htob(char* ouput, char* input) {
	int n;
	printf("1 : %s\n", input);
	printf("1-1 : %c\n", *input);
	char* ptr = strtok(input, "x");
	ptr = strtok(NULL, " ");
	printf("2 : %d\n", ptr[0]);
	for (int i = 1; i >= 0; i--)
	{
		n = (int)ptr[i] - 48;
		if (n > 9) n -= 7;
		printf("n %d is %c\n", n, ptr[i]);
		for (int j = (i + 1) * 4 - 1; j >= i * 4; j--) {

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


int main() {
	char input[5];
	int arr[50001];

	scanf("%s", input);

	my_htob(arr, input);

	for (int i = 0; i < 8; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");

	rvereseArray(arr, 0, 7);
	printf("\n");
	for (int i = 0; i < 8; i++) {
		printf("%d", arr[i]);
	}

	puts("0:1:2:3:4:5:6:7\n");
	for (int i = 0; i <= 7; i++)
	{
		if (arr[i] == 0)
		{
			putc('O');
			gpio_set_value(i + 6, 0);
		}
		else
		{
			putc('X');
			gpio_set_value(i + 6, 1);
		}

		//gpio_free(i + 6)
	}



	//printf("reverse is %d", arr[i]);
	return 0;
}