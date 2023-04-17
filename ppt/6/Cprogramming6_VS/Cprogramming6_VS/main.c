#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "po.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int power(int, int);

int main(int argc, char* argv[]) {
	/*
	//로또 프로그램 작성
	srand(time(NULL));
	//printf("%d", rand()%(45)+1);

	int randNum[8];
	int index = 0;

	for (int i = 0; i < 8; i++)
	{
		randNum[i] = rand() % (45) + 1;
	}

	for (int i = 0; i < 8; i++)
	{
		if (randNum[i] == randNum[i + 1])
		{
			randNum[i+1] = rand() % (45) + 1;
		}
	}


	for (int i = 0; i < 8; i++)
		printf("%d ", randNum[i]);

	printf("\n-----------------------\n");
	for (int i = 0; i < 8; i++)
	{
		index = 0;
		for (int j = 1; j < 8; j++)
		{
			if (randNum[index] > randNum[j])
			{
				int tmp = randNum[index];
				randNum[index] = randNum[j];
				randNum[j] = tmp;
				index = j;
			}
			else index = j;
		}
	}

	printf("eight number ");


	for (int i = 0; i < 8; i++)
		printf("%d ", randNum[i]);
	*/
	/*
	int i;
	int a, b;
	for (i = 0; i < 14; i++) printf("%5d\n", power(2, i));

	printf("더할 두 숫자를 입력해주세요");
	scanf("%d %d", &a, &b);

	printf("sum is %d, a = %d, b = %d", sum(a, b), a, b);

	return 0;
	*/
}