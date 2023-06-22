// ���� ������, ���� �ʱ�ȭ �� �� ������ ����� �� RVO(Return Value Optimization)�� ��� �۵��ϳ� Ȯ���غ���

#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	// copy constructor�� private�� ����ϸ� �ܺο��� ���� �����ڸ� ȣ�� �� �� ����.
	//Fraction(const Fraction& fraction) // copy constuctor: ���� �����ڴ� �ڱ�� �Ȱ��� Ÿ���� �ν��Ͻ��� ������ �����Ѵ�.
	//	: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	//{
	//	cout << "Copy constructor called" << endl; // ���� �����ڰ� �󸶳� ���� ȣ��Ǵ��� Ȯ���ϱ� ���ؼ� cout �߰�
	//}

public:
	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	// ������ ���������� ���߿� ���� ����, ���� ������ �� �� ���� �� ���̴�.
	// copy constructor�� private�� ����ϸ� �ܺο��� ���� �����ڸ� ȣ�� �� �� ����.
	Fraction(const Fraction& fraction) // copy constuctor: ���� �����ڴ� �ڱ�� �Ȱ��� Ÿ���� �ν��Ͻ��� ������ �����Ѵ�.
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl; // ���� �����ڰ� �󸶳� ���� ȣ��Ǵ��� Ȯ���ϱ� ���ؼ� cout �߰�
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;

		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << "&temp is" << &temp << endl;

	return temp;
}

int main()
{
	Fraction frac(3, 5);

	//	1.
	/*
	Fraction fr_copy(frac);
	//= Fraction fr_copy = frac; // ���� ����� ����� ����.

	
	cout << frac << " " << fr_copy << endl;
	//
	//Copy constructor called
	//3 / 5
	// 3 / 5
	*/
	
	/*
	//	2. 
	Fraction fr_copy(Fraction(3, 10));

	cout << frac << " " << fr_copy << endl;
	���� ���� �����ϸ� �����Ϸ��� Fraction(3, 10)�� Fraction�� ���� �������� �Ѵ�.
	//3 / 5
	//	3 / 10
	*/

	//	3.
	Fraction result = doSomething();

	//cout << result << endl;
	// ** ����� ���
	//Copy constructor called
	//	1 / 2

	// ** ������ ���
	//	1 / 2

	//	3.1
	cout << "&result is" << &result << endl;
	cout << "result is" << result << endl;

	// ** ����� ���
	//&temp is0000008F186FFA88
	//Copy constructor called
	//&result is0000008F186FFBC8
	//result is 1 / 2
	// => &temp�� &result�� �ּҰ� �ٸ��� ������ ���縦 �߾���� �ߴ�.
	// 
	// ** ������ ���
	//&temp is 0000008F186FFA88
	//&result is 0000008F186FFA88
	//result is 1 / 2	
	// release ��忡���� �ּҰ� ���Ƽ� ���縦 �� �ʿ䰡 ����.

	// �̰����� RVO�� �����̴�.

	//=> ���� ������, ���� �����ڰ� ���� �ʱ�ȭ�� ���Ǿ�����, ��쿡 ���� ����� �Ǿ��� ���� �ְ� �����Ͽ� ���� ������ �Ǿ��� �� �ִ�.
	int z = 4;

	return 0;
}