// ���� �����ڴ� �������̳� �������̳Ŀ� ���� ������ ���� �ٸ���.
// ���������� �����ε� ����� ���캸��.

// ����
// prefix(������)
// postfix(������)

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
	Digit operator ++(int) // ���������ڴ� ()�ȿ� int ���� �ƹ��ų� �־��ش�. �ܿ����Ѵ�.
		// postfix�� �Ķ���Ϳ� ���̷� �ƹ� ���̳� �־��ش�.
		// postfix�� return�� ���� ������ ���� �ٲپ���ϴ� ������ �����̴�.
		// �׷��� tmp�� ����Ѵ�.
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
	// �Ϲ����� ���������� ���
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

	//����: Digit Ŭ���� ������ 9���� 1�� �������� 0�� �ǰ� 0���� 1�� ���� 9�� �Ǵ� �����̴�.

	int z = 5;

	return 0;
}