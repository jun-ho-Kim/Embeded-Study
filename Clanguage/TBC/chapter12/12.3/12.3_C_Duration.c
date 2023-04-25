#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Storage duration: (Storage duration의 4가지 종류)
	- static storage duration (프로그램이 시작이 될 때 메모리에 저장이 되고, 끝날 때까지 static하게 머문다는 뜻. static 키워드랑 의미가 다르다.)
	(Note: 'static' keyword indicates the linkage type, not the storage duration)
	- automatic storage duration (지역 변수를 의미한다. 메모리 레이아웃에서 볼 때는 stack에 저장된다.)
	- allocated storage duration (동적할당과 관련이 있다.)
	- thread storage duration (멀티쓰레딩 개념. 기초 강의 범위는 벗어난다.)
*/

void count()
{
	int ct = 0;
	printf("count = %d\n", ct);
	ct++;
}
// stick 변수를 사용하면 프로그램이 시작될 때부터 끝날 때까지 메모리에서 가지고 있다. 다시 선언되지 않는다.
void static_count()
{
	static int ct = 0;
	printf("static count = %d\n", ct);
	ct++;
}

int main()
{
	count(); // 0
	count(); // 0
	static_count(); // 0
	static_count(); // 1

	return 0;
}