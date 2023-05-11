#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���ݱ����� �ڷ��� ������ �̷���� ���� ���ַ� ���θ� �ߴ�.
// ��Ʈ ������ �̷���� �������ڿ� ���ؼ� �˾ƺ���.

// ��Ʈ���� �����ڰ� �� �ʿ��Ѱ�?
// ������ ���� �� ������ �ɼ��� �߻��Ѵ�.

int main()
{
	unsigned char a = 6; // 0000 0110
	unsigned char b = 5; // 0000 0101

	// Bitwise AND & // �� ���� ��Ʈ�� 1�̸� 1 �� �ܴ� 0
	printf("Bitwise AND & %hhu\n", a & b); // 4 // 0000 0100

	// Bitwise OR | // �� �� ��Ʈ �� �ϳ��� 1�̸� 1 �� �� 0�� ���� 0
	printf("Bitwise OR | %hhu\n", a | b); // 7 // 0000 0111

	// Bitwise OR | // �� �� ��Ʈ �� �ϳ��� 1�̸� 1 �� �� 0�� ���� 0, �� �� 1�� ���� 
	printf("Bitwise Exclusive OR ^ %hhu\n", a ^ b); // 3 // 0000 0011

	// Bitwise NOT ~ // ��Ʈ�� �ݴ� ��
	printf("Bitwise Exclusive OR ^ %hhu\n", ~a); // 249 // 1111 1001
}