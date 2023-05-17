#include <iostream>
#include <string>

using namespace std;

// 생성자가 다른 생성자를 사용하는 것을 위임생성자라고 한다.

class Student
{
private:
	int m_id;
	string m_name;

public:
	//Student(const string& name_in)
	//	: m_id(0), m_name(name_in)
	//{}

	Student(const string& name_in)
		//: m_id(0), m_name(name_in) // 위임생성자를 사용하지 않는 경우
		: Student(0, name_in) // 위임생성자: 생성자가 다른 생성자를 가져다 사용하는 것 // C++11부터 가능
	{}

	Student(const int& id_in, const string& name_in)
		: m_id(id_in), m_name(name_in)
	{
		// init(id_in, name_in); // (위임)생성자를 사용하지 않고 멤버변수를 초기화 하는 방법 // 나중에 살펴보자.
		// 강사님은 이 방식으로 많이 코드를 작성한다.
	}

	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};

int main()
{
	Student str1(0, "Jack Jack");
	str1.print();

	// 어떤 기능을 하는 코드(초기화)는 한 곳에서만 나와야 한다.
	// m_name에 대입하는 곳은 한 곳이여야만 하며  초기화도 한 곳에서 해주는 것이 좋다.
	// m_id 처럼 변수를 상수로 초기화 하면 나중에 코드를 변경하고자 할 때 고생한다.
	// 생성자가 생성자를 가져다 사용할 수 있다.
	
	Student str2("Dash");
	str2.print();

	return 0;
}