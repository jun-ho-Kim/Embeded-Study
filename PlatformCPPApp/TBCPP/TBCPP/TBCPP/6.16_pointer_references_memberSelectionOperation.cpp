// �����Ϳ� ������ ����ü�� Ŭ������ ���ؼ� ����� �� �����Ϳ� ������ ���� Ŭ������ ����� ������ �� �ִ�.

#include <iostream>
using namespace std;

struct Person
{
	int age;
	double weight;
};

int main()
{
	Person person;

	person.age = 5;
	person.weight = 30;

	//�������� ���
	Person& ref = person;
	ref.age = 15;

	//������ ���� ���
	Person* ptr = &person;
	ptr->age = 30;
	//(*ptr).age = 20;

	Person& ref2 = *ptr; 
	ref2.age = 45;

	cout << &person << endl;//00CFF738
	cout << &ref2 << endl;	//00CFF738

	//����ü�� Ŭ�������� ���������� ����� ���� . �����͸� ����� ���� ->

	return 0;
}