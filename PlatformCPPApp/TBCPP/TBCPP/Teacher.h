#pragma once

#include "Person.h"

// student�� teacher�� �������� �ְ� �������� ������ �Ϲ�ȭ ��ų�� �ִ� ��ü�� ������.

class Teacher : public Person
{
public:
	std::string m_name;
	//TODO: more members like home address, salary, age, evalution
	Teacher(const std::string& name_in = "No Name")
		//:m_name(name_in)
		: Person(name_in)// ��� �Ŀ�
	{
	}

	void teach()
	{
		std::cout << getName() << " is teaching " << std::endl;
	}


	//void setName(const std::string& name_in)
	//{
	//	m_name = name_in; // private�� �ܼ��� �� Ŭ������ ���� �ִ� variable���� �ۿ��� ������ �ȵǰ� ���� �� �ƴ϶� �ڽĵ� �������� ���ϰ� �Ѵ�. 

	//}

	friend std::ostream& operator << (std::ostream& out, const Teacher& teacher)
	{
		out << teacher.m_name;
		//out << teacher.getName();
		return out;
	}
};