#include <iostream>
using namespace std;

void doSomthing(int y)
{
	cout << "In func " << y  <<  " " << &y << endl;
}

int main()
{
	doSomthing(5);	// In func 5 0000000674D0F660

	int x = 6;

	cout << "In main " << x << " " << &x << endl; // In main 6 0000000674D0F684

	// �Ű������� ���� y�� ���޵ȴ�. �׸��� y ���� �޸𸮿� 5��� ���� ���簡 �Ǿ� �ʱ�ȭ�� �ȴ�.
	// 6�̶�� ���� �Ķ���Ϳ� ���ݵȴ�.
	doSomthing(x);	// In func 6 0000000674D0F660
	doSomthing(x+1);// In func 7 0000000674D0F660

	// ���� ���� ������ �Լ� ���� ������ �ܺη� ������ ��ġ�� �ʴ´�.

	return 0;
}