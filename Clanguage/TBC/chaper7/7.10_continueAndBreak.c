//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	/*  continue */
	/*
	for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
			continue;

		printf("%d ", i); // 0 1 2 3 4 6 7 8 9 

		//if (i != 5)
		//	printf("%d ", i);
		// continue가 없어도 필수적으로 사용해야 하는 요소는 아니다. 보조적인 수단이 될 수 있다.
		// contitue를 사용하는 이유는 코드를 사용할 때 문맥적으로 차이가 발생할 수 있다.
	}
	*/
	printf("\n");

	/* break */
	/*
	for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
			break;
		// break를 사용하면 break에서 for 문으로 벗어난다.

		printf("%d ", i); // 0 1 2 3 4
	}
	*/

	/* while and continue */
	//int count = 0;
	//while (count < 5)
	//{
	//	int c = getchar();
	//	if (c == 'a')
	//		continue;
	//	putchar(c);
	//	count++;
	//}

	/* contitue as a placeholder */
	//while (getchar() != '\n')
	//	contitue;

	/* Need to use continue */

	//char c;
	//while ((c = getchar()) != '\n')
	//{
	//	if (c == 'a')
	//		continue;
	//	
	//	putchar(c);
	//}

	/* break */
	//char c;
	//while ((c = getchar()) != '.')
	////이 기능에는 입력을 받는 기능과 입력 값을 c에 할당해주는 두 가지 기능이 있다.
	////요즘 프로그래밍에는 한 곳에 한 가지 기능만 하게 해주는 것이 좋다.
	//{
	//	putchar(c);
	//}

	//↓

	//while (1)
	//{
	//	char c = getchar();

	//	if (c == '.')
	//		break;

	//	putchar(c);
	//}

	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
				break;
			printf("(%d %d)", i, j);
		}
		printf("\n");
	}
	// break는 다중 for문인 경우에 자신이 포함하고 있는 루프를 break하고 상위 루프는 break하지 않는다.

	return 0;
}