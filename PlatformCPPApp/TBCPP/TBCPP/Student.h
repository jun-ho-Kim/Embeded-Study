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
		// Person의 m_name을 받아서 사용할 수 있지만 관리의 책임은 Person에 있다.
		: Person(name_in), m_intel(intel_in) // 상속 후에
	{}

	//void setName(const std::string& name_in)
	//{
	//	//m_name = name_in; // private는 단순히 내 클래스에 속해 있는 variable들이 밖에서 접근이 안되게 막을 뿐 아니라 자식도 접근하지 못하게 한다. 
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