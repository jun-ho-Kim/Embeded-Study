#include <stdio.h>
#include <stdlib.h>
// todo main arg ���

int main(void)
{
	FILE* pFile = fopen("./test/123", "rb");
	int num;

	char buffer[10];

	if (pFile == NULL)
	{
		printf("������ �����ϴ�. ���α׷��� �����մϴ�.");
		return 0;
	}
	//buffer = (char*)malloc(sizeof(char) * 10);
	num = fread(buffer, 8, 10, pFile);

	printf("buff is %c\n", buffer[0]);

	

	for (int i = 0; i < 10; i++)
	{
		printf("pFile value %d is %p size is %d \n",i, &pFile[0], sizeof(pFile[0]));
	}

	//fseek(pFile, 0, SEEK_END);
	//int fileLength = ftell(pFile);

	//printf("pFile leng is %d", fileLength);
	free(buffer);
	fclose(pFile);
}
