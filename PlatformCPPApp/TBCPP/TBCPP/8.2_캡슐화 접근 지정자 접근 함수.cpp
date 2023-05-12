#include <iostream>

using namespace std;

//struct Date
//{
//	int m_month;
//	int m_day;
//	int m_year;
//};

class Date
{
	int m_month;
	int m_day;
	int m_year;
	//default���� private
public: //access specifier(���� ������) - public, private, proteced
	// private�� ������� �����ϱ� ���ؼ��� access function(���� �Լ�)�� �ʿ�
	// ���� �ҽ� �۾��� �ϰų� ����� ����Ʈ��� ����ϴ� ��쿡�� ���� �����ڸ� �����ϰ� ��Ű�� ���� ����.
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}
	void setMonth(const int& month_input)
	{
		m_month = month_input;
	}
	// setDay, setYear ... // setters

	const int& getMonth() // getters
	{
		return m_month;
	}
	const int& getDay() // getters
	{
		return m_day;
	}

	void copyFrom(const Date& original)
	{
		// Date�� ��������� ������ �� �ִ�.
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}

};

int main(){
	Date today;//{ 8, 4, 2025 };
	today.setDate(8, 4, 2025);
	today.setMonth(10);

	cout << today.getDay() << endl;
	//today.m_month = 8;
	//today.m_day = 4;
	//today.m_year = 2025;

	Date copy;
	copy.copyFrom(today); // Ŭ������ �ν��Ͻ��� ����
	// ��������� public���� �ϰ� �Ǹ� Ŭ���� �� ����������� �����ϴ� ��쿡 �ϳ��� �� �ٲ��־�� �ϴµ�
	// priavte�� �����ϴ� ��� access function�� �������ָ� �ȴ�.
	return 0;
}