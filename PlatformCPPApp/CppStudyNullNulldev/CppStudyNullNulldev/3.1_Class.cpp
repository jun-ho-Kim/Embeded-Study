#include <iostream>
//��03�� Ŭ���� - ù ��°
//- C ��� : ����������->C++ : ��ü������
//�� Class = ����ü + �Լ��� ���


//////////////////////////////////////
//������ �ڵ�
class USERDATA // typedef struct USERDATA
{
public:
    int nAge;
    char szName[32];
    //void(*Print) (struct USERDATA*);
    void Print(USERDATA* pUser)
    {
        //printf("%d, %s\n", pUser->nAge, pUser->szName); // C-Style
        printf("%d, %s\n", nAge, szName); //C++-Style
    }

    void Print2()
    {
        //printf("%d, %s\n", pUser->nAge, pUser->szName); // C-Style
        printf("%d, %s\n", nAge, szName); //C++-Style
    }

};




//////////////////////////////////////
//����� �ڵ�
int main()
{
    USERDATA a = { 20, "HONG" };
    //1
    //printf("%d %s\n", a.nAge, a.szName);
    //2
    //PrintUserData(&a);
    //3
    a.Print(&a);
    //4
    //a.Print();
    //a.Print2();
    return 0;
}

// ������-����
// �ڷᱸ�� <- ����ڵ�(�Լ�) // �ڷᱸ���� ����Ǹ� �ڵ嵵 ����Ǵ� ���踦 ������, ���������� �Ѵ�.
// C������ �ڷᱸ���� ����ڵ��� �������� ����.

// C++������ ����ü�� ����.


// �ĺ��� �˻�����

// ����ü -> Ŭ���� �Ѿ�� ���� �κ� �ٽ� ���� �ǽ��غ���