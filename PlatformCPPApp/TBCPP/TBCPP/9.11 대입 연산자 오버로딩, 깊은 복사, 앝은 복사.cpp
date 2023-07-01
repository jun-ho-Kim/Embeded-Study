//동적할당된 메모리에 대한 포인터 변수를 멤버로써 가지고 있는 클래스의 경우 복사를 하거나 대입을 할 때
// 깊은 복사인지 앝은 복사인지에 따라 대입 연산자 오버로딩, 복사 생성자 구현이 까다로워진다. 그 점에 대해서 설명을 할 것이다.
// 최근에는 std::vector나 std::string을 가져다쓰는 방식으로 구현을 하기 때문에 이 문제에 대해 직접 고민을 하는 경우는 없을 것이다.
// 다만, 이런 문제가 반드시 존재한다는 것을 알고 다른 언어를 사용할 때 이 언어가 이 문제를 사용자가 모르게 감쳐놓았다는 것을 알고 공부하면 깊이 공부할 수 있을 것이다.

#include <cassert>
#include <iostream>
using namespace std;

//5.
// std::string; 을 사용하면 된다.
//std::string도 클래스이기 떄문에 기능을 추가할거면 1.상속을 받는 방법 2. MyString 클래스 내
// shallow copy, deep copy 등등 어려운 문제점들을 피할 수 있다.



class MyString
{
	//private:
public:
	char* m_data = nullptr;
	int m_length = 0;

	// 5. 이론
	// std::string;
	// 대부분에 요즘에 나온 언어에서는 클래스 내에 std::string data;를 선언하여 사용한다.
	//// 이런 문제가 발생할 수 있으며 스택과 힙이 분리되어 있기 때문에 문제가 발생할 여지가 있으며
	//// 각각의 언어에서는 이렇게 해결했고 C++에서는 대비책을 세울 수 있고 다른 방법을 사용할 수 있다.

public:
	MyString(const char* source = "")
	{
		//assert(sorce);

		m_length = std::strlen(source) + 1;
		m_data = new char[m_length]; // 동적할당으로 

		for (int i = 0; i < m_length; i++)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	//2.
	
	MyString(const MyString& source)
	{
		cout << "Copy constructor " << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
	}
	
	MyString& operator = (const MyString& source)
	{
		//shallow copy 
		//this->m_data = source.m_data;
		//this->m_length = source.m_length;
		// 동적 할당된 메모리와 연관이 되어 있으면 이렇게 코드를 짜는 것이 문제가 생긴다.

		cout << "Assignment operator " << endl;

		if (this == &source) //prevent self-assignment
			// 자기에게 대입을 하는 경우 컴파일러에서 문제가 생긴다. 그래서 이를 방지하기 위한 예외처리이다.
			return *this;

		delete[] m_data;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
	}
	//~2.
	~MyString()
	{
		delete[] m_data;
	}
	
	//4.
	// 복사 생성자를 구분할 여력이 없는 경우
	// 물론 가장 좋은 방법은 복사 생성자를 사용하는 것이다.
	// 내가 구현한 복사 생성자를 사용하지 않을 거면 아예 생성자를 사용하면 안되게 막아버리자.
	//MyString(const MyString& source) = delete;
	// 이 방법은 차선책이다.

	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

int main()
{
	//1.~2.
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl; // 000001FF5E98A5A0
	cout << hello.getString() << endl;	// Hello

	{
		// 여기 scope를 벗어나면 copy.m_data의 주소는 delete 된다.
		MyString copy = hello; // 생성되고 있으면 복사 생성자를 생성

		// copy = hello // 대입 연산자가 호출
		cout << (int*)copy.m_data << endl;	// 1. 000001FF5E98A5A0 2. 0000024EF42AEE40
		// hello와 copy 인스턴스의 주소는 같다. 복사생성자를 생성했기 때문
		cout << copy.getString() << endl;	// Hello
	}

	// 2. Copy constructor
	cout << hello.getString() << endl; // 1. 硼硼硼硼硼 2. Hello
	// copy에서 주소를 복사해서 heap에는 Hello가 한 개 밖에 없는데 
	// copy 인스턴스의 scope가 끝나니 
	// 동적 메모리할당을 사용하는 경우에 멤버에 포인터가 있는데 copy contructor나 assignment operator를 오버로딩할 때 주의해야한다.

	
	//3. Copy constructor와 Assignment operator가 생성될 때
	/*
	MyString hello("Hello");
	//이렇게 선언하면 Copy constructor
	MyString str1(hello); // MyString str1 = hello; //Copy constructor
	

	MyString str2;
	//이렇게 선언하면 Assignment operator
	str2 = hello; // Assignment operator

	cout << (int*)hello.m_data << endl;	// 00000217DAE1E8F0
	cout << hello.getString() << endl;	// Hello
	*/



	int z = 5;

	return 0;
}


// 깊은 복사와 앝은 복사의 차이점, 앝은 복사로 인해 생길 수 있는 문제점,  default copy consturctor가 만들어주는 앝은 복사가 깊은 복사와 차이가 있고
// 동적할당 메모리를 사용할 때는 문제가 생길 수 있다.