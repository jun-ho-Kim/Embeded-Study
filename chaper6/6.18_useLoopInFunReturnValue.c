//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 사용할 때 scope 개념 잘 알기
// 아래와 같이 함수를 정의해주는 것을 프로토타입이라고 한다.
int compute_pow(int base, int exp);

int main()
{
	int base, exp, result;

	while (scanf("%d %d", &base, &exp)== 2)
	{
		result = compute_pow(base, exp);

		printf("Result = %d\n", result);
	}

	return 0;
}

int compute_pow(int base, int exp)
{
	int i, result;

	result = 1;

	for (i = 0; i < exp; i++) {
		result *= base;
	}

	return result;
}