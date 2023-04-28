#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class StudentScore
{
public:
	StudentScore();
	~StudentScore();
	void SetStudentName(const std::string& name);// : 학생 이름
	void SetSubjectScore(const std::string& subject, const int& score);// : 과목, 성적입력
	void DoCalc();
	int ShowStudentInfos();
	// : 결과 산출

private:
	int GetSum();
	float GetAvg();
	int GetMin();
	int GetMax();
//#define eKor 0
//#define eEng 1
//#define eMath 2
	enum { eKor, eEng, eMath, eSubjectsMax };
	std::string SubjectNames[eSubjectsMax] = { "KOR", "ENG", "MATH" };

	/*
	python dict/list/tuple
	*/


	struct StudentInfo
	{
		std::string name = "";
		int score[eSubjectsMax] = {0,0,0};
		int sum = 0;
		float avg = 0.;
		int min = 0;
		int max = 0;
	};
	StudentInfo si;
	std::vector<StudentInfo> vStudents;


};
