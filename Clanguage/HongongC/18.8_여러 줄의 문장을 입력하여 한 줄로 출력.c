#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* ifp, * ofp;
	char str[80];
	char* res;

	ifp = fopen("d.txt", "r");
	if (ifp == NULL)
	{
		printf("입력 파일을 열지 못했습니다.");
		return 1;
	}

	ofp = fopen("e.txt", "w");
	if (ofp == NULL)
	{
		printf("출력 파일을 열지 못했습니다.");
		return 1;
	}

	while (1)
	{
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL)
		{
			break;
		}
		printf("string is %s %d\n", str, strlen(str));
		printf("res is %s\n", res);
		str[strlen(str) - 1] = '\0';
		fputs(str, ofp);
		fputs(" ", ofp);
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}