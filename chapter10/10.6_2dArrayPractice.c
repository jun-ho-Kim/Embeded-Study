//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main()
{
	double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
	double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

	
	double arr[3][12] = { 
		{ -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 }, 
		{ -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
		{ -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 } 
	};

	printf("[Temperature Data]\n");
	printf("YEAR Index : ");
	for (int j = 1; j <= MONTHS; ++j) {
		printf("\t%d", j);
	}
	printf("\n");

	for (int y = 0; y < YEARS; ++y)
	{
		printf("Year %d     :", y);
		for (int m = 0; m < MONTHS; ++m)
		{
			printf("\t%.1f", arr[y][m]);
		}
		printf("\n");
	}
	printf("\n");

	printf("[Yearly average temperatures of 3 years\n");
	for (int y = 0; y < YEARS; ++y)
	{
		double sum = 0;
		for (int m = 0; m < MONTHS; ++m) {
			sum += arr[y][m];
		}
		printf("Year %d : average temperature = %.1f\n", y, sum / MONTHS);
	}
	printf("\n");

	printf("[Monthly average temperatures of 3 years\n");
	printf("YEAR Index : ");
	for (int j = 1; j <= MONTHS; ++j) {
		printf("\t%d", j);
	}
	printf("\n");
	printf("AVG temps :    ");
	for (int m = 0; m < MONTHS; ++m)
	{
		double sum = 0;
		for (int y = 0; y < YEARS; ++y) {
			sum += arr[y][m];
		}
		printf("\t%.1f", sum / YEARS);
	}

	return 0;
}