#include <iostream>
//��ü���� ��� C++�� ������ Class�� ���� �˾ƺ��ô�.
//��ü - object ������ �߽����� ����Ʈ���� �ý����� �����ϴ� ��

//��ü������ Ư¡:
/*
�߻�ȭ(abstraction) : ���������� ���� �� �ϳ��� ������ �Ӽ� / ����� ��� Ŭ������ ������ ��
	�޴��� : ��ȭ���� �Ӽ�...������/������
	��ȭ�� == ��ü
	��ȭ �ɱ� == ��ü,�Ӽ�/���
	��ȭ �ޱ� == ��ü,�Ӽ�/���
	��ȭ �︲ == ��ü,�Ӽ�/���
	��ȭ UI	  == ��ü,�Ӽ�/��� 123-1234-1234
	class Phone:
		send()
		recv()
		bell()
		comm()
		input()
		//Phone�� ���������� �� �ִ� ��ɵ��� ����

ĸ��ȭ(encapsulation) : ������ ���� �� ���۵Ǵ� �κп� �����͸� ó���Կ� �־� ��ü�� �����Ϳ�
	���� ������ �� ���� �޼ҵ�(method, function)�� ���ؼ��� �����ϴ�.
	class Phone:
	public:
		���/�Է�/���/ȭ��/���...
		send()
		recv()
		bell()
		comm()
		input()...123-1234-1234
	private:
		������ 123-1234-1234

��Ӽ�(inheritance) : ���...���� Ŭ���� Ȯ���� �Ļ� Ŭ������ �����ϴ� ��
	class IPhone: public Phone
		input()...button -> audio"siri"

������(polimorphism) : "�������̵�"���� �پ��� ���·� ��Ÿ�� �� �ִ� Ư¡
	class Iphone: public Phone
		input...button->audio"siri"

��ü(object)
...����Ʈ���� �ý����� ������ ����
	int/char/...struct student
	Ư���� ������ ������ ��� ��ü...
	Ư��(attribute) : �ش� ��ü�� ����� ����, ����(behavior) : ��ü�� �ൿ/�����ϴ� ���
	ex) �ڵ��� ��ü�� Ư�� : ��ü/����/��Ƽ���/���ӱ�/����...�� ��ǰ�� ������ �ִ�.
		�ڵ��� ��ü�� ���� : ����/����/��ȸ��/��ȸ��/����/���� ������ ������ ����

��ü�� ����:
�ڵ����� �����ϱ� ���ؼ� ����� ������ ��밴ü(�ν��Ͻ�ȭ �� ��ü)
���� ��ü�ڰ� (������)�� �ڵ��� ��ü�� �޼����� ������(ȣ��)�� �մϴ�.
*/

// struct + �߻�ȭ, ĸ��ȭ => Ŭ����


/*
Ŭ����(class) : ������ Ư¡ȭ ������ ���� ��ü�� ǥ���ϴ� ����(Ʋ, ����) Ȥ�� ���ø�
				������ ǥ���� ���� �߻�ȭ�� ������ Ŭ������� �մϴ�.
				��� ��ü�� Ŭ������ ������� ����, ��ü�� �ν��Ͻ�(����)��� �մϴ�.
				class student
				student person;
�߻����� ������ Ÿ��
typedef struct Date
{ int year, month, day;} Date
struct _Date
{ int year, month, day;} �ʱ�ȭ = year = month = day = 0 ?? 0xCCCC - 8563234+1
*/

/*
Ŭ������ ����ü�� ������
C << C++ ���� ����� ������
C++ ����ü�� ����Լ�, Ŭ������ ���� �� ������ ����������{public, protected, private) ĸ��ȭ�� ����
C++ ����ü/Class �����ϸ� ��ü�������� Ư¡�� ��ȣ����
����� ������
1. Ŭ������ ���������ڰ� default - private�� �ִ�. // ����ü�� public
2. Ŭ������ ����� ���� ��ü������ ��������
*/

class CDate
{
public:		//���������� - �������

	// 1. �����ڷ� ��������� �����ϴ� ���
	CDate()//����Ʈ ������..ctor
	{
		year = 0;
		month = 0;
		day = 0;
		
		std::cout << "CDate::ctor" << std::endl;
	}
	CDate(int yy, int mm, int dd) // �Լ� �����ε�, ������ �����ε�
	{
			year = yy;
			month = mm;
			day = dd;
	}
	~CDate()//�Ҹ���..dtor
	{
		std::cout << "CDate::dtor" << std::endl;
	}
protected:	//����������-�ʸ�

public:
	// 2. �Լ��� ��������� �����ϴ� ���
	void setDate(int yy, int mm, int dd)
	{
		year = yy;
		month = mm;
		day = dd;
	}
	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
	void displayDate() { std::cout << year << "��" << month << "��" << "��" << std::endl; }
private:	//����������-����
	int year, month, day;//�������...�����͸� ��� �׸�
	void privateFunction() {}
};

int main()
{
	{
		CDate date(2023,04,26);
		date.displayDate();
		date.setDate(2023, 05, 26);
		date.displayDate();
	}
}