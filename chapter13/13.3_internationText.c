#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // SetConsoleOutputCP()

int main()
{
	const UINT default_cp = GetConsoleOutputCP();
	printf("%u\n", default_cp);

	int ch;
	FILE* fr, * fw; //TODO: file pointer to write
	
	const char* in_filename = "원본_ansi.txt";
	const char* out_filename = "사본_ansi.txt";

	unsigned long count = 0;

	if ((fr = fopen(in_filename, "r")) == NULL) // Open a text file for reading.
	{
		printf("Can`t open %s\n", in_filename);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL) // Open a text file for writing.
	{
		printf("Can`t open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}

	//SetConsoleOutputCP(CP_UTF8);

	while ((ch = fgetc(fr)) != EOF)
	{
		fputc(ch, stdout);
		fputc(ch, fw);

		count++;
	}

	fclose(fr);
	fclose(fw);

	//SetConsoleOutputCP(default_cp);

	printf("FILE %s has %lu characters\n", in_filename, count);
	printf("Copied to %s\n", out_filename);

	printf("한글 출력 확인");

	return 0;
}