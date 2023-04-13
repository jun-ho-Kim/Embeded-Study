#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	int age;
	char name[20];
	
	printf("나이 입력: ");
	scanf("%d", &age);
	
	printf("이름 입력 : ");
	gets(name);
	printf("나이 : %d, 이름 : %s\n", age, name);
	 */
	
	printf("입력한 문자 : ");
	char ch[100];
	gets(ch);
	
	puts(ch);
	putchar('\n'); 
	/*
	char s[100]; 
	printf("이름이 뭐니?\n");
	gets(s);
	//scanf("%s", s);
	puts(s);
	puts("야 반가워");
	 */
	return 0;
}
