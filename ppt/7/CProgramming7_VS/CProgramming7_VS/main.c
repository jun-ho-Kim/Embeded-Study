#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 40
#define MAN 2

void encode(char* s);
void decode(char* s);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {

	int sum[MAN + 1], ave[MAN + 1];
	int kor[MAN + 1], eng[MAN + 1], math[MAN + 1], his[MAN + 1], sci[MAN + 1];

	char name[MAN + 1][10];

	printf("�̸� �� ���� �Է�:\n");

	int i;
	
	for (i = 0; i < MAN; i++)
	{
		printf("%d �̸� �Է�: ", i);
		//scanf("%s", &name[i]);
		//gets(name[i]);
		
		
		char tmp[10];
		gets(tmp);
		//while (getchar() != '\n');

		strcpy(name[i], tmp);

		//printf("name is %s\n", name[i]);
		printf("����, ����, ����, ����, ���� �����Է�\n");
		scanf("%d %d %d %d %d", &kor[i], &eng[i], &math[i], &his[i], &sci[i]);

		printf("printf %d %d %d %d %d\n", kor[i], eng[i], math[i], his[i], sci[i]);
		//int tmp = (kor[i] + eng[i] + math[i] + his[i] + sci[i]);
		//printf("tmp is %d\n", tmp);
		sum[i] = (kor[i] + eng[i] + math[i] + his[i] + sci[i]);
		ave[i] = sum[i] / 5;

		//while (getchar() != '\n');
		//strcpy(tmp, sum[i]);
		//printf("sum is %d\n", sum[i]);
		//printf("ave is %d\n", ave[i]);
	}

	printf("����, �̸�,\t ����,\t ����,\t ����,\t ����,\t ����,\t ����,\t ���\n");
	printf("========================================================================\n");
	for (i = 0; i < MAN; i++)
	{
		printf("%3d   %s\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t\n", i + 1, name[i], kor[i], eng[i], math[i], his[i], sci[i], sum[i], ave[i]);
	}
	
	printf("=========================================================================");

	/*
	//��ȣȭ ���α׷�
	char c, str[MAXLEN+3];
	do{
		do{
			printf("\n Encode or DEcode or Quit(E/D/Q)?");
			c=toupper(_getche());
		} while(c != 'E' && c != 'D' && c != 'Q');
			if(c=='Q') break;
			printf("\n Enter number");
			str[0] = MAXLEN+1;
			_cgets(str);
			if(c=='E') {
				encode(str+2);
				printf("\n Encode number : %s", str+2);
			} else {
				decode(str+2);
				printf("\n Decode number : %s", str+2);
			}
		} while(1);
		printf("\n Good luck to you!! \n");
	*/

	/*
	char s[100];
	char *ps = s; //=  char *ps; ps = s

	char *s = "I`m rambo"; // char*s; strcpy(s, "I`m rambo"); // �ʱ�ȭ ����

	printf("s - %d, ps - %d", s, ps);
	*/
	return 0;
}


void encode(char* s)
{
	int i = -1;
	static char* code = "5792134608";
	while (s[++i])s[i] = code[s[i] - '0'];
}

void decode(char* s)
{
	int i = -1;
	static char* code = "8435607192";
	while (s[++i])s[i] = code[s[i] - '0'];
}