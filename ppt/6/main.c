#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double factorial(int value);
void Line(void);
char getLC(void);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	//printf("%d", rand()%(45)+1);
	
	int randNum[8];
	int index = 0;
	
	for(int i = 0; i<8;i++)
	{
		randNum[i] = rand()%(45)+1;
	}
	for(int i = 0; i<8;i++)
		printf("%d ", randNum[i]);
	
	printf("\n-----------------------\n");
	for(int i=0; i<8;i++)
	{	
		for(int j=1; j<8; j++)
		{
			if(randNum[i] > randNum[j])
			{
				index = i;
				int tmp = randNum[index];
				randNum[index] = randNum[j];
				randNum[j] = tmp;
				index = j;
			}
		}
	index = 0;
	}
	for(int i = 0; i<8;i++)
		printf("%d ", randNum[i]);
	
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
 


