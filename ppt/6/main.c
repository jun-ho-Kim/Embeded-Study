#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double factorial(int value);
void Line(void);
char getLC(void);

int main(int argc, char *argv[]) {

	
	/*
	Line();
	printf("%c\n", getLC());
	
	printf("\n Living room\n");
	rectag(4, 4);
	*/
	
	/*
	int number;
	printf("Enter integer number : ");
	scanf("%d", &number);
	printf("%d != %.15g\n", number, factorial(number));
	*/
	return 0;
}

void rectag(int len, int width)
{
	int i, k;
	len /= 2;
	width /= 4;
	for(i=1; i<=width;i++)
	{
		printf("бс");
		
	}
	printf("\n"); 
}

char getLC(void)
{
	char ch;
	ch = getche();
	if(ch>64 && ch < 91)
		ch = ch+32;
		return (ch);
}

void Line(void)
{
	int j;
	for(j=1; j<=20;j++)
		printf("бс");
		printf("\n");	

}

double factorial(int value)
{
	if(value == 0) return 1;
	else return ((double)value * factorial(value-1));
}
 


