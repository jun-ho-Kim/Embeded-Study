#include <stdio.h>

int main(void)
{
	FILE* afp, * bfp;
	int num = 10;
	int res;
	int ary[5] = { 1,2,3,4,5 };


	afp = fopen("f.txt", "wt");
	fprintf(afp, "%d", num);

	bfp = fopen("g.txt", "wb");
	fwrite(&num, sizeof(ary), 1, bfp);

	fclose(afp);
	fclose(bfp);

	bfp = fopen("g.txt", "rb");
	fread(&res, sizeof(res), 1, bfp);
	printf("%d", res);

	fclose(bfp);

	return 0;
}