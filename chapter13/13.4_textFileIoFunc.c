#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 31

int main()
{
	FILE* fp;
	char words[MAX] = { '\0', };

	const char* filename = "record";

	unsigned long count = 0;

	if ((fp = fopen(filename, "w+")) == NULL) // Try r+, w+, a+.
	{
		fprintf(stderr, "Can`t open \%s\" file.\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
		fprintf(fp, "%s\n", words);

	//while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
	//	fprintf(fp, "%s\n", words);

	rewind(fp); /* go back to beginning of file */

	while (fscanf(fp, "%s", words) != EOF)
		fprintf(stdout, "%s\n", words);

	//while (fgets(words, MAX, fp) != NULL) // EOF check
	//	fputs(stdout, "%s\n", words);

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");


	//while (fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
	//	fputs(words, fp);

	fclose(fp);

	//SetConsoleOutputCP(default_cp);

	printf("한글 출력 확인");

	return 0;
}