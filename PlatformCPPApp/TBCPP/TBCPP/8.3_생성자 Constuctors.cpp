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

	Fraction(const int& num_in = 3, const int& den_in = 1)
	{
		m_numerator = num_in;
		m_denominaotr = den_in;
	}
	/*
	// case1 �����ڸ� �Ķ���Ϳ� �ʱ�ȭ�� �ٸ� �����ε� �����ڶ� �������� ��� ���� �߻�
	Fraction()
	{
		m_numerator = 1;
		m_denominaotr = 1;
	}

	Fraction(const int& num_in=2, const int& den_in = 1)
	{
		m_numerator = num_in;
		m_denominaotr = den_in;
	}
	*/

	void print()
	{
		cout << m_numerator << " / " << m_denominaotr << endl;
	}
};

class Second
{
public:
	Second()
	{
		cout << "class Second contructor()" << endl;
	}
};

class First
{
	Second sec;

public:
	First()
	{
		cout << "class First contructor()" << endl;
	}
};

int main()
{
	// �������� �Ķ���Ͱ� �ϳ��� ���� ��� ()�� �����Ѵ�.
	//Fraction frac;//{ 0,1 }; // int i {0}; 
	Fraction frac(1,3);//{ 0,1 }; // �ʱ�ȭ ���ִ� ���

	// Fraction frac(); // Error //
	//Fraction frac; //case1 Error
	//frac.m_numerator = 0;
	//frac.m_denominaotr = 1;

	frac.print();


	///////////////////////
	First fir; // second�� ���� ������ �� first�� �����ȴ�.
	//second�� first�� ����� ����ֱ⶧����
	//class Second contructor()
	//class First contructor()
	// �����ڰ� private�� Ŭ������ ������ �ȵȴ�. �̸� ����ϴ� ���α׷����� ���߿� �˾ƺ���.
}