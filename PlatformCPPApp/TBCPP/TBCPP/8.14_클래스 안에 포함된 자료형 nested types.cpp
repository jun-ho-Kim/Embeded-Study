// 클래스를 구현할 때 기능을 맞춰서 특정한 자료형을 만들어서 사용할 때도 있다. 이 때는 그 자료형이 여기저기서 사용될 필요가 없다.
// 클래스 안에만 어떤 자료형을 선언할 수도 있다.
// nested Types(클래스 안에 포함되어 있는 자료형)에 대해서 알아보자.

#include <iostream>
#include <string>

using namespace std;
// 여러 클래스가 공동적으로 사용하는 데이터 타입일 경우에는 밖으로 빼고 헤더를 따로 만들어서 편하게 include 해주면 좋겠지만
// 특정 클래스만 사용하는 데이터타입인 경우 클래스 안에 임시로 사용할 수 있도록 하는 것도 좋은 방법이다.
// 최근에 이렇게 사용하는 방식이 늘어나고 있다.

class Fruit
{
public:
	//case 1
	enum FruitType
	{
		APPLE, BANNA, CHERRY,
	};

	//case 2 // enum 클래스 사용
	//enum class FruitType
	//{
	//	APPLE, BANNA, CHERRY,
	//};

	// 아래와 같이 사용 가능
	class InnerClass
	{
	};

	struct InnerStruct
	{
	};

private:
	FruitType m_type;

public:
	Fruit(FruitType type): m_type(type)
	{}

	FruitType getType() { return m_type; }
};

int main()
{
	Fruit apple(Fruit::APPLE);

	if (apple.getType() == Fruit::APPLE) // case 1
	//if (apple.getType() == Fruit::FruitType::APPLE) // case 2
	{
		std::cout << "Apple" << std::endl;
	}
	return 0;
}