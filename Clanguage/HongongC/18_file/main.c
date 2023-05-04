#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*
	//예제 18.1 
	FILE *fp;
	
	fp = fopen("a.txt", "r");
	if(fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	
	printf("파일이 열렸습니다.\n");
	fclose(fp);
	*/
	
	/*
	//예제 18.2
	FILE *fp;
	int ch;
	
	fp = fopen("a.txt", "r");
	
	if(fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	
	while(1)
	{
		ch = fgetc(fp);
		if(ch==EOF)
		{
			break;
		}
		putchar(ch);
	}
	
	fclose(fp);
	*/
	
	/*
	// 예제18.4 
	FILE *fp;
	char str[] = "banana";
	int i;
	
	fp = fopen("b.txt", "w");
	
	if(fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}
	
	i = 0;
	while(str[i] != '\0')
	{
		fputc(str[i], fp);
		i++;
	}
	
	fclose(fp);
	*/
	
	/*
	int ch;
	
	while(1)
	{
		ch = getchar();
		if(ch == EOF)
		{
			break;
		}
		putchar(ch);
	} 
	*/
	
	/*
	// 예제 18.5
	int ch;
	
	while(1)
	{
		ch = fgetc(stdin);
		if(ch==EOF)
		{
			break;
		}
		fputc(ch, stdout);
	}
	*/
	
	/*
	//예제 18.6 
	FILE *fp;
	int ary[10] = {13,10,13,13,10,26,13,10,13,10};
	int i, res;
	
	fp = fopen("a.txt", "wb");
	for(i = 0; i< 10; i++)
	{
		fputc(ary[i], fp);
	}
	fclose(fp);
	
	fp = fopen("a.txt", "rt");
	while(1)
	{
		res = fgetc(fp);
		if(res == EOF) break;
		printf("%4d", res);
	}
	fclose(fp);
	*/
	
	//예제18.7
	
	FILE *fp;
	char str[20];
	
	fp=fopen("a.txt", "a+");
	if(fp==NULL)
	{
		printf("파일을 마들지 못했습니다.\n");
		return 1;
	}
	 
	while (1)
	{
		printf("과일 이름 : ");
		scanf("%s", str);
		if(strcmp(str, "end") == 0)
		{
			break;	
		}
		else if(strcmp(str, "list") == 0)
		{
			fseek(fp, 0, SEEK_SET);
			while(1)
			{
				fgets(str, sizeof(str), fp);
				if(feof(fp))
				{
					break;
				}
				printf("%s", str);
			}
		}
		else 
		{
			fprintf(fp, "%s\n", str);
		}
		
	}
	fclose(fp);
	return 0;
}
