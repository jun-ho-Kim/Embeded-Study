// int a = 10;
// int a(10);	// ���⼭ a�� ����(����, �ν��Ͻ�), 10�� �ʱⰪ(���)
// int b(a);	// ���⼭ a�� ����, b�� �纻

//������ �Լ� - caller -> call // ��� ������ ���� ȣ���. ��, ���� �Ǹ� '�˾Ƽ�' '�ڵ�'���� ȣ��
//	�����ڴ� �ν��Ͻ��� ����� �� �����ȴ�.
//�Ҹ��ڴ� delete�� scope�� ����� ��� ȣ��
//* ������ ����
//	1. �⺻ ������
//	2. ���� ���ǵ� ������(�Ű�����)
//		2-1. ��ȯ������(�Ű������� 1��)
//	3. (�̸��� ���� �ӽ� ��ü)���� ������ + r-value ������ �޴� ������(C++11���� ����)
//	4. �̵�������
// 

// ��������� �� �ʿ��ұ�?
// Deep Copy�� shallow Copy�� ���ؼ� �˾ƾ� �Ѵ�.
// 	int nData = 5;
//	int* pA = &nData;
//	int* pB = &nData;
// ���ü(nData) �ϳ��� ����, �����ڰ� 2�� �̻��� ��� ���� ����
// ���ü�� ���� ���� ��� ���� ����
//(��Ű�� 2���� �����Ѵٰ� ���� 2���� �Ǵ� ���� �ƴ�)

//ex)pointer�� 2�� ���ü�� 1���� ��� ���� ����
//		pointer�� 2�� �װ� ����Ű�� ���ü�� ���� 1���� �� 2���̸� ���� ����

// ����Ʈ ���� �����ڴ� �⺻���� ���� �����̴�. ���� ���縦 �ϱ� ���ؼ��� ����Ʈ ���� �����ڸ� ������ �����ؾ��Ѵ�.

#include <iostream>

class CTest 
{
public:
	CTest() {
		std::cout << "CTest()" << std::endl; 
		m_pData = new int(5);
	}
	//CTest(const CTest &rhs) { 
	//	std::cout << "CTest(const CTest &)" << std::endl; 
	//	this->m_nData = rhs.m_nData; // ��� ���� �ܼ� �������� ����
	//}
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

	int *m_pData = nullptr;
	//int m_nData = 0;
private:
};


int main()
{
	/*
	int *pA = new int(5);
	int* pB = NULL;

	pB = pA; //Shallow
	pB = new int(*pA); //Deep

	std::cout << *pA << std::endl;
	*/
	/*
	CTest a;
	a.m_nData = 300;
	CTest b(a); // <-- ���� ������

	//a.m_nData = 0;
	//std::cout << a.m_nData << std::endl;
	//std::cout << a.m_nData << std::endl;
	//std::cout << b.m_nData << std::endl;
	*/

	CTest a;
	CTest b(a); // <-- ���� ������

	std::cout << a.GetData() << std::endl;
	std::cout << b.GetData() << std::endl;
	// ���� ����� �Ͽ� delete�� �ϴ� ��� ���� �޸𸮰� 2�� �������� ���α׷��� ������ �߻��ϰ� �ȴ�.
	return 0;
}