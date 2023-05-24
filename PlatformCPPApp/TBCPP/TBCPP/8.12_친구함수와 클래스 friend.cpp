#include <iostream>
#include <string>

using namespace std;
//-���� ���� Ŭ������ �����ϰ� ��ȣ�ۿ��ϸ� ���ư��� ���α׷�������
//Ŭ�������� ��ȣ�ۿ��� ����ϰ� �����ϴ°� ���� ���� �� �ִ�.
//- ��ü������ �⺻��Ģ ��ĸ�����̼��� �����ϱ� ���ؼ� �������� �ΰ����� ��Ұ� �߻��Ҽ� �ִµ�
//ģ�� �Լ�, ģ�� Ŭ���� ���� Ȱ���ϸ� �� �� ����ϰ� �����ϸ鼭 ���ϴ� ������ �޼��� �� �ִ�.

/*
// case 1

class B; // forward declaration

class A
{
private:
	int m_value = 1;
	friend void doSomething(A& a, B& b);
};
class B
{
private:
	int m_value = 2;

	friend void doSomething(A& a, B& b);
};
*/

/*
// case 1
void doSomething(A& a)
{
	cout << a.m_value << endl;
	// ������ ���α׷����� �ϴٺ��� ���� ���� �ڵ��� �� ���� �ִ�. Ư�� ������ �����ε��� �� �� ���� �߻�
	// ������ �����ε����� friend�� ���� ����Ѵ�.
	// m_value�� private -> public���� �ٲ� �� ������ ��ü������ ��Ģ�� �ݴ�ȴ�.
	// �׷��� friend�� ����Ѵ�.
	//friend �Լ��� Ư�� Ŭ������ private ����� ������ �� �ִ�.
}

//Ŭ������ 2���� �� � �Լ��� 2���� Ŭ������ ��� �����ϴ� ���

void doSomething(A& a, B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
	// forward declaration�� ������־�� A Ŭ���� ��밡��
}
*/

// Ŭ������ �ٸ� Ŭ������ ��������� ����ϰ��� �� ��

class A;

class B
{
private:
	int m_value = 2;
public:

};

class A
{
private:
	int m_value = 1;
	//friend class B;
	// Ư�� ��� �Լ����Ը� friend�� ����ϰ� ���� ��
	friend void B::doSomething(A& a);
};

void B::doSomething(A& a)
{
	cout << a.m_value << endl;
}



int main()
{
	/*
	//case 1
	A a;
	B b;

	doSomething(a, b);
	*/

	//case 2
	A a;
	B b;
	b.doSomething(a);

	return 0;
}