#include <iostream>
#include <string>

// ������ ��� �ʱ�ȭ ����Ʈ �Ǵ� ��� �ʱ��� ����Ʈ�� ������

// ����
// �������� ��� �̴ϼȶ����� ����Ʈ
// 1. ��� ���� ���� �� �ʱ�ȭ ���ֱ�
// 2. ������ ȣ�� �� ����_1
	/*
	Something()
	: m_i(1), m_d(3.14), m_c('a')
	: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b{ m_i - 1 }
	*/
// 3. ������ ȣ�� �� ����_2
	/*
	Something()
	//: m_i(1), m_d(3.14), m_c('a')
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b{ m_i - 1 }
	{
		cout << "Something::ctor" << endl;
		//2.
		m_i = 2;
		m_d = 6.28;
		m_c = 'b';
	}
	*/

// ������� �ʱ�ȭ ���� �� �켱 ������
// 3. ������ ȣ�� �� ����_2 > 2. ������ ȣ�� �� ����_1 > 1. ��� ���� ���� �� �ʱ�ȭ ���ֱ�



using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in)
		:m_b(m_b_in)
	{
		cout << "Something::ctor" << endl;
	}
};

class Something
{
private:
	// non-static ������� ��� ���� �ʱ�ȭ ����
	// but �����ڿ� �Բ� ��� ���� �ʱ�ȭ�� ������ ���ִ� ��� �������� ������ �ʱ�ȭ��
	int m_i = 100;
	double m_d = 100.0;
	char m_c = 'F';
	int m_arr[5] = { 100, 200, 300, 400, 500 }; // C++11 ���Ŀ� array�� �ʱ�ȭ ����
	B m_b{ 1024 };

public:
	Something()
		//: m_i(1), m_d(3.14), m_c('a')
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b{ m_i - 1 }
	{
		cout << "Something::ctor" << endl;
		 //2.
			m_i = 2;
			m_d = 6.28;
			m_c = 'b';
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl;
	}
};

int main()
{
	Something some;
	some.print();

	int z = 4;

	return 0;
}