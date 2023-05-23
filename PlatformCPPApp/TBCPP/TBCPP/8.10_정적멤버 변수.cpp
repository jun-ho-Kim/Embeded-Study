#include <iostream>
#include <string>

using namespace std;

class Something
{
public:
	// static int m_value = 1; // Error static ��� ������ initailize�� �� �� ����.
	static int s_value;
	static const int const_value = 1; // ���� ��� ������ const�� ����Ϸ��� 
	static constexpr int constexpr_value = 1; // �����Ͽ� Ȯ���ϰ� ���� ������ �Ǿ�� �Ѵ�.
};

int Something::s_value = 1; // define in cpp

//// ���������� �Լ� �ȿ� �����ϴ� ���
//int generateID()
//{
//	static int s_id = 0;
//	return ++s_id;
//}

int main()
{
	/*
	// ������������� static�� ������� �ʴ� ���
	Something st1;
	Something st2;

	st1.m_value = 2;

	cout << &st1.m_value << " " << st1.m_value << endl; // 0000006AEC4FFB04 2
	cout << &st2.m_value << " " << st2.m_value << endl; // 0000006AEC4FFB24 1

	//cout << generateID() << endl; // 1
	//cout << generateID() << endl; // 2
	//cout << generateID() << endl; // 3
	*/

	// ������������� static�� ����ϴ� ���
	cout << &Something::s_value << " " << Something::s_value << endl; // 00007FF73202D014 1

	Something st1;
	Something st2;

	st1.s_value = 2;

	cout << &st1.s_value << " " << st1.s_value << endl; // 00007FF73202D014 2
	cout << &st2.s_value << " " << st2.s_value << endl; // 00007FF73202D014 2

	cout << &Something::s_value << " " << Something::s_value << endl;  // 00007FF73202D014 2

	int z = 3;

	return 0;
}