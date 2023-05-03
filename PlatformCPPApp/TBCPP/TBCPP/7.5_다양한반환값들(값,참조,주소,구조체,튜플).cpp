// �Լ��� ��ȯ���� ��� �������� ������ ���캸��.

#include <iostream>
#include <array>
#include <tuple>

using namespace std;

int getValue(int x)
{
	int value = x * 2;
	return value;
}

int* getAddress(int x)
{
	int value = x * 2;
	return &value;
}

int* allocateMemoery(int size)
{
	return new int[size]; // �ּҸ� ��ȯ
}

int& getReference(int x)
{
	int value = x * 2;

	cout << "getReference Value is" << &value << endl; // getReference Value is000000C3C44FF9E4
	return value;
}

int& get(std::array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

struct S
{
	int a, b, c, d;
};

//S getStrct()
//{
//	S my_s{ 1,2,3,4 };
//}

std::tuple<int, double> getTuple() // ����� ���� �ڷ����� ����.
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}

int main()
{
	// ���� ���� ����
	int value = getValue(3); 
	// ���� �����ϰ� ���������� ���糪 ������ ������ ������ �Ͼ�� �ӵ��� ������ ���̴�.
	// structure�� class, array ���� ����� �� �����Ͱ� ���ٸ� ������ �����ϴ� ����� ���� �ɸ� ���̴�.

	// �ּҿ� ���� ����
	//int *address = getAddress(3);// �� ����// �ּҴ� �Լ��� ���� �� �̹� ������� ������
	//int address = *getAddress(3); // ���� X // ����� ������ reference�� �ϴ� ���� ���� ����� �ƴϴ�.
	//������ �������� ������ �̷��� �ϴ� ����� ����X

	int* array = allocateMemoery(1024); 

	delete[] array; // new�� ������ delete�� �־�� �Ǵµ� �Լ��� ���� �ִ�.

	int &referenceValue = getReference(5); // ���ϰ� �޴� ���ȸ� �ӽ÷� ����ְ� �ִٰ� �������.

	cout << referenceValue << endl;
	cout << referenceValue << endl;
	cout << &referenceValue << endl; // 000000C3C44FF9E4

	int x = 5;


	std::array<int, 100> my_array;
	my_array[30] = 10;

	get(my_array, 30) = 1024;
	cout << my_array[30] << endl; // 1024

	// ���� ���� �����ϰ� ���� ���
	// �Լ� �ϳ��� ���� �� ���� ����ü�� �ϳ� �� ����� �־�� �Ѵ�. �׷��� ���� �����ε尡 ũ��.
	// ���� ���̺귯���� ���ο� ����ü�� ���� �����Ͽ� ����Ͽ���.
	//S my_s = getStrct();
	//my_s.b;

	// Ʃ���� ���
	std::tuple<int, double> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl;	// 10
	cout << std::get<1>(my_tp) << endl; // 3

	// c++17 �������� �̿밡��
	auto [a, d] = getTuple();
	cout << a << endl;
	cout << d << endl;

	return 0;
}