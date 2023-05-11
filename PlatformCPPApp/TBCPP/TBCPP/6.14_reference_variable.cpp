// Ư�� ��쿡 �����ͺ��� ���� ���� ������ ���� �˾ƺ���.

#include <iostream>
using namespace std;

void doSomething(int& n); //doSomething(const int& n) // ���򿡴� �Լ����� ���� �ٲ��� ���ϵ��� �ڵ��� �Ѵ�. �׷� ��� �Ű������� const�� �ٿ��ش�.
void printElement(int(&arr)[5]);

struct Somthing
{
	int v1;
	float v2;
};

struct Other
{
	Somthing st;
};

int main()
{
	//------------------------------------------------
	int value = 5;

	int* ptr = nullptr;
	ptr = &value;


	//��������
	int& ref = value;
	cout << ref << endl;

	ref = 10;

	cout << value << " " << ref << endl; // 10 10

	//������ ����ó�� ����� �� �� �ִ�.
	

	cout << &value << endl; //006FFCAC
	cout << &ref << endl;	//006FFCAC
	cout << ptr << endl;	//006FFCAC
	cout << &ptr << endl;	//006FFCA0

	//reference�� �ݵ�� �ʱ�ȭ�� �Ǿ�� �Ѵ�.

	// int &ref = 104; // ���������� ���ͷ��� ���� �� ����. l-value�� ���� �� �ִ�.
	//------------------------------------------------
	/*
	int x = 5;
	int& ref = x;

	const int y = 8;
	const int& ref = y;
	*/

	//------------------------------------------------
	/*
	int value1 = 5;
	int value2 = 10;

	int& ref1 = value1;

	cout << ref1 << endl;	// 5
	ref1 = value2;

	cout << ref1 << endl;	// 10
	*/

	int n = 5;

	cout << n << endl;	//5
	cout << &n << endl; //006FF9F8


	doSomething(n);

	cout << n << endl; //  void doSomething(int &n)�� ��� 10, void doSomething(int n)�� ��� 5

	// reference�� ����ϸ� ���� ��ü�� �ѱ��.
	// �����ʹ� ���� ��ü�� ���縦 �ؾߵȴ�.

	//------------------------------------------------
	// �迭�� ������ �޴� ��
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };

	printElement(arr);

	//------------------------------------------------
	// ����ü ���
	Other ot;
	int& v1 = ot.st.v1;
	v1 = 1;

	//------------------------------------------------
	int value = 5;
	//�Ʒ� 2���� ��� �� �����ϴ�.
	int* const ptr = &value;
	int& ref = value;
	*ptr = 10;
	ref = 10;

	return 0;
}

void doSomething(int& n) //doSomething(const int& n) // ���򿡴� �Լ����� ���� �ٲ��� ���ϵ��� �ڵ��� �Ѵ�. �׷� ��� �Ű������� const�� �ٿ��ش�.
{
	n = 10;
	cout << "In DoSometing " << n << endl; // In DoSometing 10
	cout << &n << endl;//006FF9F8
}

void printElement(int(&arr)[5])
{
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}