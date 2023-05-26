// Ŭ������ ������ �� ����� ���缭 Ư���� �ڷ����� ���� ����� ���� �ִ�. �� ���� �� �ڷ����� �������⼭ ���� �ʿ䰡 ����.
// Ŭ���� �ȿ��� � �ڷ����� ������ ���� �ִ�.
// nested Types(Ŭ���� �ȿ� ���ԵǾ� �ִ� �ڷ���)�� ���ؼ� �˾ƺ���.

#include <iostream>
#include <string>

using namespace std;
// ���� Ŭ������ ���������� ����ϴ� ������ Ÿ���� ��쿡�� ������ ���� ����� ���� ���� ���ϰ� include ���ָ� ��������
// Ư�� Ŭ������ ����ϴ� ������Ÿ���� ��� Ŭ���� �ȿ� �ӽ÷� ����� �� �ֵ��� �ϴ� �͵� ���� ����̴�.
// �ֱٿ� �̷��� ����ϴ� ����� �þ�� �ִ�.

class Fruit
{
public:
	//case 1
	enum FruitType
	{
		APPLE, BANNA, CHERRY,
	};

	//case 2 // enum Ŭ���� ���
	//enum class FruitType
	//{
	//	APPLE, BANNA, CHERRY,
	//};

	// �Ʒ��� ���� ��� ����
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