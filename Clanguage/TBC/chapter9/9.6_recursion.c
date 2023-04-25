//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void my_func(int);

int main()
{
	my_func(1);

	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %p, dec = %d\n", n, &n, &n);
	// Level 1, address of variable n = 0000001AC65FFC30
	// Level 2, address of variable n = 0000001AC65FFC00
	// Level 3, address of variable n = 0000001AC65FFBD0
	// Level 4, address of variable n = 0000001AC65FFBA0

	if(n<4)
		my_func(n + 1);

	printf("Level %d, address of variable n = %p, dec = %d\n", n, &n, &n);
	// Level 4, address of variable n = 0000001AC65FFBA0
	// Level 3, address of variable n = 0000001AC65FFBD0
	// Level 2, address of variable n = 0000001AC65FFC00
	// Level 1, address of variable n = 0000001AC65FFC30

	// 재귀함수가 끝나면 인셉션처럼 꿈을 계속 꾸다가 꿈에서 깰때는 깊은 꿈에서 순서대로 깨는 걸 생각하면 좋다.
	// 자세한건 다음 강의 때
}