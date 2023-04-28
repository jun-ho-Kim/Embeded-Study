#pragma once
#include <iostream>
#include <string>

struct StudentInfo
{
	std::string _name;
	int _eng;
	int _math;
	int _kor;
	int _sum;
	float _avg;
	int _min;
	int _max;
};

class StudentsScore
{
public:
	StudentsScore();
	~StudentsScore();
	void GetSum();
	void GetAvg();
	void GetMin();
	void GetMax();
	void SetStudentName(std::string name);
	void SetStudentScore(std::string subject, int score);
	void DoCalc();
private:
	StudentInfo stStudentInfo;
};

