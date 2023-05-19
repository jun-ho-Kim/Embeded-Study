#include <iostream>
#include <string>

using namespace std;

// �����ڴ� �ڽ��� ������ �ϱ� ���ٴ� ������� �� ȣ��Ǵ� �Լ��� �ǹ��ߴ�.
// �Ҹ��ڴ� ������ ������ ����� ����� �� ȣ���� �Ǵ� �Լ��̴�.

class IntArray
{
private:
	int* m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_arr = new int[m_length];
	}
	~IntArray()
	{
		if(m_arr != nullptr) 
			delete[] m_arr;
	}

	int size() { return m_length; }
 };

class Simple
{
private:
	int m_id;
public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	}
	// �Ҹ��ڴ� return Ÿ���� ����. 
		// ~(tilda)
	~Simple()
	{
		cout << "Destuctor " << m_id << endl;
	}
};

int main()
{
	//Simple s1(0);
	//Simple s2(1);
		// Constructor 0
		// Constructor 1
		// Destuctor 1
		// Destuctor 0

	//Simple* s1 = new Simple(0);
	//Simple s2(1);

	//delete s1;
	//	Constructor 0
	//	Constructor 1
	//	Destuctor 0
	//	Destuctor 1
	// �����Ҵ��� ���������� �ʴ� ��쿡�� ������ ����� �Ҹ��ڰ� �����ȴ�.
	// �����Ҵ����� Ŭ������ ��������� ������ ����� �޸𸮰� �������� �ʰ� delete�� ����ؾ� �Ҹ��ڰ� ȣ��ȴ�.
	// ( �Ҹ��ڸ� ���α׷��Ӱ� ���� ȣ���ϴ� ���� �������� �ʴ´�.)

	// �Ʒ��� ���� ���� �� delete�� ������� ������ memoery leak�� �����.
	while (true)
	{
		IntArray my_int_arr(10000);
	
	}
	// �����Ҵ翡�� Ŭ���� ��� �� �Ҹ��� ȣ�� �� �����Ҵ����� �ڵ带 ������� ������ ���͸� �������.
	// ���ʹ� ���ο� �Ҹ��� ȣ�� �� �����Ҵ����� ������ ����ִ�.

	int z = 4;

	return 0;
}