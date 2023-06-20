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

	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	bool operator ! () const // 문맥과 프로그램의 목적에 따라서 로직을 잘 결정하면 된다.
	{
		// !Cents(...)

		return (m_cents == 0) ? true : false;
	}

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;

		return out;
	}
};

int main()
{
	// - 연산자 오버로딩
	//Cents cents1(6);
	//Cents cents2(8);

	//cout << cents1 << endl;
	//cout << -cents1 << endl;
	//cout << -Cents(-10) << endl;

	// ! 연산자 오버로딩
	Cents cents1(6);
	Cents cents2(0);

	cout << !cents1 << " " << !cents2 << endl; // 0 1

	int z = 5;

	return 0;
}