#include "StudentScore.h"
#include <iostream>

int main()
{
	StudentsScore s[3];
	
	
	StudentInfo test;

	test._name = "������";
	test._kor = 15;
	test._math = 13;
	test._eng = 12;

	printf("test is %c\n", test._name);
	
	s[0].SetStudentName("ȫ�浿");
	s[0].stStudentInfo._name = test._name;
	printf("s[0].stStudentInfo._name %p\n", &s[0].stStudentInfo._name);
	printf("test._name %p\n", &test._name);

	s[0].SetStudentScore("����", 80);
	s[0].SetStudentScore("����", 84);
	s[0].SetStudentScore("����", 72);

	s[1].SetStudentName("�̼���");
	s[1].SetStudentScore("����", 92);
	s[1].SetStudentScore("����", 87);
	s[1].SetStudentScore("����", 89);

	s[2].SetStudentName("�Ż��Ӵ�");
	s[2].SetStudentScore("����", 97);
	s[2].SetStudentScore("����", 85);
	s[2].SetStudentScore("����", 45);

	s[0].DoCalc();
	s[1].DoCalc();
	s[2].DoCalc();


}