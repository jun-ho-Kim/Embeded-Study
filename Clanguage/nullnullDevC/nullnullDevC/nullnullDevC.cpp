// nullnullDevC.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//C언어에서 자료형이란 일정길이의 메모리에 저장된 정보 해석 방법
//배열: 동일형식의 연속(연접)된 '집합체'
//구조체: 서로 같거나 다른 형식들의 연속된 집합체
//공용체: 한 형식(같은 크기)에 여러 해석 방법을 부여하는 문법
//구조체나 공용체 같은 것을 사용자 정의 자료형이라고 한다.

//single linked list - 자기 참조 구조체

#include <iostream>

typedef struct USERDATA
{
    int nHeight;
    char szName[12];
    char szPhone[12];
    unsigned char sex;

    struct USERDATA* pNext;
} USERDATA;

int main()
{
    USERDATA a;
    a.nHeight = 180;
    strcpy_s(a.szName, sizeof(a.szName), "Ho-sung");
    strcpy_s(a.szPhone, sizeof(a.szPhone), "123-1234");
    a.sex = 'M';

    char buffer[sizeof(USERDATA)];
    USERDATA* pData = (USERDATA*)buffer;
    pData->nHeight = 180;
    strcpy_s(pData->szName, sizeof(pData->szName), "David");
    strcpy_s(pData->szPhone, sizeof(pData->szPhone), "123-1234");
    pData->sex = 'M';

    a.pNext = pData;

    printf("%s", a.pNext->szName);

    return 0;
}
