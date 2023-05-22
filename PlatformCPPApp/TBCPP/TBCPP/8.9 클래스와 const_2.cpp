#include <iostream>
#include <string>

using namespace std;
// const overroading ~16:00
// const가 클래스와 사용이 될 때 어떻게 사용이 되는가
// 클래스의 인스턴스 혹은 오브젝트를 const를 만들 때 member variable이 const가 되는 것과 같은 효과가 나타난다.
// 멤버 함수가 const가 되는 것은 함수 안에서 멤버 variable을 바꾸지 않겠다라는 선언
// 코딩할 때 const로 만들 수 있는 것은 const로 작성하는 것이 논리 오류와 코딩 실수를 줄이는데 도움이 된다.
// Copy Consturction
// const overroad

class Something
{
public:
	string m_value = "default";

	const string& getValue() const // const reference 
	{ 
		cout << "const version" << endl;
		return m_value; 
	}
	string& getValue()  // non const reference
	{
		cout << "non-const version" << endl;
		return m_value;
	}
};

int main()
{
	Something something;

	something.getValue(); // non-const version
	something.getValue() = 10; // non-error

	const Something something2;
	something2.getValue(); // const version
	// something2.getValue() = 1004; // Error // const reference라서

	int z = 3;

	return 0;
}