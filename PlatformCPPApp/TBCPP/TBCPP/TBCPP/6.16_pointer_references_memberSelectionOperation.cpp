// 포인터와 참조를 구조체나 클래스에 대해서 사용할 때 포인터와 참조를 통해 클래스와 멤버에 접근할 수 있다.

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

	//참조변수 사용
	Person& ref = person;
	ref.age = 15;

	//포인터 변수 사용
	Person* ptr = &person;
	ptr->age = 30;
	//(*ptr).age = 20;

	Person& ref2 = *ptr; 
	ref2.age = 45;

	cout << &person << endl;//00CFF738
	cout << &ref2 << endl;	//00CFF738

	//구조체나 클래스에서 참조변수를 사용할 때는 . 포인터를 사용할 때는 ->

	return 0;
}