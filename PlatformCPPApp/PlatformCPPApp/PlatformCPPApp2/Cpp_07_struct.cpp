#include <iostream>
#include <string>
#include <vector>
//구조체 :: strucrt
//사용자 정의 데이터 타입

/*
구조체 선언 및 정의
struct [태크명]
{
	멤버 데이터
}
struct _stEmployee
{
	string name;
	int age;
	string phoneNum;
	double pay;
	int yearPay[12];
};
*/
//C style
//typedef struct _stABC
//{
//
//};

int main()
{
	/*
	struct _stEmployee
	{
		std::string name;
		int age;
		//std::string phoneNum;
		//double pay;
		//int monthPay[12];
	};

	//정적으로 만드는 방법
	_stEmployee person = { "홍길동", 100 };
	person.age = 30;
	person.name = "이순신";

	int* pA = new int(10);
	*pA = 20;
	delete pA;

	//_stEmployee* pPerson = new _stEmployee("홍길동", 100);
	//pPerson->age = 30;
	//pPerson->name = "이순신";
	//delete pPerson;

	struct _stClass
	{
		std::string subject;
		int score;
	};

	struct _stStudent
	{
		std::string name;
		int age;
		_stClass item[3]; // kor, eng, math
	};
	_stStudent student;
	student.name = "홍길동";
	student.age = 18;
	student.item[0].subject = "국어";
	student.item[0].score = 90;
	student.item[1].subject = "영어";
	student.item[1].score = 95;
	student.item[2].subject = "수학";
	student.item[2].score = 87;
	//출력해봅시다.
	//홍길동 18 국어 90 영어 95 수학 87

	std::cout << student.name;
	std::cout << student.age;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << student.item[i].subject << '\t';
		std::cout << student.item[i].score << '\t';
	}
	std::cout << std::endl;

	std::vector<_stStudent> vStudents;
	vStudents.push_back(student); //구조체 값들의 변수를 넣어줌.

	student.name = "이순신";
	student.age = 19;
	//student.item[0].subject = "국어";
	student.item[0].score = 100;
	//student.item[1].subject = "영어";
	student.item[1].score = 97;
	//student.item[2].subject = "수학";
	student.item[2].score = 95;
	vStudents.push_back(student);

	for (size_t i = 0; i < vStudents.size(); i++)
	{
		_stStudent s = vStudents[i];
		//학생 정보를 출력하세요.
		//이름  나이 과목 성적 ...

		std::cout << "vector\n" << s.name << "   " << s.age << "   ";
		for(int i = 0; i < 3; i++)
			std::cout << s.item[i].subject << "   " << s.item[i].score << "   ";
		std::cout << std::endl;
	}

	vStudents[0]; //홍길동
	vStudents[0].item[0]; //홍길동
	vStudents[0].item[1];
	
	std::vector<int> vInt;

	vInt.push_back(1);
	vInt.push_back(2);
	vInt.push_back(3);
	vInt.push_back(4);
	vInt.push_back(5);
	std::cout << vInt[0] << vInt[1] << vInt[2] << vInt[3] << vInt[4] << std::endl;
	//벡터를 사용하면 크기가 얼마나 되는지 모르는 동적할당을 관리하기 쉬움
	*/
	return 1;
}