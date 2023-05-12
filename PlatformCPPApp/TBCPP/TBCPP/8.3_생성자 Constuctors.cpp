#include <iostream>
using namespace std;

//객체를 설계하다보면 생성되자마자 이런 속성이나 기능들을 수행해야하는데 이럴 때 생성자(Contructor)를 사용한다.

class Fraction
{
public:
	int m_numerator; // 분자
	int m_denominaotr; // 분모

public:
	// Franction() 생성자를 선언해주지 않으면 default 생성자가 있어서 실행된다.
	// 생성자는 선언하면 메모리에 자리를 잡으면 바로 실행된다.
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
	// 생성자의 파라미터가 하나도 없는 경우 ()를 생략한다.
	//Fraction frac;//{ 0,1 }; // int i {0};

	// Fraction frac(); // Error //

	Fraction frac(4, 5);
	//frac.m_numerator = 0;
	//frac.m_denominaotr = 1;

	frac.print();

	int y = 4;
}