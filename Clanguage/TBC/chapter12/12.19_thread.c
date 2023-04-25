/*
* // https://www.onlinegdb.com/ 에서 사용하는 코드
* 
* // gcc와 window에서의 코드가 다르다. window를 사용하기 위해서는 pthread.h를 설치해주어야 한다.
* // window에서는 Atomic이 없다.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep()
#include <pthread.h>
#include <stdatomic.h>

_Atomic int acnt = 0; // atomic type qualifer (C11)
// _Atomic qualifer는 쓰레드에서 해당 변수 작업 시 다른 쓰레드에서 접근하지 못하도록 한다.

// A normal C function that is executeed as a thread_local
// when its name is specified in pthread_create()

void myThreadFun(void* vargp)
{
    int n = 1; // thread storage duration
    for (int j = 0; j < 10; ++j)
    {
        sleep(1);
        acnt += n;
        printf("Printing from Thread %d %llu", acnt, (unsigned long long) & n);
    }

    return NULL;
}

int main()
{
    pthread_t thread_id1, thread_id2;

    printf("Before Thread\n");

    pthread_create(&thread_id1, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);

    pthread_join(&thread_id1, NULL);
    pthread_join(&thread_id2, NULL);
    // pthread_join는 thread가 작업이 끝날 때까지 프로그램이 기다려주도록 한다.

    printf("After Thread\n");
    printf("atomic %d\n", acnt);

    return 0;
}
*/

// window에서 하는 경우
#include <stdio.h>
#include <Windows.h>

// Atomic int acnt = 0; //NA

DWORD WINAPI ThreadFunc(void* data)
{
    int n = 1;
    Sleep(1000);

    // acnt += n; // NA
    printf("Printing from Thread \n");

    return 0;
}

int main()
{
    HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

    if (thread)
        WaitForSingleObject(thread, INFINITE);
}