//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BASE1 12000000.0
#define BASE2 46000000.0
#define BASE3 88000000.0
#define BASE4 150000000.0
#define BASE5 300000000.0
#define BASE6 500000000.0

#define RATE1 (6.0/100.0)
#define RATE2 (15.0/100.0)
#define RATE3 (24.0/100.0)
#define RATE4 (35.0/100.0)
#define RATE5 (38.0/100.0)
#define RATE6 (40.0/100.0)
#define RATE7 (42.0/100.0)

#define BASIC_DEDUCTION 1500000.0

int main()
{
	int salary;
	double tax;

	printf("INPUT Salary : ");
	scanf("%d", &salary);

	salary -= BASIC_DEDUCTION;

	if (salary <= BASE1)
		tax = salary * RATE1;
	else if(salary <= BASE2)
		tax = (salary - BASE1) * RATE2 + BASE1 * RATE1;
	else if(salary <= BASE3)
		tax = (salary - BASE2) * RATE3 + (BASE2 - BASE1) * RATE2 + BASE1 * RATE1;
	// ... 이어서
	printf("your tax : %f", tax);

	return 0;
}