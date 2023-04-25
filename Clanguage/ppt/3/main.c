#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 13
#define STRINGLEN 21
#define MAXLENGTH 8
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	/*
	int i;
	int arr[MAX+1];
	arr[0] = 2;
	//printf("arr[0]", arr[0]);
	//i = 1;
	//while(i<=MAX)
	for(i = 1; i<=MAX; i++)
	{
		arr[i] = arr[i-1] * 2;
		//i = i + 1;
	}
	//i = 0;
	//while(i<=MAX)
	for(i = 0;i<=MAX; i++)
	{
		printf("%d\n", arr[i]);
		//i = i + 1;
	}
	*/

	/*
	int baeyul[4];
	char a = 10;
		// char baeyul[4];
	// char a = 'w';
	int i;
	for(i=0; i<=3; i++)
	{
		baeyul[i] = a;
		printf("\n baeyul[%d] ==> %d", i, *(baeyul+i));
		++a;
		printf("\n Baeyul sijak Juso .. %x Bunji", baeyul+i);
	}
	printf("\n Baeyul sijak Juso .. %x Bunji", baeyul);
	*/

	/*
	char chararray[STRINGLEN+1] = "Welcome to my world!";
	char *str;
	str = chararray;
	//strcpy(chararray, "Welcome to my world!");
	//str = "Welcome to my world!";
	printf("%s\n", chararray);
	printf("%s\n", str);
	printf("%p\n", chararray);
	printf("%p\n", str);
	printf("%d\n", chararray);
	printf("%d\n", str);
	printf("String length of str: %d\n", strlen(str));
	printf("String length of chararray: %d\n", strlen(chararray));
	printf("str[0]: %c\n", str[0]);
	printf("str[12]: %c, chararray[12] %c\n", str[11], chararray[12]);
	printf("End of str : %d\n", str[strlen(str)]);
	*/
	
	/*
	int i = 32;
	while(i<127)
	{
		printf("%c", i);
		if(i%32==31) printf("\n");
		i++;
	}
	*/
	
	/*
	printf("|%d|\n", 626);
	printf("|%6d|\n", 626);
	printf("|%06d|\n", 626);
	printf("|%-6d|\n", 626);
	printf("|%-06d|\n", 626);
	printf("|%x|\n", 626);
	printf("|%6x|\n", 626);
	printf("|%06d|\n", 626);
	
	char *string;
	string = "100% IBM compatible is the top of the lies.";
	printf("|%s|\n", string);
	printf("|%60s|\n", string);
	printf("|%-60s|\n", string);
	printf("|%30.21s|\n", string);
	printf("|%-30.21s|\n", string);
	printf("|%30.30s|\n", string);
	*/
	
	/*
	int i, m, n;
	printf("\n Enter three any integer: ");
	scanf("%i %i %i", &i, &m, &n);
	printf("\n Number : %d, %#o, %#x\n", i, m, n);
	*/
	
	/*
	int year;
	printf("Enter the year of your birthday: ");
	scanf("%d", &year);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("\n Your are %d year old.\n", tm.tm_year+1900-year+1); // todo: 1992 시간 함수로 변경
	*/
	
	/*
	char s[MAXLENGTH + 3];
	s[0] = MAXLENGTH + 1;
	printf("Enter a string:");
	printf("\n String length by s[0] = %d\n", s[0]);
	printf("\n String length by s[1] = %d\n", s[1]);
	_cgets(s);
	printf("String length by s[1] = %d\n", s[1]);
	printf("String length by strlen = %d\n", strlen(s));
	printf("String : %s\n", s);

	printf("_cputs", s);
	_cputs(s);
	*/
	
	return 0;
}
