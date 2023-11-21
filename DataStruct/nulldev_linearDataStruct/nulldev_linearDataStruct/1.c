﻿#include <stdio.h>

typedef struct USERDATA
{
    int age;
    char name[32];
    char phone[32];
    struct USERDATA* pNext;
} USERDATA;

int main(void)
{
    USERDATA a = { 10, "HOON", "010-1234-1234" };
    USERDATA b;
    b = a;
    printf("%d %s %s\n", b.age, b.name, b.phone); // 10, HOON, 010-6283-5049

    USERDATA aList[4] = {
        {20, "Tester01", "010-1234-1111", NULL},
        {21, "Tester02", "010-1234-2222", NULL},
        {22, "Tester03", "010-1234-3333", NULL},
        {23, "Tester04", "010-1234-4444", NULL}
    };

    aList[0].pNext = &aList[1];
    aList[1].pNext = &aList[2];
    aList[2].pNext = &aList[3];
    aList[3].pNext = NULL;

    printf("%s\n", aList[0].name);  // TESTER01
    printf("%s\n", aList[0].pNext->name);   // TESTER02
    printf("%s\n", aList[0].pNext->pNext->name);    // TESTER03
    printf("%s\n", aList[0].pNext->pNext->pNext->name); //TESTER04
    putchar('\n');

    for (int i = 0; i < 4; ++i)
        printf("%s\n", aList[i].name);


    return 0;
}