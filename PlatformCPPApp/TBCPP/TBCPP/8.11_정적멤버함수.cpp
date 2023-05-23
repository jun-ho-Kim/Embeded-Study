#include <iostream>
#include <string>

using namespace std;

// 같은 클래스의 모든 인스턴스에서 접근이 가능하다.
// 
// staitc 멤버 함수 vs 일반함수의 this 포인터 사용
//// static 멤버 함수는 this 포인터를 사용할 수 없다.

// static 멤버함수 선언 vs 일반 멤버함수 선언

// static 멤버 variable은 contructor에 사용 불가

//_init 클래스를 사용하여 멤버 변수 초기화(cpp에서는 간접적인 방법으로)

class Something
{
	/*
	//case 1.
	static int s_value; // 같은 클래스의 모든 인스턴스에서 접근이 가능하다.
	int getValue()
	{
		return s_value;
	}
	*/

// case 2.
public:
	class _init
	{
	public:
		_init()
		{
			s_value = 1234;
		}
	};


private:
	static int s_value;
	int m_value;

	static _init s_initializer; // inner 클래스를 static으로 선언
public:

	Something()
		: m_value(123) //s_value(1024); // Error
	{}
	//_init 클래스를 사용하여 멤버 변수 초기화
	// 클래스 안에 클래스


	static int getValue()
	{
		return s_value;
		//return this->m_value;  // Error
		// static 멤버 함수는 this 포인터를 사용할 수 없다.
	}

	int temp()
	{
		return this->s_value;
		// this를 사용한다는 것은 특정 인스턴스의 주소를 가져와 사용하겠다는 의미이다.
	}
};

int Something::s_value = 1024;
Something::_init s_initializer; // inner 클래스의 생성자가 호출되고 s_value가 초기화됨

int main()
{
	//case 1.
	/*
	cout << Something::s_value << endl; 
	// 클래스가 정의가 되기 전에도 static 멤버 변수는 사용될 수 있다.

	Something s1;
	cout << s1.getValue() << endl;
	cout << s1.s_value << endl;
	*/


	//cae 2
	cout << Something::getValue() << endl;

	Something s1, s2;
	cout << s1.getValue() << endl;

	// int (Something::*fptr1)() = s1.temp; // Error 
	// 클래스 함수는 인스턴스 별로 가지고 있는 것이 아니라 하나의 주소에서 가져다 사용하기 때문에 에러가 발생

	// 클래스함수를 사용하려면 다음과 같이 사용해라.
	int (Something:: * fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl; 
	// Something이라는 클래스에 멤버 함수 temp에 포인터를 가지고 있는데 포인터 위치에 있는 함수를 실행을 시킬 때 
	//(이어서) s2라는 인스턴스의 포인터를 넘겨주고 s2라는 인스턴스의 this 포인터를 가져와 작동을 하는 상태
	// s2가 없으면 temp 함수는 동작하지 않는다. non-static 멤버 함수는 인스턴스에 종속이 있는 형태로 구현되어 있어서 
	// 인스턴스가 없으면(this 포인터가 없으면) 작동이 안된다.

	// int (Something:: * fptr2)() = &Something::getValue; // Error
	int (* fptr2)() = &Something::getValue; // static 멤버 함수는 특정 인스턴스와 상관없이 실행시킬 수 있다.(static 멤버 변수와 같이)

	cout << fptr2() << endl;

	// function의 주소는 특정 인스턴스 주소에 묶여있지 않다.

	int z = 1;

	return 0;
}
