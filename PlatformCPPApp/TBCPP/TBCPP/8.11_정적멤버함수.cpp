#include <iostream>
#include <string>

using namespace std;

// ���� Ŭ������ ��� �ν��Ͻ����� ������ �����ϴ�.
// 
// staitc ��� �Լ� vs �Ϲ��Լ��� this ������ ���
//// static ��� �Լ��� this �����͸� ����� �� ����.

// static ����Լ� ���� vs �Ϲ� ����Լ� ����

// static ��� variable�� contructor�� ��� �Ұ�

//_init Ŭ������ ����Ͽ� ��� ���� �ʱ�ȭ(cpp������ �������� �������)

class Something
{
	/*
	//case 1.
	static int s_value; // ���� Ŭ������ ��� �ν��Ͻ����� ������ �����ϴ�.
	int getValue()
	{
		return s_value;
	}
	*/

// case 2.
public:
	class _init
	{
	public:
		_init()
		{
			s_value = 1234;
		}
	};


private:
	static int s_value;
	int m_value;

	static _init s_initializer; // inner Ŭ������ static���� ����
public:

	Something()
		: m_value(123) //s_value(1024); // Error
	{}
	//_init Ŭ������ ����Ͽ� ��� ���� �ʱ�ȭ
	// Ŭ���� �ȿ� Ŭ����


	static int getValue()
	{
		return s_value;
		//return this->m_value;  // Error
		// static ��� �Լ��� this �����͸� ����� �� ����.
	}

	int temp()
	{
		return this->s_value;
		// this�� ����Ѵٴ� ���� Ư�� �ν��Ͻ��� �ּҸ� ������ ����ϰڴٴ� �ǹ��̴�.
	}
};

int Something::s_value = 1024;
Something::_init s_initializer; // inner Ŭ������ �����ڰ� ȣ��ǰ� s_value�� �ʱ�ȭ��

int main()
{
	//case 1.
	/*
	cout << Something::s_value << endl; 
	// Ŭ������ ���ǰ� �Ǳ� ������ static ��� ������ ���� �� �ִ�.

	Something s1;
	cout << s1.getValue() << endl;
	cout << s1.s_value << endl;
	*/


	//cae 2
	cout << Something::getValue() << endl;

	Something s1, s2;
	cout << s1.getValue() << endl;

	// int (Something::*fptr1)() = s1.temp; // Error 
	// Ŭ���� �Լ��� �ν��Ͻ� ���� ������ �ִ� ���� �ƴ϶� �ϳ��� �ּҿ��� ������ ����ϱ� ������ ������ �߻�

	// Ŭ�����Լ��� ����Ϸ��� ������ ���� ����ض�.
	int (Something:: * fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl; 
	// Something�̶�� Ŭ������ ��� �Լ� temp�� �����͸� ������ �ִµ� ������ ��ġ�� �ִ� �Լ��� ������ ��ų �� 
	//(�̾) s2��� �ν��Ͻ��� �����͸� �Ѱ��ְ� s2��� �ν��Ͻ��� this �����͸� ������ �۵��� �ϴ� ����
	// s2�� ������ temp �Լ��� �������� �ʴ´�. non-static ��� �Լ��� �ν��Ͻ��� ������ �ִ� ���·� �����Ǿ� �־ 
	// �ν��Ͻ��� ������(this �����Ͱ� ������) �۵��� �ȵȴ�.

	// int (Something:: * fptr2)() = &Something::getValue; // Error
	int (* fptr2)() = &Something::getValue; // static ��� �Լ��� Ư�� �ν��Ͻ��� ������� �����ų �� �ִ�.(static ��� ������ ����)

	cout << fptr2() << endl;

	// function�� �ּҴ� Ư�� �ν��Ͻ� �ּҿ� �������� �ʴ�.

	int z = 1;

	return 0;
}
