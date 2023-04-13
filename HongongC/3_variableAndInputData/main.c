#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {	
	printf("3-1------------------------------------------\n");
	int a;
	int b, c;
	double da;
	char ch;
	
	a = 10;
	b = a;
	c = a + 20;
	da = 3.5;
	ch = "A";
	
	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);
	//printf("변수 ch-s의 값 : %s\n", ch);
	
	printf("3-2------------------------------------------\n");
	char ch1 = 'A';
	char ch2 = 65;
	printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch1);	// 65
	printf("아스키 코드 값이 %d인 문자 : %c\n", ch2, ch2);	// A
	
	printf("3-3------------------------------------------\n");
	short sh = 32767;
	int in = 2147483647;
	long ln = 2147483647;
	long long lln = 123451234512345;
	
	printf("short형 변수 출력 : %d\n", sh);
	printf("int형 변수 출력 : %d\n", in);
	printf("long형 변수 출력 : %ld\n", ln);
	printf("long long형 변수 출력 : %ld\n", lln);
	
	printf("long long형의 크기: %d바이트\n", sizeof(long long));
	
	printf("3-4------------------------------------------\n");
	unsigned int a1;
	a = 4294967295;
	printf("%d\n", a);	// -1
	a = -1;
	printf("%u\n", a);	// 4294967295
	
	printf("3-5------------------------------------------\n");
	float ft = 1.234567890123456789;
	double db = 1.234567890123456789;
	
	printf("float형 변수\t: %.30f값\n" , ft);
	printf("double형 변수\t: %.30lf값\n", db);
	
	printf("3-6, 3-7------------------------------------------\n");
	char fruit[10] = "strawberry";
	printf("딸기 : %s\n", fruit);
	printf("딸기쨈 : %s %s\n", fruit, "jam");
	// fruit = "Banana"; Error
	strcpy(fruit, "banana");
	printf("바나나쨈 : %s %s\n", fruit, "jam");
	
	printf("3-8------------------------------------------\n");
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	
	income = 456;
	tax = income * tax_rate;
	printf("세금은 : %.1f입니다.\n", tax);
	/*
	printf("3-9------------------------------------------\n");
	int a2 = 7;
 
	scanf("%d", &a2);
	printf("입력된 값 : %d\n", a2);
	
	printf("3-10------------------------------------------\n");
	int age;
	double height;
	
	printf("나이와 키를 입력하세요");
	scanf("%d%lf", &age, &height);
	printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age, height); 
	*/
	printf("3-11------------------------------------------\n");
	char grade;
	char name[3];
	
	printf("학점 입력: ");
	scanf("%c", &grade);
	printf("이름 입력: ");
	scanf("%s", &name);
	printf("%s의 학점은 %c입니다.\n", name, grade);
	
	return 0;
}
