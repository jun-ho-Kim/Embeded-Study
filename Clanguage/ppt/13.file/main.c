#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp;
	char str[128];
	int line=0;

	int i, temp;
	char name[6][20];
	int jum[6][6];
	char *res;
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
	
	if((fp=fopen("sungjuk.txt", "r+"))==NULL)
	{
		printf("File open error...\n");
		exit(-1);
	}
	
	for(int i=0; i<5; i++)
	{
		fscanf(fp,"%d %s %d %d %d %d %d ", &temp, &name[i], &jum[i][0], &jum[i][1], &jum[i][2], &jum[i][3], &jum[i][4]);
	}
	  for(i=0; i<5;i++)
	 { 
	 	printf("%2d %6s %4d %4d %4d %4d %4d \n",
	       i, name[i], jum[i][0],jum[i][1],jum[i][2],jum[i][3],jum[i][4]);
	 }
	
	fgets(str, sizeof(str), fp);
	puts(str);
	
	fgets(str, sizeof(str), fp);
	puts(str);
	
	fscanf(fp, "%s", str);
	printf("����=%s\n", str);-// ��ȣ 
	
	fscanf(fp, "%s", str);
	printf("����=%s\n", str); // �̸� 
	
	fclose(fp);
	
	
	
	return 0;
}
