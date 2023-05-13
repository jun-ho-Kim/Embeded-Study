#include <iostream>
using namespace std;

class Something
{
private:
	int m_i;
	double m_d;
	char m_c;
	int m_arr[5]; // C11에서 arr도 초기화 가능

public:
	Something()
		: m_i(1), m_d(3.14), m_c('a'), m_arr{1,2,3}
		//: m_i{1}, m_d{3.14}, m_c{'a'} // 이렇게 초기화하는 경우 형 변환이 안된다.
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