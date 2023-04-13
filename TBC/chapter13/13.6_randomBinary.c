#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// make a test binary file

	{
		FILE* fp = fopen("binary", "wb");
		for (int i = 0; i < 100; ++i)
		{
			double d = i * 1.11;
			fwrite(&d, sizeof(double), 1, fp);
		}
		fclose(fp);
	}

	// read

	FILE* fp = fopen("binary", "rb");
	long cur;
	double d;

	cur = ftell(fp);
	printf("Before reading %ld\n", cur);	// Before reading 0

	fread(&d, sizeof(double), 1, fp);

	cur = ftell(fp);
	printf("After reading %ld\n", cur);		// After reading 8

	printf("%f\n", d); // 0.000000
	
	fread(&d, sizeof(double), 1, fp);
	printf("%f\n", d); // 1.110000

	cur = ftell(fp);
	printf("After reading %ld\n", cur); // After reading 16
	fseek(fp, 32L, SEEK_SET); // 32 = 4 * 8 -> 4L
	fread(&d, sizeof(double), 1, fp);
	printf("%f\n", d); // 4.440000
	
	fclose(fp);

	return 0;
}