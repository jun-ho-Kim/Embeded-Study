#include <iostream>
using namespace std;

// ������ const�� ���ϰ� ����� �� �ְ� �Լ��� �Ķ���ͷ� ������ ����� �� ���� ��������.

void doSomething(const int& x)
{
	cout << x << endl;
}

int main()
{
	/**/
	int x = 5;
	int &ref_x = x;

	const int& ref_2 = ref_x;

	// �Լ��� �Ķ���Ͱ� ������ �Ʒ��� ���� �����ϴ�.
	doSomething(x); // 5
	doSomething(1);	// 1
	doSomething(x+3);// 8
	doSomething(3*4);// 12


	return 0;
}