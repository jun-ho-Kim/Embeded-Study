// class를 흔히 붕어빵을 찍는 틀에 비유하는 경우가 있다.
// 여러개의 붕어빵 즉 인스턴스들이 나올텐데 각 인스턴스들을 어떻게 구분할 수 있을까?
// 클래스 안에 숨어있는 this 포인터와 this 포인터를 사용하여 chaining member function(연쇄 호출)을 알아보자.

#include <iostream>
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id); // setID에는 this가 생략되어 있다.(this->setId(id)
		// ->는 class나 structure가 포인터인 경우에 memeber selection operation이다.
		//(*this).setID(id);

		cout << this << endl; // 자신의 주소를 출력
		// 000000CB315AF814 // Simple s1
		// 000000CB315AF834 // Simple s2
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

int main()
{
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	//  ** 클래스나 함수(setID, getID 등)를 인스턴스 별로 만들지 않는다.
	// Simple::setId(&s1, 4) 이렇게 넣어준다.()
	// Simple::setId(&s1, 4) == s2.setID(4) 이다. 문법상으로는  s2.setID(4) 가능
	// 각 인스턴스들이 각각 포인터를 가지고 있고 this라는 키워들르 사용하면 된다.
	cout << &s1 << " " << &s2 << endl; // 000000CB315AF814 000000CB315AF834

	int z = 3;

	return 0;
}