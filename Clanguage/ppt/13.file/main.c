#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp, * fpw;
	char str[128];
	int line=0;

	int i, temp;
	char name[6][20];
	int score[5][5];
	char buffer[1024];
	char* p;
	/*
	//if((fp=fopen("test.txt", "w")) == NULL)
	if((fp=fopen("data.txt", "r")) == NULL)
	{
		printf("File open error...\n");
		exit(-1);
	}
	
	fgets(str, sizeof(str), fp);
	puts(str);
	
	fgets(str, sizeof(str), fp);
	puts(str);
	
	fscanf(fp, "%s", str); // fscanf�� �ϴ� ��� \n ���� �̽� 
	printf("���=%s\n", str); 
	
	fscanf(fp, "%s", str);
	printf("���=%s\n", str);
	
	
	// �Ϲ������� ���ڿ��� �־��. ������ Ÿ���� �����ض� 
	
	while(1)
	{
		res = fgets(str, sizeof(str), fp);
		puts(str);
		
		if(res ==NULL)
		{
			break;
		}
	}

	for(;;)
	{
		gets(str);
		if(str[0] == '\0') break;
		line++;
		fprintf(fp, "%3d: %s\n", line , str);
	}
	 
	fclose(fp);
	*/
	
	// ���� txt ���Ϸ� �Է¹޾Ƽ� ����, ��ճ���
	
	int subjectSum[5] = {0,};
	int subjectAvg[5] = {0,};
	
	if((fp=fopen("gradeCheck.csv", "r+"))==NULL)
	{
		printf("File open error...\n");
		exit(-1);
	}

		//while (!feof(fp))
		//{
	for(int i=0; i<5; i++)
	{
			fgets(buffer, 1024, fp);
			printf("%s\n", buffer);
			p = strtok(buffer, ",");
			*name[i] = strtok(NULL, ",");
			printf("name %d is %c\n", i, *name[i]);
			for (int j = 0; j < 5; j++)
			{
				p = strtok(NULL, ",");
				score[i][j] = atoi(p);
				printf("p is is %s\n", p);
				printf("score %d %d is is %s\n", i, j, p);
			}

		}
		
	//}
		printf("-------------------\n");
	  for(i=0; i<5;i++)
	 { 
	 	printf("%2d %4d %4d %4d %4d %4d \n",
	       i, score[i][0],score[i][1],score[i][2],score[i][3],score[i][4]);
	 }
	
	//fgets(str, sizeof(str), fp);
	//puts(str);
	//
	//fgets(str, sizeof(str), fp);
	//puts(str);
	//
	//fscanf(fp, "%s", str);
	//printf("����=%s\n", str);-// ��ȣ 
	//
	//fscanf(fp, "%s", str);
	//printf("����=%s\n", str); // �̸� 
	
	fclose(fp);
	
	//fpw = fopen("result.csv", "w+");
	//for (int i =0; i<5;i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		fputs(score[i][j], fpw);
	//	}
	//

	//}
	//fclose(fpw);
	
	return 0;
}
