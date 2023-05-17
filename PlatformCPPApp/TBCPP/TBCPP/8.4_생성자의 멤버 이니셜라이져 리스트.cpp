#include <iostream>
#include <string>

// 보통은 멤버 초기화 리스트 또는 멤버 초기자 리스트로 변역됨

// 정리
// 생성자의 멤버 이니셜라이져 리스트
// 1. 멤버 변수 선언 시 초기화 해주기
// 2. 생성자 호출 시 생성_1
	/*
	Something()
	: m_i(1), m_d(3.14), m_c('a')
	: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b{ m_i - 1 }
	*/
// 3. 생성자 호출 시 생성_2
	/*
	Something()
	//: m_i(1), m_d(3.14), m_c('a')
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b{ m_i - 1 }
	{
		cout << "Something::ctor" << endl;
		//2.
		m_i = 2;
		m_d = 6.28;
		m_c = 'b';
	}
	*/

// 멤버변수 초기화 선언 시 우선 순위는
// 3. 생성자 호출 시 생성_2 > 2. 생성자 호출 시 생성_1 > 1. 멤버 변수 선언 시 초기화 해주기



using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in)
		:m_b(m_b_in)
	{
		cout << "Something::ctor" << endl;
	}
};

class Something
{
private:
	// non-static 멤버에서 멤버 변수 초기화 가능
	// but 생성자와 함께 멤버 변수 초기화를 동시해 해주는 경우 생성자의 값으로 초기화됨
	int m_i = 100;
	double m_d = 100.0;
	char m_c = 'F';
	int m_arr[5] = { 100, 200, 300, 400, 500 }; // C++11 이후에 array도 초기화 가능
	B m_b{ 1024 };

public:
	Something()
		//: m_i(1), m_d(3.14), m_c('a')
		: m_i{ 1 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1,2,3,4,5 }, m_b{ m_i - 1 }
	{
		cout << "Something::ctor" << endl;
		 //2.
			m_i = 2;
			m_d = 6.28;
			m_c = 'b';
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl;
	}
};

int main()
{
	Something some;
	some.print();

	int z = 4;

	return 0;
}