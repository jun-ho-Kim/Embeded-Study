// ������ ���� �μ� ����(Call by reference)�� �˾ƺ���. ���簡 ���� ��ȣ�ϴ� ����̴�.
// ���� �ҽ� �� �� �� ���� �����Ѵ�.

#include <iostream>
#include <vector>
using namespace std;

// const type &variable �� �Է��� �� ó�� type &varible�� return�� �� ó�� �������.
void getSinCos(const double &degrees, double& sin_out, double& cos_out)
{
	// static �����̱� ������ �� �� ���� ����� �ȴ�.
	static const double pi = 3.141592 / 180.0;

	
	const double radians = degrees * pi;
	
	sin_out = std::sin(radians);
	cos_out = std::cos(radians);
}

typedef int* pint;

//void foo(int& x)
//void foo(int*& x) // �����͸� reference�� �޴� ���
//void foo((int*) &x)�� �ؼ��� �ϸ� ���ϴ�.
void foo(pint &x)
{
	cout << x << endl;
}

// ���� ���� ȣ���� �Լ� �ȿ��� ���Ӱ� ������ ���Ǹ� �ϰ� ���縦 �Ѵ�.
// ������ ���� ȣ���� ���� ��ü�� �ѱ�� ������ ���簡 �̷������ �ʴ´�.

void addOne(int& y) // Reference�� �����ϸ� y�� reference�� �Ѿ�´�.
{
	cout << y << " " << &y << endl;	// 5 0000004D266FFA44

	y = y + 1;
}

//void printElement(int(&arr)[4]) 
void printElement(const vector<int>& arr)
// (&arr)[4]�� ������ �Ķ������ �迭�� ���ƾ� �Ѵ�. ������ ���� �迭���� ���� �迭�� ����Ѵ�.
// ����� Ŭ������ ���� �����Ͽ� int(&arr)[4] ó�� ������� �ʴ´�.
// std::array�� std::vector�� ����ؼ� ������ referece�� ������ ���� ���� ������ std::array�� std::vector�� ���
{
}

int main()
{
	int x = 5;

	cout << x << " " << &x << endl;	// 5 0000004D266FFA44
	// x��� ���� ��ü�� ���ڷν� ������ �ȴ�.
	addOne(x);

	cout << x << " " << &x << endl;	// 6 0000004D266FFA44
	
	// �̷� ������ �Լ��� ����� ������ ���µ� ���ȴ�.

	double sin(0.0);
	double cos(0.0);

	// C++�� ���� ���� �ϳ��̱� ������ ������ ���� ���޿� ���Ͽ� �Լ��� return�ϴ� ��ó�� ����Ѵ�.
	getSinCos(30.0, sin, cos);

	cout << sin << " " << cos << endl; // 0.5 0.866025


	// ������ ���� �μ� ������ ����
	// �� ��ü�� �����ϸ� �Լ����� ������ ���Ѵ�.
	//	foo(6);
	// void foo(const int& x)

	// ���򿡴� �Է����� ������ ���� const�� �޴´�.
	// �ֱٿ� modern C++������ 
	//		1. return value openvisaion?, 
	//		2. ���� ���� return ���� ��ȯ�ϴ� ���� �������� �ʰ� �Ǿ���.



	int y = 5;
	//int* ptr = &x;
	pint ptr = &x;

	foo(ptr);

	// array�� �Ķ���Ϳ� �����ϴ� ���

	//int arr[]{ 1,2,3,4 };

	vector<int> arr{ 1,2,3,4 };

	printElement(arr);

	return 0;
}

// ������ ���� ���� ���� ����� ���簡 ��ȣ�ϰ� ȿ������ ���� �� ��ġ�����鼭 ���ϴ�. 
// ������ ���� ������ ����ϴ� ������� �ڵ��ϸ� ��κ��� ��쿡 ũ�� ���� ���� ȿ�������� �ڵ��� �� �ִ�.