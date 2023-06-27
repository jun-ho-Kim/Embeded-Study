// ���α׷����� ���Ǹ� ���ؼ� �����ڸ� ��ȯ�����ִ� Converting constructor�� ���ؼ� �����ϰ�
// ��ȯ �����ڸ� ��� ���ϵ��� ���ƹ����� explicit Ű���忡 ���� �˾ƺ��� Ư���� �����ڸ� ������� ���ϰ� ���������� delete Ű���嵵 ���캸��.
// ������ �� ����ϴ� delete�ʹ� �ٸ� �ǹ��̴� ��������.

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

	//2. explicit�� ����ϸ� �����ڰ� converting constructor�ν��� ����� ���� ���ϰ� �ȴ�.
	explicit Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	// 3. delete�� �ش� �Լ��� �������ȱ� ������
	// ���� ���� �ϸ鼭 ������� ���� ������� ����� ���� ������ ��� ���� ����Ѵ�.
	// �� �ܿ��� �ڵ� consersion �ǰų� ����ȯ �Ǵ� ���� ���� �� ����Ѵ�.
	// ���� ��� ���α׷����� �Ѵٸ� ���� ����ؾ� �� ���̴�.
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
	//doSometing(7); // explicit ��� �� �̿� ���� �ڵ� ��� �Ұ�
	// explicit�� ��Ȯ�ϰ� �϶�� ���̴�.

	doSometing(frac); // doSometing(Fraction(7)


	// 3.
	// Fraction frac("c"); // Error

	int z = 4;

	return 0;
}