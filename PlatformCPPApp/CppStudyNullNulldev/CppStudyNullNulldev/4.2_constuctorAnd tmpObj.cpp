// ���Կ�����
// ������ overloading
// ������ +, -. /, *
// c++������ �����ڸ� �Լ��� �ٲ� �� �ִµ� �̸� ������ �Լ���� �Ѵ�.
//	�������� Ư���� �Լ��� ��ü���� overloading�Ѵ�.

// �ܼ����� ������ =
// l-value r-value
//	l:Locator(����)(OverWrite)
//	r-value is ����, ���(Read)

// ������ �Լ��� �⺻����(int, double��)������ �������� �� ������ Ŭ���������� ������ �� �� �ִ�.
// ���� �����ڸ� ����� ��� ��ü�� ���Կ����ڵ� �����Ǹ� �ؾ��Ѵ�.

// Deep copy �̽��� �־ ���� �����ڸ� �����ϴ� Ŭ������ ������ �ܼ����Կ����ڵ� �������ؾ��Ѵ�.
#include <iostream>

class CTest
{
public:
	CTest() {
		std::cout << "CTest()" << std::endl;
		m_pData = new int(5);
	}
	CTest(const CTest &rhs) { 
		// Pointer�� ���� Shallow copy
		//std::cout << "CTest(const CTest &)" << std::endl; 
		//this->m_nData = rhs.m_nData; // ��� ���� �ܼ� �������� ����

		// Deep Copy
		this->m_pData = new int(*rhs.m_pData);
	}
	~CTest() {
		std::cout << "~CTest()" << std::endl;
		delete m_pData;
	}

	void SetData(int nParam)
	{
		*m_pData = nParam;
	}

	int GetData()
	{
		return *m_pData;
	}

	CTest& operator =(const CTest& rhs)
	{
		*m_pData = *rhs.m_pData; // Deep
		m_pData = rhs.m_pData;  // Shallow
		return *this;
	}

	int* m_pData = nullptr;
	//int m_nData = 0;
private:
};

int main()
{
	CTest a;
	CTest b;

	a.SetData(5);
	b = a;

	std::cout << a.GetData() << std::endl;
	std::cout << b.GetData() << std::endl;
	// ���� ����� �Ͽ� delete�� �ϴ� ��� ���� �޸𸮰� 2�� �������� ���α׷��� ������ �߻��ϰ� �ȴ�.
	return 0;
}