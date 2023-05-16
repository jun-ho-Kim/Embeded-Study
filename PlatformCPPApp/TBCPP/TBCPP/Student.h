#pragma once

#include "Person.h"

class Student : public Person
{
private:
	int m_intel; // intelligence;

	// TODO: add more members like address, phone, favorate food, habits, ...

public:
	Student(const std::string &name_in = "No Name", const int &intel_in = 0)
		//: m_name(name_in), m_intel(intel_in)
		// Person�� m_name�� �޾Ƽ� ����� �� ������ ������ å���� Person�� �ִ�.
		: Person(name_in), m_intel(intel_in) // ��� �Ŀ�
	{}

	//void setName(const std::string& name_in)
	//{
	//	//m_name = name_in; // private�� �ܼ��� �� Ŭ������ ���� �ִ� variable���� �ۿ��� ������ �ȵǰ� ���� �� �ƴ϶� �ڽĵ� �������� ���ϰ� �Ѵ�. 
	//	std::cout << getName() << std::endl;
	//}

	//std::string getName()
	//{
	//	//return m_name;

	//	return getName();
	//}

	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}
	int getIntel()
	{
		return m_intel;
	}

	void study()
	{
		std::cout << getName() << " is studying " << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Student& student)
	{
		//out << student.m_name << " " << student.m_intel;

		return out;
	}
};