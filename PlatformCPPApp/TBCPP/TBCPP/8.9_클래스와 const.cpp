#pragma once


#include <iostream>
using namespace std;

class Something
{
public:
	int m_value = 0;
	
	void setValue(int value) { m_value = value; }
	int getValue() { return m_value; }
};

int main()
{
	const int i = 0;
	// i = 1; // Error //const라서

	const Something something; // something is obeject
	// something.setValue(3);  // Error
	// something은 const이기 때문에 변경이 될 수 없기 때문에 Error 발생
	// something은 const이기 때문에 변경이 될 수 없기 때문에 Error 발생
	// something

	return 0;
}