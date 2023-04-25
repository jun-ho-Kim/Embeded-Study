// CppStudyNullNulldev.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>

//void TestFunc(int = 10, int); // Error
void TestFunc(int, int = 10);

//Caller
int main()
{ 
        //동적 메모리 할당
        ////C
        //int* pnData = (int*)malloc(sizeof(int) * );
        //free(pnData);

        ////C++
        //int* pnNewData = new int[5];
        //delete [] pnNewData;

        int nData(10);
        std::cout << nData << std::endl;
        int& rData = nData;

        rData = 5;
        std::cout << nData << std::endl;
        std::cout << &nData << std::endl;
        std::cout << &rData << std::endl;
        // 포인터의 문제점(변절?)
        int nData = 10;
        int nNewData = 20;

        int* pnData = &nData;
        //nData = 5;
        *pnData = 5;

        pnData = &nNewData;
        //nNewData = 5;
        *pnData = 5;

    TestFunc(3);

    return 0;

}

//Callee
void TestFunc(int a, int b)
{
    printf("a: %d, b: %d\n", a, b);
}
