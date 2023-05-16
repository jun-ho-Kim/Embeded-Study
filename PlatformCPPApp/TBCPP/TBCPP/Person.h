#pragma once

#include <iostream>
#include <string>

class Person
{
private:
	std::string m_name;
	// 멤버 변수를  private로 하면 신경을 써주어야 하지만 장기적으로는 코드를 깔끔하고 우아하게 유지하기 위한 방법이다.
public:
	// 생성자정도는 구현해줘야 되는 번거로움이 있지만 생성자를 제외하고 중복된 것을 없앨 수 있다.

	//Person()
	//	: m_name("No Name")
	//{}

	Person(const std::string& name_in="No Name")
		: m_name(name_in)
	{}

	void setName(const std::string& name_in)
	{
		m_name = name_in; // private는 단순히 내 클래스에 속해 있는 variable들이 밖에서 접근이 안되게 막을 뿐 아니라 자식도 접근하지 못하게 한다. 
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