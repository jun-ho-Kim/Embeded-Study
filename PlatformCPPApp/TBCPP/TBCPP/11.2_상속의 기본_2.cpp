#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
	Student std("Jack Jack");
	std.setName("Jack Jack2");
	std::cout << std.getName() << std::endl;

	Teacher teacher1("Dr. H");
	teacher1.setName("Dr. K");

	std::cout << teacher1.getName() << std::endl;

	std::cout << std << std::endl;
	std::cout << teacher1 << std::endl;

	std.doNothing();
	teacher1.doNothing();

	std.study();
	teacher1.teach();

	Person person;

	person.setName("Mr. Incredible");
	person.getName();


	// 자식 클래스의 함수를 부모클래스에서 가져와 사용할 수 없다.
	//person.study();
	//person.teach();
}