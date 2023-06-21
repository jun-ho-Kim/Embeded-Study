// 1. 비교연산자 오버로딩
// 2. 비교연산자 오버로딩 하면서 벡터로 sorting하기

// if문안에 user defiened data type을 사용하려면 반드시 구현되어야 하고 std 이용하여 sorting 할 때 크기 비교 연산자가 반드시 구현이 되어 있어야 한다.
// 이 두 가지 위주로 살펴보자.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend bool operator < (const Cents& c1, const Cents& c2) 
	// std::sort를 사용할 때는 >가 아닌 <를 사용해야한다.(less than이 구현이 되어야 한다.
	{
		return c1.m_cents < c2.m_cents;
	}

	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}


	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;

		return out;
	}
};

int main()
{

	//int a = 3, b = 3;
	//if (a == b)
	//	cout << "Equal" << endl;

	Cents cents1(6);
	Cents cents2(0);

	cout << std::boolalpha; // 0 1

	// 아래와 같이 비교하기 위해서는 비교연산자를 사용해야한다. 그렇지 않으면 에러가 발생한다.
	if (cents1 == cents2)
		cout << "Equal " << endl;


	// 비교연산자 오버로딩 하면서 벡터로 sorting하기
	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
		arr[i].getCents() = i;

	std::random_shuffle(begin(arr), end(arr));

	for (auto& e : arr)
		cout << e << " ";

	cout << endl;

	std::sort(begin(arr), end(arr));

	for (auto& e : arr)
		cout << e << " ";
		
	// 비교연산자 <를 선언해주지 않으면 에러가 발생

	int z = 5;

	return 0;
}