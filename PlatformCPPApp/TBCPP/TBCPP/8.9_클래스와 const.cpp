#pragma once

#include <iostream>
using namespace std;

class Something
{
public:

	// Copy Consturctor
	// 사용자가 지정해주지 않아도 Copy Construct는 생성되어 있다.
	Something(const Something& st_in)
	{
		m_value = st_in.m_value;

		cout << "Copy Constructor" << endl;
	}

	Something()
	{
		cout << "Constuctor" << endl; // 0
	}
	int m_value = 0;
	
	void setValue(int value) { m_value = value; }
	int getValue() const { return m_value; }
};

void print(Something st)
{
	cout << &st << endl; // 00000009FD91FAF0
	cout << st.m_value << endl; // 0
}

// reference로 클래스 받기
//void print(Something &st)
//{
//	cout << &st << endl; // 00000009FD91FB14
//	cout << st.m_value << endl; // 0
//}


int main()
{
	/*
	const int i = 0;
	// i = 1; // Error //const라서

	const Something something; // something is obeject
	// something.setValue(3);  // Error
	// something은 const이기 때문에 변경이 될 수 없기 때문에 Error 발생
	// something은 const이기 때문에 변경이 될 수 없기 때문에 Error 발생
	// something

	// something.getValue(); // Error 발생
	// int getValue() const { return m_value; } 로 명시해주어야 함.

	// const를 많이 사용할 수 있으면 사용하는 것이 좋다.
	*/

	Something something;

	cout << &something << endl; //00000009FD91FB14

	print(something);

	int z = 3;

	return 0;
}