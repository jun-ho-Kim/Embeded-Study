//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n = 1; // 초기값 설정

    while (n < 3) { //조건
        printf("%d\n", n);
        n = n + 1; // 변하는 조건
    }

/* goto문
label:
    printf("%d\n", n);
    n = n + 1;

    if (n == 10) goto out;

    goto label;

out:
*/

    return 0;
}