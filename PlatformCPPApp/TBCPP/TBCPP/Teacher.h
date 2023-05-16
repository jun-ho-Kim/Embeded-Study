#pragma once

#include "Person.h"

// student와 teacher에 공통점이 있고 공통점을 묶에서 일반화 시킬수 있는 객체를 만들자.

class Teacher : public Person
{
public:
	std::string m_name;
	//TODO: more members like home address, salary, age, evalution
	Teacher(const std::string& name_in = "No Name")
		//:m_name(name_in)
		: Person(name_in)// 상속 후에
	{
	}

	void teach()
	{
		std::cout << getName() << " is teaching " << std::endl;
	}


	//void setName(const std::string& name_in)
	//{
	//	m_name = name_in; // private는 단순히 내 클래스에 속해 있는 variable들이 밖에서 접근이 안되게 막을 뿐 아니라 자식도 접근하지 못하게 한다. 

	//}

	friend std::ostream& operator << (std::ostream& out, const Teacher& teacher)
	{
		out << teacher.m_name;
		//out << teacher.getName();
		return out;
	}
};