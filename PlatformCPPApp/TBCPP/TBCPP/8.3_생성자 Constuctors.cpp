#include <iostream>
using namespace std;

//��ü�� �����ϴٺ��� �������ڸ��� �̷� �Ӽ��̳� ��ɵ��� �����ؾ��ϴµ� �̷� �� ������(Contructor)�� ����Ѵ�.

class Fraction
{
public:
	int m_numerator; // ����
	int m_denominaotr; // �и�

public:
	// Franction() �����ڸ� ���������� ������ default �����ڰ� �־ ����ȴ�.
	// �����ڴ� �����ϸ� �޸𸮿� �ڸ��� ������ �ٷ� ����ȴ�.
	Fraction()
	{
		m_numerator = 1;
		m_denominaotr = 1;
	}

	Fraction(const int& num_in, const int& den_in = 1)
	{
		m_numerator = num_in;
		m_denominaotr = den_in;
	}

	void print()
	{
		cout << m_numerator << " / " << m_denominaotr << endl;
	}
};

int main()
{
	// �������� �Ķ���Ͱ� �ϳ��� ���� ��� ()�� �����Ѵ�.
	//Fraction frac;//{ 0,1 }; // int i {0};

	// Fraction frac(); // Error //

	Fraction frac(4, 5);
	//frac.m_numerator = 0;
	//frac.m_denominaotr = 1;

	frac.print();

	int y = 4;
}