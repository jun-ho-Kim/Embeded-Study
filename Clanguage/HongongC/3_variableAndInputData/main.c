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
	
	printf("���� a�� �� : %d\n", a);
	printf("���� b�� �� : %d\n", b);
	printf("���� c�� �� : %d\n", c);
	printf("���� da�� �� : %.1lf\n", da);
	printf("���� ch�� �� : %c\n", ch);
	//printf("���� ch-s�� �� : %s\n", ch);
	
	printf("3-2------------------------------------------\n");
	char ch1 = 'A';
	char ch2 = 65;
	printf("���� %c�� �ƽ�Ű �ڵ� �� : %d\n", ch1, ch1);	// 65
	printf("�ƽ�Ű �ڵ� ���� %d�� ���� : %c\n", ch2, ch2);	// A
	
	printf("3-3------------------------------------------\n");
	short sh = 32767;
	int in = 2147483647;
	long ln = 2147483647;
	long long lln = 123451234512345;
	
	printf("short�� ���� ��� : %d\n", sh);
	printf("int�� ���� ��� : %d\n", in);
	printf("long�� ���� ��� : %ld\n", ln);
	printf("long long�� ���� ��� : %ld\n", lln);
	
	printf("long long���� ũ��: %d����Ʈ\n", sizeof(long long));
	
	printf("3-4------------------------------------------\n");
	unsigned int a1;
	a = 4294967295;
	printf("%d\n", a);	// -1
	a = -1;
	printf("%u\n", a);	// 4294967295
	
	printf("3-5------------------------------------------\n");
	float ft = 1.234567890123456789;
	double db = 1.234567890123456789;
	
	printf("float�� ����\t: %.30f��\n" , ft);
	printf("double�� ����\t: %.30lf��\n", db);
	
	printf("3-6, 3-7------------------------------------------\n");
	char fruit[10] = "strawberry";
	printf("���� : %s\n", fruit);
	printf("����´ : %s %s\n", fruit, "jam");
	// fruit = "Banana"; Error
	strcpy(fruit, "banana");
	printf("�ٳ���´ : %s %s\n", fruit, "jam");
	
	printf("3-8------------------------------------------\n");
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	
	income = 456;
	tax = income * tax_rate;
	printf("������ : %.1f�Դϴ�.\n", tax);
	/*
	printf("3-9------------------------------------------\n");
	int a2 = 7;
 
	scanf("%d", &a2);
	printf("�Էµ� �� : %d\n", a2);
	
	printf("3-10------------------------------------------\n");
	int age;
	double height;
	
	printf("���̿� Ű�� �Է��ϼ���");
	scanf("%d%lf", &age, &height);
	printf("���̴� %d��, Ű�� %.1lfcm�Դϴ�.\n", age, height); 
	*/
	printf("3-11------------------------------------------\n");
	char grade;
	char name[3];
	
	printf("���� �Է�: ");
	scanf("%c", &grade);
	printf("�̸� �Է�: ");
	scanf("%s", &name);
	printf("%s�� ������ %c�Դϴ�.\n", name, grade);
	
	return 0;
}
