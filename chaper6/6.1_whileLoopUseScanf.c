//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//강의 코드
	int num, sum = 0;

	printf("Enter an integer (q to quit) : ");
	// status = scanf("%d", &num); //scanf() 함수의 리턴값은 입력 받은 값의 개수를 return
	while (scanf("%d", &num) == 1) {
		sum += num;
		printf("Enter next integer (q to quit) : ");
	}
	printf("Sum = %d", sum);

	/* 내가 짠 코드
	char num;
	int sum;

	printf("Enter an integer (q to quit) : ");
	scanf("%d", &num);
	
	while (num != (char)113) {
		sum += (int)num;
		printf("Enter nex integer (q to quit) :");
		scanf("%d", &num);
	}
	printf("Sum = %d", sum);
	*/
	return 0;
}