//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	// file이라는 변수를 선언하는데 앞에 *가 있다. *는 포인터이고 포인터 변수라는 의미이다.
	// file 변수에는 주소가 저장이 된다.
	// pointer 변수에 파일을 읽어 들일 수 있는 stream을 다룰 수 있는 어떤 정보가 담겨져 있다.
	FILE *file = NULL;
	// 파일의 위치는 실행하는 파일의 위치와 함께 놓으면 된다.
	char file_name[] = "my_file.txt";

	// fopen: 파일의 stream을 열어준다. file로부터 데이터를 읽어오거나 저장할 수 있는 통로를 열어준다.
	// fopen 함수가 반환하는 오픈 함수가 반환하는 값이 file이라는 포인터 변수에 저장 될 것이다.
	// 별도의 옵션이 없으면 .txt 포맷을 읽어온다.
	file = fopen(file_name, "r");

	if (file == NULL)
	{
		printf("Failed to open file.\n");
		exit(1);
	}
	
	while ((c = getc(file)) != EOF)
		putchar(c);
	fclose(file);

	return 0;
}