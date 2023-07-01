//�����Ҵ�� �޸𸮿� ���� ������ ������ ����ν� ������ �ִ� Ŭ������ ��� ���縦 �ϰų� ������ �� ��
// ���� �������� ���� ���������� ���� ���� ������ �����ε�, ���� ������ ������ ��ٷο�����. �� ���� ���ؼ� ������ �� ���̴�.
// �ֱٿ��� std::vector�� std::string�� �����پ��� ������� ������ �ϱ� ������ �� ������ ���� ���� ����� �ϴ� ���� ���� ���̴�.
// �ٸ�, �̷� ������ �ݵ�� �����Ѵٴ� ���� �˰� �ٸ� �� ����� �� �� �� �� ������ ����ڰ� �𸣰� ���ĳ��Ҵٴ� ���� �˰� �����ϸ� ���� ������ �� ���� ���̴�.

#include <cassert>
#include <iostream>
using namespace std;

//5.
// std::string; �� ����ϸ� �ȴ�.
//std::string�� Ŭ�����̱� ������ ����� �߰��ҰŸ� 1.����� �޴� ��� 2. MyString Ŭ���� ��
// shallow copy, deep copy ��� ����� ���������� ���� �� �ִ�.



class MyString
{
	//private:
public:
	char* m_data = nullptr;
	int m_length = 0;

	// 5. �̷�
	// std::string;
	// ��κп� ���� ���� ������ Ŭ���� ���� std::string data;�� �����Ͽ� ����Ѵ�.
	//// �̷� ������ �߻��� �� ������ ���ð� ���� �и��Ǿ� �ֱ� ������ ������ �߻��� ������ ������
	//// ������ ������ �̷��� �ذ��߰� C++������ ���å�� ���� �� �ְ� �ٸ� ����� ����� �� �ִ�.

public:
	MyString(const char* source = "")
	{
		//assert(sorce);

		m_length = std::strlen(source) + 1;
		m_data = new char[m_length]; // �����Ҵ����� 

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
		// ���� �Ҵ�� �޸𸮿� ������ �Ǿ� ������ �̷��� �ڵ带 ¥�� ���� ������ �����.

		cout << "Assignment operator " << endl;

		if (this == &source) //prevent self-assignment
			// �ڱ⿡�� ������ �ϴ� ��� �����Ϸ����� ������ �����. �׷��� �̸� �����ϱ� ���� ����ó���̴�.
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
	// ���� �����ڸ� ������ ������ ���� ���
	// ���� ���� ���� ����� ���� �����ڸ� ����ϴ� ���̴�.
	// ���� ������ ���� �����ڸ� ������� ���� �Ÿ� �ƿ� �����ڸ� ����ϸ� �ȵǰ� ���ƹ�����.
	//MyString(const MyString& source) = delete;
	// �� ����� ����å�̴�.

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
		// ���� scope�� ����� copy.m_data�� �ּҴ� delete �ȴ�.
		MyString copy = hello; // �����ǰ� ������ ���� �����ڸ� ����

		// copy = hello // ���� �����ڰ� ȣ��
		cout << (int*)copy.m_data << endl;	// 1. 000001FF5E98A5A0 2. 0000024EF42AEE40
		// hello�� copy �ν��Ͻ��� �ּҴ� ����. ��������ڸ� �����߱� ����
		cout << copy.getString() << endl;	// Hello
	}

	// 2. Copy constructor
	cout << hello.getString() << endl; // 1. ���������� 2. Hello
	// copy���� �ּҸ� �����ؼ� heap���� Hello�� �� �� �ۿ� ���µ� 
	// copy �ν��Ͻ��� scope�� ������ 
	// ���� �޸��Ҵ��� ����ϴ� ��쿡 ����� �����Ͱ� �ִµ� copy contructor�� assignment operator�� �����ε��� �� �����ؾ��Ѵ�.

	
	//3. Copy constructor�� Assignment operator�� ������ ��
	/*
	MyString hello("Hello");
	//�̷��� �����ϸ� Copy constructor
	MyString str1(hello); // MyString str1 = hello; //Copy constructor
	

	MyString str2;
	//�̷��� �����ϸ� Assignment operator
	str2 = hello; // Assignment operator

	cout << (int*)hello.m_data << endl;	// 00000217DAE1E8F0
	cout << hello.getString() << endl;	// Hello
	*/



	int z = 5;

	return 0;
}


// ���� ����� ���� ������ ������, ���� ����� ���� ���� �� �ִ� ������,  default copy consturctor�� ������ִ� ���� ���簡 ���� ����� ���̰� �ְ�
// �����Ҵ� �޸𸮸� ����� ���� ������ ���� �� �ִ�.