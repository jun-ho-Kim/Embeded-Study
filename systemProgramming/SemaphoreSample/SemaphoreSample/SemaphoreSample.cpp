#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <process.h>

HANDLE g_hSema;
TCHAR g_StringList[10][64] = { 0 };

UINT WINAPI ThreadSemaphore(LPVOID pParam)
{
    int nIndex = (int)pParam;

    while (TRUE)
    {
        ::wsprintf(g_StringList[nIndex],
            TEXT("%d thread is waiting"), nIndex);
        Sleep(500);

        DWORD dwResult = WaitForSingleObject(g_hSema, INFINITE);
        ::wsprintf(g_StringList[nIndex],
            TEXT("##%d thread is selected!##"), nIndex);
        ::Sleep(500);
        ::ReleaseSemaphore(g_hSema, 1, NULL);
    }
    return 0;
}

int main()
{
    g_hSema = ::CreateSemaphore(NULL, 3, 3, NULL);

    UINT nThreadId = 0;
    HANDLE hThread = NULL;

    for (int i = 0; i < 10; ++i)
    {
        hThread = (HANDLE)::_beginthreadex(
            NULL,
            0,
            ThreadSemaphore,
            (LPVOID)i,
            0,
            &nThreadId);

        ::CloseHandle(hThread);
    }

    while (1)
    {
        system("cls");
        for (int i = 0; i < 10; ++i)
        {
            _putws(g_StringList[i]);
        }
        ::Sleep(1000);
    }

    std::cout << "Hello World!\n";
}
