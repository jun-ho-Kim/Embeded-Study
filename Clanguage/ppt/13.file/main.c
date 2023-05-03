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
	
	fscanf(fp, "%s", str); // fscanf로 하는 경우 \n 관련 이슈 
	printf("기수=%s\n", str); 
	
	fscanf(fp, "%s", str);
	printf("기수=%s\n", str);
	
	
	// 일반적으로 문자열로 넣어라. 파일의 타입을 통일해라 
	
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
	
	// 성적 txt 파일로 입력받아서 총합, 평균내기
	
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
	printf("점수=%s\n", str);-// 번호 
	
	fscanf(fp, "%s", str);
	printf("점수=%s\n", str); // 이름 
	
	fclose(fp);
	
	
	
	return 0;
}
