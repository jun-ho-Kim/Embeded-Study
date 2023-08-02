#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <process.h>

UINT WINAPI ThreadFunction(LPVOID pParam)
{
    int nTmp = 0;
    while (1)
    {
        ++nTmp;
    }

    return 0;
}

int main()
{
    UINT nThreadId = 0;
    HANDLE hThread = (HANDLE)::_beginthreadex(
        NULL,
        0,
        ThreadFunction,
        NULL,
        0,
        &nThreadId);

    if (hThread == NULL)
    {
        std::cout << "ERROR: Failed to begin thread." << std::endl;
        return 0;
    }

    for (int i = 0; i < 8; ++i)
    {
        ::SetThreadAffinityMask(hThread, 0x0000001 << i);
        //::SetThreadAffinityMask(hThread, 3); // 3 == 0011 이므로 0번코어와 1번 코어를 사용한다.
        ::Sleep(5000);
    }

    ::WaitForSingleObject(hThread, INFINITE);
    ::CloseHandle(hThread);
}