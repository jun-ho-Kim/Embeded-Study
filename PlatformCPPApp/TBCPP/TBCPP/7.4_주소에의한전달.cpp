#include <iostream>
using namespace std;

void foo(int* ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl; //5 0000006400AFF634

	//void foo(const int* ptr)

	*ptr = 10; // ������ const ���� �� ���� �Ұ�
}

// �����͸� ����Ͽ� �Լ��� ����� �� ó�� �ϱ⵵ �Ѵ�.
void getSinCos(const double degrees, double* sin_out, double* cos_out)
{
	*sin_out = 1.0;
	*cos_out = 2.0;
}

//void foo(int* const ptr) 
// �ϴ� ����� �Լ� ���� �ּ� ���� �ٲ㵵 �����Ϳ� ���� ���޵� ���� ���� �����̱� ������ �Լ��� ������ �Լ� �� �ּҺ����� ������� �ʴ´�.

int main()
{
	int value = 5;

	cout << value << " " << &value << endl;// 5 00000086FA51FBE4

	//foo(value); // Error

	int* ptr = &value;	
	// ������ ������ �����̱� ������ �ּ��� ���� ���� ���� ���޵ȴ�.
	// �� �ּ� ���� ���簡 �ȴ�.
	cout << &ptr << endl;// 0000006400AFF658

	foo(ptr);	//5 0000006400AFF634 0000006400AFF610
	foo(&value);//5 0000006400AFF634 0000006400AFF610

	//foo(5); // Error // ���ͷ��̶� ���� �߻�

	double degrees = 30;
	double sin, cos;

	getSinCos(degrees, &sin, &cos);

	cout << sin << " " << cos << endl; // 1, 2

	// �ǿ����� ���鿡�� referece�� �����ϴ°� ����.
	// �����Ϳ� ���� ���޵� ��ǻ� ���� ���� �����̴�.

	int x = 5;
}