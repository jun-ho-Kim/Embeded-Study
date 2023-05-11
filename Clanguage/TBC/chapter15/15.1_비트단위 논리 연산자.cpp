#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 지금까지는 자료형 단위로 이루어진 연산 위주로 공부를 했다.
// 비트 단위로 이루어진 논리연산자에 대해서 알아보자.

// 비트단위 연산자가 왜 필요한가?
// 게임을 만들 때 아이템 옵션이 발생한다.

int main()
{
	unsigned char a = 6; // 0000 0110
	unsigned char b = 5; // 0000 0101

	// Bitwise AND & // 두 개의 비트가 1이면 1 그 외는 0
	printf("Bitwise AND & %hhu\n", a & b); // 4 // 0000 0100

	// Bitwise OR | // 두 개 비트 중 하나만 1이면 1 둘 다 0인 경우는 0
	printf("Bitwise OR | %hhu\n", a | b); // 7 // 0000 0111

	// Bitwise OR | // 두 개 비트 중 하나만 1이면 1 둘 다 0인 경우는 0, 둘 다 1인 경우는 
	printf("Bitwise Exclusive OR ^ %hhu\n", a ^ b); // 3 // 0000 0011

	// Bitwise NOT ~ // 비트의 반대 값
	printf("Bitwise Exclusive OR ^ %hhu\n", ~a); // 249 // 1111 1001
}