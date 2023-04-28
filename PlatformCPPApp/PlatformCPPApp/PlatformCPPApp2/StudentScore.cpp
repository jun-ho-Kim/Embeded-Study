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

void StudentsScore::SetStudentScore(std::string subject, int score)
{
	if (subject == "국어")
		stStudentInfo._kor = score;
	else if (subject == "수학")
		stStudentInfo._math = score;
	else if (subject == "영어")
		stStudentInfo._eng = score;
}

//void StudentsScore::SetStruct(StudentInfo str)
//{
//
//}

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
	if (stStudentInfo._min > stStudentInfo._math)
		stStudentInfo._min = stStudentInfo._math;
	if (stStudentInfo._min > stStudentInfo._eng)
		stStudentInfo._min = stStudentInfo._eng;
}

void StudentsScore::GetMax()
{
	stStudentInfo._max = INT_MIN;
	if (stStudentInfo._max < stStudentInfo._kor)
		stStudentInfo._max = stStudentInfo._kor;
	if (stStudentInfo._max < stStudentInfo._math)
		stStudentInfo._max = stStudentInfo._math;
	if (stStudentInfo._max < stStudentInfo._eng)
		stStudentInfo._max = stStudentInfo._eng;
}

void StudentsScore::DoCalc()
{
	GetSum();
	GetAvg();
	GetMin();
	GetMax();
	std::cout << stStudentInfo._name << " = ";
	std::cout << " 국어: " << stStudentInfo._kor;
	std::cout << " 수학: " << stStudentInfo._math;
	std::cout << " 영어: " << stStudentInfo._eng;
	std::cout << " 총합: " << stStudentInfo._sum;
	std::cout << " 평균: " << stStudentInfo._avg;
	std::cout << " 최소: " << stStudentInfo._min;
	std::cout << " 최대: " << stStudentInfo._max;
	std::cout << std::endl;
}