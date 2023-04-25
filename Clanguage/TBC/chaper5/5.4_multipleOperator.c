//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double seedMoney, targetMoney, annualInterest;
    int annual = 0;
    printf("Input seed money : ");
    scanf("%lf", &seedMoney);

    printf("Input target money : ");
    scanf("%lf", &targetMoney);

    printf("Input annual interest (%%) : ");
    scanf("%lf", &annualInterest);

    printf("seedMoney: %f, targetMoney: %f, annualInterest: %f %%\n", seedMoney, targetMoney, annualInterest);
    double interest = 1 + annualInterest / 100;
    printf("interest: %lf\n", interest);
    while (seedMoney <= targetMoney) {
        seedMoney = seedMoney * interest;
        annual += 1;
        printf("annual: %d, seedMoney: %f\n", annual, seedMoney);
    }
    
    printf("it takes %d years", annual);

    return 0;
}