#include <iostream>
using namespace std;

class Something
{
private:
	int m_i;
	double m_d;
	char m_c;
	int m_arr[5]; // C11���� arr�� �ʱ�ȭ ����

public:
	Something()
		: m_i(1), m_d(3.14), m_c('a'), m_arr{1,2,3}
		//: m_i{1}, m_d{3.14}, m_c{'a'} // �̷��� �ʱ�ȭ�ϴ� ��� �� ��ȯ�� �ȵȴ�.
	{
		//m_i = 1;
		//m_d = 3.14;
		//m_c = 'a';
	}
};

int main()
{
	Something som;
}