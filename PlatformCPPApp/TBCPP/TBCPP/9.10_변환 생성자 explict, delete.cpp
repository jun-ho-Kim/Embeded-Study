// 프로그래머의 편의를 위해서 생성자를 변환시켜주는 Converting constructor에 대해서 설명하고
// 변환 생성자를 사용 못하도록 막아버리는 explicit 키워드에 대해 알아보고 특별한 생성자를 사용하지 못하게 지워버리는 delete 키워드도 살펴보자.
// 동적할 때 사용하던 delete와는 다른 의미이니 참고하자.

#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	// 1.
	//Fraction(int num = 0, int den = 1)
	//	: m_numerator(num), m_denominator(den)
	//{
	//	assert(den != 0);
	//}

	//2. explicit을 사용하면 생성자가 converting constructor로써의 기능을 하지 못하게 된다.
	explicit Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	// 3. delete는 해당 함수를 지워버렸기 때문에
	// 버전 업을 하면서 사람들이 예전 방식으로 사용할 것이 걱정될 경우 보통 사용한다.
	// 그 외에도 자동 consersion 되거나 형변환 되는 것을 막을 때 사용한다.
	// 주의 깊게 프로그래밍을 한다면 종종 사용해야 할 것이다.
	Fraction(char) = delete;

	Fraction(const Fraction& fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;

		return out;
	}
};


void doSometing(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);
	// 1.
	//doSometing(frac); // doSometing(Fraction(7)) // doSometing(7)

	// 2.
	//doSometing(7); // explicit 사용 시 이와 같은 코드 사용 불가
	// explicit은 명확하게 하라는 뜻이다.

	doSometing(frac); // doSometing(Fraction(7)


	// 3.
	// Fraction frac("c"); // Error

	int z = 4;

	return 0;
}