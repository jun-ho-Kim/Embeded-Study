#include <iostream>
#include <windows.h>

DWORD WINAPI ThreadFunction(LPVOID pParam)
{
    std::cout << "ThreadFuncfion() - Begin" << std::endl;
    std::cout << (const char*)pParam << std::endl;
    std::cout << "ThreadFunction() - End" << std::endl;

    return 0;
}

int main()
{
    std::cout << "main() - Begin" << std::endl;
    DWORD dwThreadId = 0;
    HANDLE hThread = ::CreateThread(
        NULL,
        0,
        ThreadFunction,
        (LPVOID)"PARAN",
        0,
        &dwThreadId
    );

    if (hThread == NULL)
    {
    }

    std::cout << "main() - waitForSingleObject() - before" << std::endl;
    std::cout << "hThread is " << hThread << std::endl;
    ::WaitForSingleObject(hThread, INFINITE);
    ::CloseHandle(hThread);
    std::cout << "main() - End" << std::endl;;



    //main() - Begin
    //main() - waitForSingleObject() - before
    // hThread is 00000000000000A4
    //ThreadFuncfion() - Begin
    //PARAN
    //ThreadFunction() - End
    //main() - End
}
