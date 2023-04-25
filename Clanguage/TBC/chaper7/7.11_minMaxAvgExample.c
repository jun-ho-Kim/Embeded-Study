//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>
#include <ctype.h>

int main()
{
	float min = FLT_MAX;
	float max = -FLT_MAX;
	float sum = 0.0f;
	float input;

	int n = 0;

	//getchar()로 입력 값을 받아오면 숫자를 아스키코드로 변경해서 계산함. 이럴 때 어떻게 해야하는지 찾아보기.
	while ((scanf("%f", &input)) == 1)
	{

		if (input < min)
			min = input;

		if (input > max)
			max = input;

		if (input < 0 || input > 100)
			continue;

		sum += input;
		++n;
	}

	printf("min = %f, max = %f, avg = %f", min, max, sum / n);
		return 0;
}