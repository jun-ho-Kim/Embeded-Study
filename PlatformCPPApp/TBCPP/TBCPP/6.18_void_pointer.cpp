// ��� ������ Ÿ���� �ּҸ� �����ϴ� ���� �������̴�.
// �ڷ����� ������� �����͸� �����ϴ� ���?
// void poiner = generic pointer


#include <iostream>

using namespace std;

int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	//ptr = &c;

	// void �����ʹ� ������ ������ �Ұ����ϴ�. �� ������ �� bytes�� ���ؾ��ϴ��� �� �� �� ���� �����̴�.
	//cout << ptr + 1 << endl; // Error

	cout << &c << " " << ptr << endl; // a��������

	//cout << *ptr << endl; // � Ÿ������ ���� dereferencing�� �ȵȴ�.
	cout << *static_cast<float*>(ptr) << endl; // 3

	// void �����͸� ����ϴ� ��� �������� ����� �� �ε����ϰ� ����� �� �ִ�.
	// c++ ���������� �߰��� ���� �߿� ������ �� �ִ� �ڵ带 �ۼ��� �� �ִ�. ���߿� ���캸��.
	// void �����͸� ���캸�� �������� Ư���� ���� �����غ� �� �ִ�.
	// ���� ������ ���� ���̴�.
}