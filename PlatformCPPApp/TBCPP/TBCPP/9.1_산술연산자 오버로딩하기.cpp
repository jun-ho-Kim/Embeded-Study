#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public: 
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	//4. 클래스 내에 연산자 오버로딩
	friend Cents operator + (const Cents& c1, const Cents& c2)
	{
		return Cents(c1.getCents() + c2.getCents());
	}

	//5. friends를 멤버로 바꾸어서 사용
	// c1은 this를 사용해서 접근해야 한다.
	Cents operator + (const Cents& c2)
	{
		return Cents(this->getCents() + c2.getCents());
	}
};

//1. 연산자 오버로딩을 사용하기 전 코드(return 값을 받아서 사용)
//void add(const Cents& c1, const Cents& c2, Cents &c_out)
//{
//	c_out.getCents() = c1.getCents() + c2.getCents();
//
//}

//2. add 함수를 산술연산자 있는 버전으로 수정
Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}


// 3. 연산자 오버로딩 사용
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.getCents() + c2.getCents());
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	//1.
	//Cents sum;
	//add(cents1, cents2, sum);
	//cout << sum.getCents() << endl;

	//2.
	//cout << add(cents1, cents2).getCents() << endl;

	//3.
	cout << (cents1+ cents2 + Cents(6)).getCents() << endl;


	// int i = 6; j = 8; cout << i+j << endl;

	// 연산자 오버로딩은 +, -, *, / 다 할 수 있다.
	// ? :(삼항연산자), sizeof, ::, ., .* 는 연산자 오버로딩이 되지 않는다.
	// * 연산자 오버로딩을 하여도 연산자 우선순위는 그대로이다. 
	// 직관적으로 알기 어려운 것은 오버로딩하면 위험하다.

	// ^ 연산자는 우선순위가 매우 낮기 때문에 다른 기능을 오버로딩하려면 () 를 사용해야해서 오버로딩을 하지 않는 것이 좋다.


	return 0;
}