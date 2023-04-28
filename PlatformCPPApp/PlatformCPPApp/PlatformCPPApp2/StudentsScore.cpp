#include "StudentsScore.h"
#include <iostream>

StudentsScore::StudentsScore()
{
	std::cout << "StudentsScore::Ctor" << std::endl;
}

StudentsScore::~StudentsScore()
{
	std::cout << "StudentsScore::Dtor" << std::endl;
}

void StudentsScore::SetStudentName(std::string name)
{
	stStudentInfo._name = name;
}

void StudentsScore::SetStudentsScore(std::string subject, int score)
{
	if (subject == "����")
		stStudentInfo._kor = score;
	else if (subject == "����")
		stStudentInfo._math = score;
	else if (subject == "����")
		stStudentInfo._eng = score;

}

void StudentsScore::GetSum()
{
	stStudentInfo._sum = stStudentInfo._kor + stStudentInfo._eng + stStudentInfo._math;
}

void StudentsScore::GetAvg()
{
	stStudentInfo._avg = (stStudentInfo._kor + stStudentInfo._eng + stStudentInfo._math) / 3;
}

void StudentsScore::GetMin()
{
	stStudentInfo._min = INT_MAX;
	if (stStudentInfo._min > stStudentInfo._kor)
		stStudentInfo._min = stStudentInfo._kor;
	else if (stStudentInfo._kor > stStudentInfo._math)
		stStudentInfo._min = stStudentInfo._math;
	else if (stStudentInfo._math > stStudentInfo._eng)
		stStudentInfo._min = stStudentInfo._eng;
}

void StudentsScore::GetMax()
{
	stStudentInfo._max = INT_MIN;
	if (stStudentInfo._max < stStudentInfo._kor)
		stStudentInfo._max = stStudentInfo._kor;
	else if (stStudentInfo._kor < stStudentInfo._math)
		stStudentInfo._max = stStudentInfo._math;
	else if (stStudentInfo._math < stStudentInfo._eng)
		stStudentInfo._max = stStudentInfo._eng;
}

void StudentsScore::DoCalc()
{
	GetSum();
	GetAvg();
	GetMin();
	GetMax();
	std::cout << stStudentInfo._name << " = ";
	std::cout << " ����: " << stStudentInfo._kor;
	std::cout << " ����: " << stStudentInfo._math;
	std::cout << " ����: " << stStudentInfo._eng;
	std::cout << " ����: " << stStudentInfo._sum;
	std::cout << " ���: " << stStudentInfo._avg;
	std::cout << " �ּ�: " << stStudentInfo._min;
	std::cout << " �ִ�: " << stStudentInfo._max;
	std::cout << std::endl;
}