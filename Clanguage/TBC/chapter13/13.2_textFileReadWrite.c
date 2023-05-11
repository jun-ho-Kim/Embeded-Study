#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()

int main(int argc, char* argv[])
{
	int ch;
	FILE* fr, * fw; //TODO: file pointer to write
	//FILE* fr = 파일을 처리할 때 필요한 데이터의 묶음에 대한 포인터(구조체에 대한 포인터)
	/*
	typedef struc _iobuf
	{
		char* _ptr;
		int _cnt;
		char* _base;
		int _flag;
		int _file;
		int _charbuf;
		int _bufsiz;
		char* _tmpfname;
	} FILE;
	*/

	const char* out_filename = "output.txt";

	unsigned long count = 0;

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL) // Open a text file for reading.
	{
		printf("Can`t open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL) // Open a text file for writing.
	{
		printf("Can`t open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}
	/*
		fopen mode strings for text files
		- r: reading
		- w: creating-and-writing or over-writing
		- a: appending or creating-and-writing
		- r+: both reading and writing
		- w+: reading and writing, over-writing or creating
		- a+: reading and writing, appending or creating
	*/


	while ((ch = fgetc(fr)) != EOF) // getc(fr)
	{
		//putc(ch, stdout); // same as putchar(ch);
		fputc(ch, stdout);
		fputc(ch, fw); //write a file stream!

		count++;
	}

	fclose(fr);
	fclose(fw);

	printf("FILE %s has %lu characters\n", argv[1], count);

	return 0;
}