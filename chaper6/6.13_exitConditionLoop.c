//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int secret_code;
	int guess = 0;

	do 
	{
		printf("Enter secret code : ");
		scanf("%d", &guess);
	} while (guess != 1234);
	printf("Good");
	
	//for (; secret_code != 1234; scanf("%d", &secret_code)) {
	//	printf("Enter secret code : ");
	//}
	
	return 0;
}