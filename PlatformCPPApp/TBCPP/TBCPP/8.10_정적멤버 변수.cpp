#include <iostream>
#include <string>

using namespace std;

class Something
{
public:
	// static int m_value = 1; // Error static 멤버 변수는 initailize를 할 수 없다.
	static int s_value;
	static const int const_value = 1; // 정적 멤버 변수에 const를 사용하려면 
	static constexpr int constexpr_value = 1; // 컴파일에 확실하게 값이 결정이 되어야 한다.
};

int Something::s_value = 1; // define in cpp

//// 정적변수가 함수 안에 존재하는 경우
//int generateID()
//{
//	static int s_id = 0;
//	return ++s_id;
//}

int main()
{
	/*
	// 정적멤버변수에 static을 사용하지 않는 경우
	Something st1;
	Something st2;

	st1.m_value = 2;

	cout << &st1.m_value << " " << st1.m_value << endl; // 0000006AEC4FFB04 2
	cout << &st2.m_value << " " << st2.m_value << endl; // 0000006AEC4FFB24 1

	//cout << generateID() << endl; // 1
	//cout << generateID() << endl; // 2
	//cout << generateID() << endl; // 3
	*/

	// 정적멤버변수에 static을 사용하는 경우
	cout << &Something::s_value << " " << Something::s_value << endl; // 00007FF73202D014 1

	Something st1;
	Something st2;

	st1.s_value = 2;

	cout << &st1.s_value << " " << st1.s_value << endl; // 00007FF73202D014 2
	cout << &st2.s_value << " " << st2.s_value << endl; // 00007FF73202D014 2

	cout << &Something::s_value << " " << Something::s_value << endl;  // 00007FF73202D014 2

	int z = 3;

	return 0;
}