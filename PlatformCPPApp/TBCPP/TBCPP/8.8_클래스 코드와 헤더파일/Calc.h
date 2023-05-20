#pragma once
// 보통은 클래스 이름과 헤더파일의 이름을 같이 사용한다.

// 헤더파일에 using namespace std;를 사용하면 nclude하는 곳이 전부 영향을 받아서 헤더파일에는 사용하지 않는 것이 좋다.

#include <iostream>


class Calc
{
private:
	int m_value;
public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	void print()
	{
		using namespace std;
		cout << m_value << endl;
	}

	Calc& add(int value);
	Calc& sub(int value);
	Calc& mult(int value);
};