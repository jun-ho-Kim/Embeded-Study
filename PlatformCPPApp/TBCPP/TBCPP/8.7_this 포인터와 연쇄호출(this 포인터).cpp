// class�� ���� �ؾ�� ��� Ʋ�� �����ϴ� ��찡 �ִ�.
// �������� �ؾ �� �ν��Ͻ����� �����ٵ� �� �ν��Ͻ����� ��� ������ �� ������?
// Ŭ���� �ȿ� �����ִ� this �����Ϳ� this �����͸� ����Ͽ� chaining member function(���� ȣ��)�� �˾ƺ���.

#include <iostream>
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id); // setID���� this�� �����Ǿ� �ִ�.(this->setId(id)
		// ->�� class�� structure�� �������� ��쿡 memeber selection operation�̴�.
		//(*this).setID(id);

		cout << this << endl; // �ڽ��� �ּҸ� ���
		// 000000CB315AF814 // Simple s1
		// 000000CB315AF834 // Simple s2
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

int main()
{
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	//  ** Ŭ������ �Լ�(setID, getID ��)�� �ν��Ͻ� ���� ������ �ʴ´�.
	// Simple::setId(&s1, 4) �̷��� �־��ش�.()
	// Simple::setId(&s1, 4) == s2.setID(4) �̴�. ���������δ�  s2.setID(4) ����
	// �� �ν��Ͻ����� ���� �����͸� ������ �ְ� this��� Ű���鸣 ����ϸ� �ȴ�.
	cout << &s1 << " " << &s2 << endl; // 000000CB315AF814 000000CB315AF834

	int z = 3;

	return 0;
}