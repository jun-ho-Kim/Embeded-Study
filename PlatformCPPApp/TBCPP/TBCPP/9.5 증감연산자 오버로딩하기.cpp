// 증감 연산자는 전위형이냐 후위형이냐에 따라 성질이 많이 다르다.
// 증감연산자 오버로딩 방법을 살펴보자.

// 목차
// prefix(전위형)
// postfix(후위형)

#include <iostream>
using namespace std;

class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) { m_digit = digit; }

	// prefix
	Digit& Digit::operator ++()
	{
		++m_digit;
		return *this;
	}

	//postfix
	Digit operator ++(int) // 후위연산자는 ()안에 int 같이 아무거나 넣어준다. 외워야한다.
		// postfix는 파라미터에 더미로 아무 값이나 넣어준다.
		// postfix는 return을 해준 다음에 값을 바꾸어야하는 희한한 구조이다.
		// 그래서 tmp를 사용한다.
	{
		Digit temp(m_digit);
		++(*this);
		return temp;
	}

	friend std::ostream& operator << (std::ostream& out, const Digit& d)
	{
		out << d.m_digit;

		return out;
	}
};

int main()
{
	// 일반적인 증감연산자 사용
	int a = 10;

	cout << ++a << endl;// 11
	cout << a << endl;	// 11
	cout << a++ << endl;// 11
	cout << a << endl;	// 12

	Digit d(9);

	cout << ++d << endl;
	cout << d << endl;

	cout << d++ << endl;
	cout << d << endl;

	//과제: Digit 클래스 예제는 9에서 1이 더해지면 0이 되고 0에서 1으 빼면 9가 되는 예제이다.

	int z = 5;

	return 0;
}