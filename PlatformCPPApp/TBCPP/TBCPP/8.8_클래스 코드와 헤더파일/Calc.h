#pragma once
// ������ Ŭ���� �̸��� ��������� �̸��� ���� ����Ѵ�.

// ������Ͽ� using namespace std;�� ����ϸ� nclude�ϴ� ���� ���� ������ �޾Ƽ� ������Ͽ��� ������� �ʴ� ���� ����.

#include <iostream>


class Calc
{
private:
	int m_value;
public:
	Calc(int init_value)
		: m_value(init_value)
	{}

	void print()
	{
		using namespace std;
		cout << m_value << endl;
	}

	Calc& add(int value);
	Calc& sub(int value);
	Calc& mult(int value);
};