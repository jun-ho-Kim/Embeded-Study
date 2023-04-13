﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
	char bank_name[FUNDLEN];
	double bank_saving;
	char fund_name[FUNDLEN];
	double fund_invest;
};

//double sum(double, double);
double sum(struct fortune* my_fortune);

int main()
{
	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n",
	//	sum(my_fortune.bank_saving, my_fortune.fund_invest)
		sum(&my_fortune)
	);

	return 0;
}

double sum(struct fortune* mf)
{
	return mf->bank_saving + mf->fund_invest;
}

//double sum(struct fortune mf)
//{
//	return mf.bank_saving + mf.fund_invest;
//}


//double sum(const double x, const double y) // TODO: try pointers
//{
//	return x + y;
//}