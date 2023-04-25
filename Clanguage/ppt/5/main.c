#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("%d", sizeof(int));
	/*
	int a = 0;
	static int b;
	printf("a = %d, b = %d\n", a, b);
	*/
	/*
	printf("■\n");  //KS코드 
	printf("♠\n");	 
	printf("☎\n"); 
	*/
	/*
	int c =3;
	printf("cast c value %d\n", (double)c);
	printf("c value %d\n", c);
	*/
	
	/*
	//p.5 
	int i = 1;
	while(i<=1000)
	{
		printf("%d\n", i);
		i *= 2;
	}
	for(int i = 1; i<=1000; i*2) {
	printf("%d\n",i);
	i *= 2;
	}
	*/
	/*
		//p.7
		//<홀수 출력>
		int i;
		for(i = 0; i < 100; i++)
		{
			if(i%2 == 0)
				printf("%4d", i);
			printf("\n");
		}
	*/
	/*
		//p.7
		//<문자열을 뒤집는다>
		char s[18+1], temp;
		int i, j, len;
		strcpy(s, "I cream ice cream.");
		printf("\n");
		printf("%s\n\n", s);
		len = strlen(s);
		for(i=0, j=len-1; i<j; i++, j--)
		{
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;	
			printf("pre temp %p \n", &temp);
		} 
		
		printf("%s \n", s);
		printf("temp %s \n", temp);
	*/
	
	/*
		//p.8
		int cols, rows;
		for(rows=1; rows<13; rows++)
		{
			for(cols=1; cols<13; cols++)
				printf("%3d", cols*rows);
			printf("\n");
		}
	*/
	/*
	// p.9
	int count = 0;
	printf("Type in a phrase: \n");
	while(getche() != '\r')
		count ++;
	printf("\n character count is %d", count);
	*/
	
	/*
	// p.10
	int count = -1;
	char ch ='a';
	printf("Type in a phrase :\n");
	while(ch != '\0')
	{
		ch = getche();
		count++;
	}
	printf("\n character count is %d", count);
	*/
	
	/*
	//p.11
	char ch = 'a';
	while(ch != '\r')
	{
		printf("Enter a character : \n");
		ch = getch();
		printf("\n The code for %c is %d \n", ch, ch);
	}
	*/
	/*
	// p.12
	int i;
	char ch = 'a';
	for(i=0; i<5; i++)
	{
		printf("\n Type in a letter from 'a' to 'e'");
		while((ch=getche()) != 'd') //while(ch=(getche() != 'd')
		{
			printf("\n Sorry, %c is incorrect.\n", ch);
			printf("Try again \n");
		}
		printf("\n That`s it! \n");
	}
	printf("Game`s over! \n");
	*/
	
	/*
	//p.13
	long number = 0;
	long answer;
	while(number != 1)
	{
		printf("\n Enter a number : \n");
		scanf("%ld", &number);
		answer = 1;
		while(number>1)
			answer=answer*number--;
	}
	printf("Factorial is :%Ld\n", answer);
	*/
	
	/*
	// 아래 함수가 없어서 실행을 못함 
	//p.14
	switch(getch())
	{
		case 'l':
		case 'L': 
		{
			fileload();
			break;
		}
		case 'p':
		case 'P':	
		{
			pickfile();
			break;
		}
		case 'c':
		case 'C':
		{
			cancle();
			break;
		}	
	}
	*/
	
	/*
	char c;
	switch(c=tolower(getch()))
	{
		default : 
			if(c>=0 && c < 9)
				printf("Decimal or Haxa");
			else break;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'f':
			printf("HexaDecima\n");
		break;
	}
	*/
	/*
	//p.17
	int length, i;
	char string[] = "THIS IS A STRING";
	length = strlen(string);
	for(i=0; i<length; i++)
	{
		string[i] = tolower(string[i]);
	}
	printf("%s\n", string);
	*/
	
	/*
	//p.23
	srand(time(NULL));
	char ch = 1;
	do 
	{
		int randchar = rand()%(103-97+1) + 97;
		printf("rand char %c\n", randchar);
		printf("\n\n Type in a digit from 'a' to 'e' : \n");
		while((ch=getche())!= randchar)
		{
			printf("\n Sorry, %c is incorrect.\n", ch);
			printf("Try again \n");	
		}	
		printf("\n That`s it! \n");
		printf("\n Play again ? (type 'y' or 'n') :");
	} while (getche() == 'y');
	printf("\n Thanks fo play");
	*/
	

	
	/*
	// rand example
	int ans = 0, bet = 0;
	printf("Enter number(0~10)? ");
	scanf("%d", &bet);
	srand(time(NULL));
	ans = rand()%10;
	
	if(bet == ans) printf("That`s It\n");
	else printf("wrong number is %d", ans);
	*/
	/*
	printf("구구단 칸에 맞춰  출력 문제===========================================================\n");
	int i, dan = 0;
	printf("몇 단을 출럭하시겠습니까?\n");
	//scanf("%d", &dan);
	printf("%d단 \t\t %d단 \t\t %d단 \t\t %d단\n", dan+1, dan+2, dan+3, dan+4);
	printf("===========================================================\n");
	for(i=1; i<=19;i++)
	{
		// printf("%d * %d = %d,\t %d * %d = %d,\t %d * %d = %d,\t %d * %d = %d \n", 
		// (dan+1), i, (dan+1)*i, (dan+2), i, (dan+2)*i, (dan+3), i, (dan+3)*i, (dan+4), i, (dan+4)*i);
		printf(" %d * %d = %d\t",(dan+1), i, (dan+1)*i);
		printf(" %d * %d = %d\t",(dan+2), i, (dan+2)*i);
		printf(" %d * %d = %d\t",(dan+3), i, (dan+3)*i);
		printf(" %d * %d = %d\n",(dan+4), i, (dan+4)*i);
	}
	
	dan = 4;
	printf("===========================================================\n");
	printf("%d단 \t\t %d단 \t\t %d단 \t\t %d단\n", dan+1, dan+2, dan+3, dan+4);
	printf("===========================================================\n");
	
	for(i=1; i<=19;i++)
	{
		//printf("%d * %d = %d,\t %d * %d = %d,\t %d * %d = %d,\t %d * %d = %d \n", 
		//(dan+1), i, (dan+1)*i, (dan+2), i, (dan+2)*i, (dan+3), i, (dan+3)*i, (dan+4), i, (dan+4)*i);
		printf(" %d * %d = %d\t",(dan+1), i, (dan+1)*i);
		printf(" %d * %d = %d\t",(dan+2), i, (dan+2)*i);
		printf(" %d * %d = %d\t",(dan+3), i, (dan+3)*i);
		printf(" %d * %d = %d\n",(dan+4), i, (dan+4)*i);
	}
	printf("===========================================================\n");
	*/
	
	
	
	/*
	for(int i=1; i<=9; i++)
	{
		for(int j = 1; j<5; j++)
		{
			printf("%d * %d = %d \t", j, i, j * i);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=1; i<=19; i++)
	{
		for(int j = 5; j<9; j++)
		{
			printf("%d * %d = %d \t", j, i, j * i);
		}
		printf("\n");
	}
	*/
	
	/*
	printf("-------------기탄수학 문제집-------------\n\n");
	int arrA[100];
	int arrB[100];
	int answer[100];
	char op;
	int opLen;
	int moffset;
	int page;
	srand(time(NULL));

	
	printf("원하는 연산은? +, -, *, /, \n");
	scanf("%c", &op);
	
	printf("연산의 자리수는? 1~3\n");
	scanf("%d", &opLen);
	
	if(opLen == 1) moffset = 10;
	else if(opLen == 2) moffset = 100;
	else if(opLen == 3) moffset = 1000;
	
	printf("몇 페이지를 출력할까요? 1~5\n");
	scanf("%d", &page);
	
	
	for(int i = 0; i < 100; i++)
	{
		arrA[i] = rand() % moffset;
		arrB[i] = rand() % moffset;
		if(op == '+')
			answer[i] = arrA[i] + arrB[i];
		if(op == '-')
			answer[i] = arrA[i] - arrB[i];
		if(op == '*')
			answer[i] = arrA[i] * arrB[i];
		if(op == '/')
			answer[i] = arrA[i] / arrB[i];
	}
		int index = 0;
		
		//for(int i = (page-1)*20; i < 20 * page; i++)
		for(int i = 0 + 20 * (page-1); i < 20 * (page); i+=4)
		{
			for(int j = i; j < i +4; j++)
			{
				printf("%d)\t", j);
			}
			printf("\n");
			for(int j = i; j < i +4; j++)
			{
				printf("%5d\t", arrA[j]);
			}
			printf("\n");
			for(int j = i; j < i +4; j++)
			{
				printf("%c", op);
				printf("%4d\t", arrB[j]);
				
			}
			printf("\n-----\t-----\t-----\t-----\t\n\n");
			//++index;
		} 
		printf("\n");
	
		printf("\n");
	for(int i = 0 + 20 * (page-1); i < 20 * (page); i++)
		printf("%d answer is %d\n", i, answer[i]);
	
	for(int i = 0 + 20 * (page-1); i < 20 * (page); i++)
	{
		printf("%d ", arrA[i]);
	}	
	*/
	/*
	long number = 0;
	long answer;
	while(number != 1)
	{
		printf("\n Enter a number : \n");
		scanf("%ld", &number);
		answer = 1;
		while(number > 1)
			answer = answer*number--;
	}
	printf("Factorial is : %ld\n", answer);
	char ch = 'a';
	*/
	 
	/*
	char arr[2] = "te8st5";
	char *arr2 = arr;
	for(int i = 0; i<10; i++) 
	{
		printf("printf i %i-%d\n", i, arr[i]);
		//printf("printf2 i %i-%c\n", i, arr2[i]);
	}
	printf("printf end s-%s\n", arr);
	puts(arr);
	printf("printf2 end s-%s\n", arr2);
	*/
	
	return 0;
}
