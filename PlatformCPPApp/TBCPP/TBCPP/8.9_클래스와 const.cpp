#pragma once

#include <iostream>
using namespace std;

class Something
{
public:

	// Copy Consturctor
	// ����ڰ� ���������� �ʾƵ� Copy Construct�� �����Ǿ� �ִ�.
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

// reference�� Ŭ���� �ޱ�
//void print(Something &st)
//{
//	cout << &st << endl; // 00000009FD91FB14
//	cout << st.m_value << endl; // 0
//}


int main()
{
	/*
	const int i = 0;
	// i = 1; // Error //const��

	const Something something; // something is obeject
	// something.setValue(3);  // Error
	// something�� const�̱� ������ ������ �� �� ���� ������ Error �߻�
	// something�� const�̱� ������ ������ �� �� ���� ������ Error �߻�
	// something

	// something.getValue(); // Error �߻�
	// int getValue() const { return m_value; } �� ������־�� ��.

	// const�� ���� ����� �� ������ ����ϴ� ���� ����.
	*/

	Something something;

	cout << &something << endl; //00000009FD91FB14

	print(something);

	int z = 3;

	return 0;
}