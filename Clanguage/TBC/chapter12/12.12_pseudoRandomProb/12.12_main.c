#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // srand()
#include <time.h> // time()
#include "my_rand.h" // time()

int main(int argc, char * argv[])
{
	my_srand((unsigned int)time(0));

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", my_rand() % 6 + 1);
	}

	/*
		rand()
		- 0 to RAND_MAX (typically INT_MAX)
		- defined in stdilb.h
	*/

	//srand(1); // random seed // random seed가 같으면 나오는 숫자도 같다.
	//srand((unsigned int)time(0)); //

	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d\n", rand());
	//}

	/*
	* 내부적으로 사용하는 알고리즘
	* 난수를 생성하지만 실제로는 규칙이 있다.
	* 
	unsigned int next = 1;

	for (int i = 0; i < 10; ++i)
	{
		next = next * 1103515245 + 1234;
		next = (unsigned int)(next / 65536) % 32768;
		printf("%d\n", (int)next);
	}
	*/

	return 0;
}