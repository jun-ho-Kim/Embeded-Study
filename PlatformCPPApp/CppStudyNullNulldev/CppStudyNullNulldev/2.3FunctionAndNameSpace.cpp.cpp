// CppStudyNullNulldev.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
// �������� ��ȣ��
#include <iostream>

// �ζ��� �Լ� - C 15��, 16��
// release ����� �� ���ϱ��ϴ� ��� push�� ��

// C���: [�����̸�, �Լ��̸�] �ߺ��� �ȵ�
// ��������� �ڵ带 ¥�� �ߺ��� ���ɼ��� ��������.
// �̰� �ذ��ϱ� ���� ������ ���� namespace�̴�. �̰� �Ҽ����� �����ϸ� �ȴ�.
// �������� ������ �� �Ҽ��� �߿�������.
// useage: namespace
// namespaece: test
// test::a // test�� ����, �Ҽ��̴�. 

//using�� ����Ͽ� std�� �ۼ��� �����־ ������ ���߿� �ĺ��� �˻����� ������ �� �� �ִ�.


// �ĺ��� �˻�����
// ��Ϲ���, ��������

int Add(int a, int b)
{
    return a + b;
}

namespace TEST
{
    void TestFunc(void)
    {
        Add(3, 4);
    }

    int Add(int a, int b)
    {
        return a + b;
    }
}

int main()
{
    int nResult = ::Add(3, 4);
    printf("%d\n", nResult);

    return 0;
}