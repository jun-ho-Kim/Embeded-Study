#include <iostream>
#include <string>

using namespace std;
//-여러 개의 클래스가 복잡하게 상호작용하며 돌아가는 프로그램에서는
//클래스간의 상호작용을 깔끔하게 정의하는게 쉽지 않을 수 있다.
//- 객체지향의 기본원칙 인캡슐레이션을 유지하기 위해서 여러가지 부가적인 요소가 발생할수 있는데
//친구 함수, 친구 클래스 등을 활용하면 좀 더 깔끔하게 정리하면서 원하는 목적을 달성할 수 있다.

/*
// case 1

class B; // forward declaration

class A
{
private:
	int m_value = 1;
	friend void doSomething(A& a, B& b);
};
class B
{
private:
	int m_value = 2;

	friend void doSomething(A& a, B& b);
};
*/

/*
// case 1
void doSomething(A& a)
{
	cout << a.m_value << endl;
	// 복잡한 프로그래밍을 하다보면 위와 같이 코딩을 할 때가 있다. 특히 연산자 오버로딩을 할 때 많이 발생
	// 연산자 오버로딩에서 friend를 많이 사용한다.
	// m_value를 private -> public으로 바꿀 수 있지만 객체지향의 원칙과 반대된다.
	// 그래서 friend를 사용한다.
	//friend 함수는 특정 클래스의 private 멤버에 접근할 수 있다.
}

//클래스가 2개일 때 어떤 함수가 2개의 클래스에 모두 접근하는 방법

void doSomething(A& a, B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
	// forward declaration를 사용해주어야 A 클래스 사용가능
}
*/

// 클래스가 다른 클래스의 멤버변수를 사용하고자 할 때

class A;

class B
{
private:
	int m_value = 2;
public:

};

class A
{
private:
	int m_value = 1;
	//friend class B;
	// 특정 멤버 함수에게만 friend를 사용하고 싶을 때
	friend void B::doSomething(A& a);
};

void B::doSomething(A& a)
{
	cout << a.m_value << endl;
}



int main()
{
	/*
	//case 1
	A a;
	B b;

	doSomething(a, b);
	*/

	//case 2
	A a;
	B b;
	b.doSomething(a);

	return 0;
}