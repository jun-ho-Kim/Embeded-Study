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
	// i = 1; // Error //const��

	const Something something; // something is obeject
	// something.setValue(3);  // Error
	// something�� const�̱� ������ ������ �� �� ���� ������ Error �߻�
	// something�� const�̱� ������ ������ �� �� ���� ������ Error �߻�
	// something

	return 0;
}