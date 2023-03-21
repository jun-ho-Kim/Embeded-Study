//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// a만 포인터 주소 저장 타입이고 b는 그냥 int 타입이다.
	int* a.b;
	/*
	c++에서는 
	//int *a;
	//int *b; 
	//로 나누어서 사용하는 것을 권장
	//하지만 스타일은 같이 일하는 사람
	//상단메뉴 -> TOOLS -> Options -> C/C++ -> Formating -> General 에서 Default Foramt Style로 수정
	*/

	/*
		int *a; // O
		int* b; // O
		int * b; // X
	*/

	return 0;
}