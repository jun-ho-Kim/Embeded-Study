// 1. �񱳿����� �����ε�
// 2. �񱳿����� �����ε� �ϸ鼭 ���ͷ� sorting�ϱ�

// if���ȿ� user defiened data type�� ����Ϸ��� �ݵ�� �����Ǿ�� �ϰ� std �̿��Ͽ� sorting �� �� ũ�� �� �����ڰ� �ݵ�� ������ �Ǿ� �־�� �Ѵ�.
// �� �� ���� ���ַ� ���캸��.

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
	// std::sort�� ����� ���� >�� �ƴ� <�� ����ؾ��Ѵ�.(less than�� ������ �Ǿ�� �Ѵ�.
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

	// �Ʒ��� ���� ���ϱ� ���ؼ��� �񱳿����ڸ� ����ؾ��Ѵ�. �׷��� ������ ������ �߻��Ѵ�.
	if (cents1 == cents2)
		cout << "Equal " << endl;


	// �񱳿����� �����ε� �ϸ鼭 ���ͷ� sorting�ϱ�
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
		
	// �񱳿����� <�� ���������� ������ ������ �߻�

	int z = 5;

	return 0;
}