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

	Fraction(const int& num_in = 3, const int& den_in = 1)
	{
		m_numerator = num_in;
		m_denominaotr = den_in;
	}
	/*
	// case1 생성자를 파라미터에 초기화를 다른 오버로드 생성자랑 겹차지는 경우 에러 발생
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
	// 생성자의 파라미터가 하나도 없는 경우 ()를 생략한다.
	//Fraction frac;//{ 0,1 }; // int i {0}; 
	Fraction frac(1,3);//{ 0,1 }; // 초기화 해주는 경우

	// Fraction frac(); // Error //
	//Fraction frac; //case1 Error
	//frac.m_numerator = 0;
	//frac.m_denominaotr = 1;

	frac.print();


	///////////////////////
	First fir; // second가 먼저 생성된 후 first가 생성된다.
	//second가 first의 멤버로 들어있기때문에
	//class Second contructor()
	//class First contructor()
	// 생성자가 private면 클래스가 생성이 안된다. 이를 사용하는 프로그램밍은 나중에 알아보자.
}