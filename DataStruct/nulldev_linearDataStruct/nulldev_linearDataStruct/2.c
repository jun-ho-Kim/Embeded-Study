#include <stdio.h>

typedef struct USERDATA
{
    int age;
    char name[32];
    char phone[32];
    struct USERDATA* pNext;
} USERDATA;

int main(void)
{
    USERDATA a = { 10, "HOON", "010-6283-5049" };
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

    USERDATA* pUser = &aList[0];

    while (pUser != NULL)
    {
        printf("[%p] %d, %s, %s, [next: %p]\n",
            pUser,
            pUser->age, pUser->name, pUser->phone,
            pUser->pNext);
        pUser = pUser->pNext;
    }

    /*
    [00D7F6C0] 20, Tester01, 010 - 1234 - 1111, [next:00D7F708]
    [00D7F708] 21, Tester02, 010 - 1234 - 2222, [next:00D7F750]
    [00D7F750] 22, Tester03, 010 - 1234 - 3333, [next:00D7F798]
    [00D7F798] 23, Tester04, 010 - 1234 - 4444, [next:00000000]
    */

    return 0;
}
