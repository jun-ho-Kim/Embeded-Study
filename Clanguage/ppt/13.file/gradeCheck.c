#include <stdio.h>
#include <string.h>
#define STUDENT 5
#define DEPT 5

int jum[STUDENT+1][DEPT+1];
char name[STUDENT+1][20];
int sum[STUDENT+1];
int ave[STUDENT+1];

int main(int argc, char* argv[])
{
 FILE *fp, *exfp;
 int i, temp;
 int student, dept;
 char sub[10][10];
 char buff[1024];
 
/*
 if((fp=fopen("sungjuk.txt","r+"))==NULL)
 { printf(" file open error");
 }
 */
  if((exfp=fopen("gradeCheck.csv","r+"))==NULL)
 { printf(" excel file open error");
 }
 
 char *p;
 while(i<6)
 {
 	
 	printf("i is %d: ", i);
 	fgets(buff, 1024, exfp);
 	p = buff.strtok(NULL, ",");
 	
 	printf( "%s", buff);
 	i++;
 }

 
 
 ///////////////////////////////////////////////
 /*
 fscanf(fp,"%d", &student);
 printf("입력할 학생수는 %d 입니다. \n", student);

 fscanf(fp,"%d", &dept);
 printf("입력할 과목수는 %d 입니다. \n", dept);

 fscanf(fp,"%s %s %s %s %s %s %s", sub[0], sub[1], sub[2], sub[3] , sub[4], sub[5], sub[6]);
 printf("%s %s %s %s %s %s %s\n", sub[0], sub[1], sub[2], sub[3] , sub[4], sub[5], sub[6]);

 for(i=1; i<=student;i++)
 {
  fscanf(fp,"%d %s %d %d %d %d %d ", &temp, &name[i], &jum[i][0], &jum[i][1], &jum[i][2], &jum[i][3], &jum[i][4]);
 }

  for(i=1; i<=student;i++)
 { printf("%2d %6s %4d %4d %4d %4d %4d \n",
       i, name[i], jum[i][0],jum[i][1],jum[i][2],jum[i][3],jum[i][4]);
 }
   printf("\n Input complete!!\n");
   */
/*
 for(i=1; i<=STUDENT;i++)
 {
  printf("%d 이름입력 :",i);
  scanf("%s", &name[i]);
  printf(" 국어, 영어, 수학, 국사, 과학 성적입력\n");
  scanf("%d %d %d %d %d", &jum[i][0], &jum[i][1], &jum[i][2], &jum[i][3], &jum[i][4]);
 }
 */
 ////////////////////////////////////////////////////////////

/*
 for(i=1; i<=student;i++)
 { sum[i]=  jum[i][0]+ jum[i][1]+ jum[i][2]+ jum[i][3]+ jum[i][4];
  ave[i]= (int)sum[i]/5;
 }
 printf("순번 이 름 국어, 영어, 수학, 국사, 과학, 총점, 평균\n");
 printf("===================================================\n");

 for(i=1; i<=student;i++)
 { printf("%2d %6s %4d %4d %4d %4d %4d %4d %4d \n",
       i, name[i], jum[i][0],jum[i][1],jum[i][2],jum[i][3],jum[i][4],sum[i],ave[i]);
 }
 printf("===================================================\n");
 printf("이하여백 \n");
*/
  fclose(fp);
  
  
 return 0;
}
