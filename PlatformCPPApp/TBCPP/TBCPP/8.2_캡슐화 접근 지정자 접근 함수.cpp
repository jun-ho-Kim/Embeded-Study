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
	//default값이 private
public: //access specifier(접근 지정자) - public, private, proteced
	// private의 멤버들을 접근하기 위해서는 access function(접근 함수)가 필요
	// 오픈 소스 작업을 하거나 상업용 소프트웨어를 사용하는 경우에는 접근 지정자를 엄격하게 지키는 것이 좋다.
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
		// Date에 멤버변수에 접근할 수 있다.
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
	copy.copyFrom(today); // 클래스의 인스턴스를 복사
	// 멤버변수를 public으로 하게 되면 클래스 내 멤버변수명을 변경하는 경우에 하나씩 다 바꿔주어야 하는데
	// priavte로 접근하는 경우 access function만 수정해주면 된다.
	return 0;
}