#include "StudentScore.h"

int main()
{
	StudentScore si;

	std::string _kor = "kor", _eng = "Eng", _math = "maTH";
	int kor = 0, eng = 0, math = 0;

	//cin
	std::string name = "홍길동";
	si.SetStudentName(name);
	kor=80, eng=90, math=100;

	
	si.SetSubjectScore(_kor, kor);
	si.SetSubjectScore(_eng, eng);
	si.SetSubjectScore(_math, math);
	si.DoCalc();
	si.ShowStudentInfos();

	name = "이순신";
	si.SetStudentName(name);
	kor = 75, eng = 85, math = 95;
	si.SetSubjectScore(_kor, kor);
	si.SetSubjectScore(_eng, eng);
	si.SetSubjectScore(_math, math);
	si.DoCalc();

	name = "유관순";
	si.SetStudentName(name);
	kor = 65, eng = 75, math = 85;
	si.SetSubjectScore(_kor, kor);
	si.SetSubjectScore(_eng, eng);
	si.SetSubjectScore(_math, math);
	si.DoCalc();
	si.ShowStudentInfos();
	return 1;
}