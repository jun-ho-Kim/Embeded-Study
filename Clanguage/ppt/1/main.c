#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	int age;
	char name[20];
	
	printf("���� �Է�: ");
	scanf("%d", &age);
	
	printf("�̸� �Է� : ");
	gets(name);
	printf("���� : %d, �̸� : %s\n", age, name);
	 */
	
	printf("�Է��� ���� : ");
	char ch[100];
	gets(ch);
	
	puts(ch);
	putchar('\n'); 
	/*
	char s[100]; 
	printf("�̸��� ����?\n");
	gets(s);
	//scanf("%s", s);
	puts(s);
	puts("�� �ݰ���");
	 */
	return 0;
}
