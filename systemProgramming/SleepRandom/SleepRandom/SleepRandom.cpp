#include <iostream>
#include <windows.h>
#include <process.h>

LARGE_INTEGER freq;
LARGE_INTEGER begin;
LARGE_INTEGER end;
__int64 elapsed;

//CPU 타이머 주파수 확인



int main()
{
    ::QueryPerformanceFrequency(&freq);
    std::cout << "초당 주파수: " << freq.QuadPart << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        ::QueryPerformanceCounter(&begin);
        //우연에 맡기기 위한 코드 한 줄!
        ::Sleep(10);
        ::QueryPerformanceCounter(&end);

        elapsed = end.QuadPart - begin.QuadPart;

        std::cout << "실제로 흘러간 시간: " << elapsed << std::endl;
        std::cout << "실제로 흘러간 시간(ms):" << 
            (double)elapsed / freq.QuadPart * 100 << std::endl;
        std::cout << "실제로 흘러간 시간(micro):" <<
            (double)elapsed / freq.QuadPart * 100 * 1000 << std::endl;
        std::cout << "랜덤 값(1~100);" <<
            elapsed % 100 << std::endl;

    }

}