#pragma once

#include <iostream>
#include <string>

class Person
{
private:
	std::string m_name;
	// ��� ������  private�� �ϸ� �Ű��� ���־�� ������ ��������δ� �ڵ带 ����ϰ� ����ϰ� �����ϱ� ���� ����̴�.
public:
	// ������������ ��������� �Ǵ� ���ŷο��� ������ �����ڸ� �����ϰ� �ߺ��� ���� ���� �� �ִ�.

	//Person()
	//	: m_name("No Name")
	//{}

	Person(const std::string& name_in="No Name")
		: m_name(name_in)
	{}

	void setName(const std::string& name_in)
	{
		m_name = name_in; // private�� �ܼ��� �� Ŭ������ ���� �ִ� variable���� �ۿ��� ������ �ȵǰ� ���� �� �ƴ϶� �ڽĵ� �������� ���ϰ� �Ѵ�. 
	}

	std::string getName()
	{
		return m_name;
	}

	void doNothing()
	{
		std::cout << m_name << " is doing nothing " << std::endl;
	}

};