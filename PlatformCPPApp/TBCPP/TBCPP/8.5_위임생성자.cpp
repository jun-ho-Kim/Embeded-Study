#include <iostream>
#include <string>

using namespace std;

// �����ڰ� �ٸ� �����ڸ� ����ϴ� ���� ���ӻ����ڶ�� �Ѵ�.

class Student
{
private:
	int m_id;
	string m_name;

public:
	//Student(const string& name_in)
	//	: m_id(0), m_name(name_in)
	//{}

	Student(const string& name_in)
		//: m_id(0), m_name(name_in) // ���ӻ����ڸ� ������� �ʴ� ���
		: Student(0, name_in) // ���ӻ�����: �����ڰ� �ٸ� �����ڸ� ������ ����ϴ� �� // C++11���� ����
	{}

	Student(const int& id_in, const string& name_in)
		: m_id(id_in), m_name(name_in)
	{
		// init(id_in, name_in); // (����)�����ڸ� ������� �ʰ� ��������� �ʱ�ȭ �ϴ� ��� // ���߿� ���캸��.
		// ������� �� ������� ���� �ڵ带 �ۼ��Ѵ�.
	}

	void init(const int& id_in, const string& name_in)
	{
		m_id = id_in;
		m_name = name_in;
	}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};

int main()
{
	Student str1(0, "Jack Jack");
	str1.print();

	// � ����� �ϴ� �ڵ�(�ʱ�ȭ)�� �� �������� ���;� �Ѵ�.
	// m_name�� �����ϴ� ���� �� ���̿��߸� �ϸ�  �ʱ�ȭ�� �� ������ ���ִ� ���� ����.
	// m_id ó�� ������ ����� �ʱ�ȭ �ϸ� ���߿� �ڵ带 �����ϰ��� �� �� ����Ѵ�.
	// �����ڰ� �����ڸ� ������ ����� �� �ִ�.
	
	Student str2("Dash");
	str2.print();

	return 0;
}