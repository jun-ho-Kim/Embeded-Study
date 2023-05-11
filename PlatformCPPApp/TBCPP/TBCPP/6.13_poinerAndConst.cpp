#include <iostream>
using namespace std;

int main()
{
	/*
	//���� �տ� const�� ���̸� ���� �ּҸ� �Ҵ��Ϸ��� �����Ϳ��� const�� �ٿ��־�� �Ѵ�.
	// ������ const�� �پ ������ �� ������ ������� �ʴ´�.
	const int value = 5;
	const int* ptr = &value;
	//*ptr = 6; //  Error
	*/

	//------------------------------------------------
	/*
	int value = 5;
	const int* ptr = &value;
	//*ptr = 6; // Error
	value = 6; // ����
	*/


	//------------------------------------------------
	// �������� ���� ���� �ٲ��� ���Ѵ�. ������ ptr�� �ּҰ��� �ٲ� �� �ִ�.
	/*
	int value1 = 5;
	const int* ptr = &value1;
	//*ptr = 7; // Error

	int value2 = 6;
	ptr = &value2; // ����
	*/

	//------------------------------------------------
	/*
	int value = 5;
	int *const ptr = &value;
	*ptr = 10; // ����
	cout << *ptr << endl;
	int value2 = 8;
	// ptr = &value2; // Error
	*/

	//------------------------------------------------
	// Ÿ�� �� �ڷ� const�� ������ ������ ����� �ּҰ� ���� �� �� �� �� ����.
	int value = 5;
	const int *const ptr = &value; 
	//*ptr = 10; // Error
	int value2 = 8;
	// ptr = &value2; // Error

	return 0;
}