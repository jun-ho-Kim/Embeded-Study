//this �� ���������� ���� �ν��Ͻ��� ������ ���� �޸��� �ּ��̴�.
// ���������δ� �޴����� �ø����ȣ�̴�.
//

#include <iostream>

class CTest
{
public:
	CTest()
		//: m_nData(0) // C++11 ���� ���� ���� ���//���� ���� �ʱ���
	{
		std::cout << "CTest()" << std::endl;
		m_nData = 0;// �Լ��� call �� �� ����
	}
	//int m_nData; // C++11 ���� ���� ���� ���

	~CTest()
		//: m_nData(0) // C++11 ���� ���� ���� ���//���� ���� �ʱ���
	{
		std::cout << "~CTest()" << std::endl;
		m_nData = 0;// �Լ��� call �� �� ����
	}

	void PrintData()
	{
		int local = 5;
		std::cout << this << std::endl;
		std::cout << m_nData << std::endl;
		std::cout << this->m_nData << std::endl;
	}

	int m_nData = 0; //C++ 11 ��Ÿ��

};

int main()
{
	CTest a;
	std::cout << &a << std::endl; // 00BCFB28
	a.PrintData();
	// 0019FD9C
	// 0019FD9C
	// 0

	CTest b;
	std::cout << &b << std::endl; // 00BCFB1C
	b.PrintData();
	// ���� CTest Ŭ���������� a�� b�� �ּҴ� �ٸ���.
	// a.printData()�� a.printData(&a)�� ����. �Ű������� &a�� �������ִ�.(hidden)

	// this �������� ���� �ڵ����� �����ȴ�. 
	// this pointer�� r-value�̴�. ������ �� ����.

	// const �Լ��� this�� ���� ������ �� ����.
	// static ������� -> [�������� �����Լ�] �ҼӸ� class�̴�.
	//	���������� ����ϸ� ��Ƽ�������� ������ �߻��� ���ɼ��� ����.
	//	��Ƽ�������� �����Ͽ� ���ü��� �߻��ϴ°��� ������ ���ؼ� ����غ��ƾ� �Ѵ�.
	//	�ذ���:	���� ������ �����帶�� ����Ǵ� stack �޸�(local) (TLS)�� ������Ѽ� ������ �ذ�
	//	������ ���� core�� ������ �÷� ���ļ�(���ü�)���� �۵���Ű�� ������ static�� ������� �ʴ� ���� ����.
}