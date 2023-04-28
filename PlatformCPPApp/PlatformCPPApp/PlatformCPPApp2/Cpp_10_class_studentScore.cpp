#include "StudentScore.h"
#include <iostream>

int main()
{
	StudentsScore s[3];
	
	
	StudentInfo test;

	test._name = "김준하";
	test._kor = 15;
	test._math = 13;
	test._eng = 12;

	printf("test is %c\n", test._name);
	
	s[0].SetStudentName("홍길동");
	s[0].stStudentInfo._name = test._name;
	printf("s[0].stStudentInfo._name %p\n", &s[0].stStudentInfo._name);
	printf("test._name %p\n", &test._name);

	s[0].SetStudentScore("국어", 80);
	s[0].SetStudentScore("수학", 84);
	s[0].SetStudentScore("영어", 72);

	s[1].SetStudentName("이순신");
	s[1].SetStudentScore("국어", 92);
	s[1].SetStudentScore("수학", 87);
	s[1].SetStudentScore("영어", 89);

	s[2].SetStudentName("신사임당");
	s[2].SetStudentScore("국어", 97);
	s[2].SetStudentScore("수학", 85);
	s[2].SetStudentScore("영어", 45);

	s[0].DoCalc();
	s[1].DoCalc();
	s[2].DoCalc();


}