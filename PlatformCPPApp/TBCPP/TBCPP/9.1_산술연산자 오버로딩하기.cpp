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

	//4. Ŭ���� ���� ������ �����ε�
	friend Cents operator + (const Cents& c1, const Cents& c2)
	{
		return Cents(c1.getCents() + c2.getCents());
	}

	//5. friends�� ����� �ٲپ ���
	// c1�� this�� ����ؼ� �����ؾ� �Ѵ�.
	Cents operator + (const Cents& c2)
	{
		return Cents(this->getCents() + c2.getCents());
	}
};

//1. ������ �����ε��� ����ϱ� �� �ڵ�(return ���� �޾Ƽ� ���)
//void add(const Cents& c1, const Cents& c2, Cents &c_out)
//{
//	c_out.getCents() = c1.getCents() + c2.getCents();
//
//}

//2. add �Լ��� ��������� �ִ� �������� ����
Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}


// 3. ������ �����ε� ���
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

	// ������ �����ε��� +, -, *, / �� �� �� �ִ�.
	// ? :(���׿�����), sizeof, ::, ., .* �� ������ �����ε��� ���� �ʴ´�.
	// * ������ �����ε��� �Ͽ��� ������ �켱������ �״���̴�. 
	// ���������� �˱� ����� ���� �����ε��ϸ� �����ϴ�.

	// ^ �����ڴ� �켱������ �ſ� ���� ������ �ٸ� ����� �����ε��Ϸ��� () �� ����ؾ��ؼ� �����ε��� ���� �ʴ� ���� ����.


	//�Ϲ����� �Լ�, friend �Լ�(1. Ŭ���� �ۿ� ���� 2. definition�� Ŭ���� ������ ����) ��� �Լ��� ����

	// ���ǻ���: ��� �Լ��� ������ �����ε��� �ߴµ� ����θ� �ؾ��ϴ� �����ڵ� �ִ�.
	//// =, [], (), -> �� ����Լ��θ� �����ε��� �ؾ��Ѵ�.
	// �� �̷� ��쿡�� �ܿ�� ���ٴ� ������ �˻��ϰų� �����Ϸ��� �����ϸ鼭 �ڵ��ϴ� ���� ����.

	int z = 4;

	return 0;
}