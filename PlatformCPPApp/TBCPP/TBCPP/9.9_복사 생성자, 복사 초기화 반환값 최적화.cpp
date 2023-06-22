// 복사 생성자, 복사 초기화 이 두 가지를 사용할 때 RVO(Return Value Optimization)이 어떻게 작동하나 확인해보자

#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	// copy constructor를 private에 사용하면 외부에서 복사 생성자를 호출 할 수 없다.
	//Fraction(const Fraction& fraction) // copy constuctor: 복사 생성자는 자기와 똑같은 타입의 인스턴스가 들어오면 복사한다.
	//	: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	//{
	//	cout << "Copy constructor called" << endl; // 복사 생성자가 얼마나 자주 호출되는지 확인하기 위해서 cout 추가
	//}

public:
	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	// 지금은 간단하지만 나중에 깊은 복사, 앝은 복사할 때 더 살펴 볼 것이다.
	// copy constructor를 private에 사용하면 외부에서 복사 생성자를 호출 할 수 없다.
	Fraction(const Fraction& fraction) // copy constuctor: 복사 생성자는 자기와 똑같은 타입의 인스턴스가 들어오면 복사한다.
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl; // 복사 생성자가 얼마나 자주 호출되는지 확인하기 위해서 cout 추가
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
	//= Fraction fr_copy = frac; // 위에 선언과 방법이 같다.

	
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
	위와 같이 선언하면 컴파일러가 Fraction(3, 10)의 Fraction을 빼고 컴파일을 한다.
	//3 / 5
	//	3 / 10
	*/

	//	3.
	Fraction result = doSomething();

	//cout << result << endl;
	// ** 디버그 모드
	//Copy constructor called
	//	1 / 2

	// ** 릴리즈 모드
	//	1 / 2

	//	3.1
	cout << "&result is" << &result << endl;
	cout << "result is" << result << endl;

	// ** 디버그 모드
	//&temp is0000008F186FFA88
	//Copy constructor called
	//&result is0000008F186FFBC8
	//result is 1 / 2
	// => &temp와 &result가 주소가 다르기 때문에 복사를 했었어야 했다.
	// 
	// ** 릴리즈 모드
	//&temp is 0000008F186FFA88
	//&result is 0000008F186FFA88
	//result is 1 / 2	
	// release 모드에서는 주소가 같아서 복사를 할 필요가 없다.

	// 이것을이 RVO의 성질이다.

	//=> 복사 생성자, 복사 생성자가 복사 초기화에 사용되어지고, 경우에 따라서 사용이 되어질 수도 있고 컴파일에 따라 생략이 되어질 수 있다.
	int z = 4;

	return 0;
}