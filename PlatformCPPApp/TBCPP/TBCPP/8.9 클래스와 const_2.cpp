#include <iostream>
#include <string>

using namespace std;
// const overroading ~16:00
// const�� Ŭ������ ����� �� �� ��� ����� �Ǵ°�
// Ŭ������ �ν��Ͻ� Ȥ�� ������Ʈ�� const�� ���� �� member variable�� const�� �Ǵ� �Ͱ� ���� ȿ���� ��Ÿ����.
// ��� �Լ��� const�� �Ǵ� ���� �Լ� �ȿ��� ��� variable�� �ٲ��� �ʰڴٶ�� ����
// �ڵ��� �� const�� ���� �� �ִ� ���� const�� �ۼ��ϴ� ���� �� ������ �ڵ� �Ǽ��� ���̴µ� ������ �ȴ�.
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
	// something2.getValue() = 1004; // Error // const reference��

	int z = 3;

	return 0;
}