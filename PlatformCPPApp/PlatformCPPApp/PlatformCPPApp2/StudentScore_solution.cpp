#include "StudentScore_solution.h"


StudentScore::StudentScore()
{
}

StudentScore::~StudentScore()
{
}

void StudentScore::SetStudentName(const std::string& name)
{
	memset(reinterpret_cast<void*>(&si), 0x00, sizeof(si));
	si.name = std::string(name);
}

void StudentScore::SetSubjectScore(const std::string& subject, const int& score)
{
	std::string strUpper = subject;
	for (int i = 0; i < strUpper.size(); i++)
	{
		strUpper[i] = toupper(strUpper[i]);
	}

	std::transform(strUpper.begin(), strUpper.end(), strUpper.begin(), [](char const& c)
		{
			return std::toupper(c);
		});
	std::transform(strUpper.begin(), strUpper.end(), strUpper.begin(), ::toupper);
	

	for (size_t i = 0; i < eSubjectsMax; i++)
	{
		if (strUpper == SubjectNames[i]) { si.score[i] = score; break; }
	}
}

void StudentScore::DoCalc()
{
	//ȫ�浿 = ����:90, ���� : 90, ���� : 98, �̼� : 88, ���� : 94, ���� : 99���� = ? ? , ��� = ? ? , �ּ� = ? ? , �ִ� = ? ?
	GetSum();
	GetAvg();
	GetMin();
	GetMax();

	vStudents.push_back(si);

}
int StudentScore::ShowStudentInfos()
{
	std::cout << std::endl;
	std::cout << "===================================" << std::endl;

	//python
	//for x in range(0, 10, 1)
	for (size_t i = 0; i < vStudents.size(); i++)
	{
		StudentInfo s = vStudents[i];

		std::cout << s.name << " = ";

		for (size_t k = 0; k < eSubjectsMax; k++)
		{
			std::cout << SubjectNames[k] << " : " << s.score[k] << '\t';
		}
		std::cout << "���� = " << s.sum<< '\t';
		std::cout << "��� = " << s.avg<< '\t';
		std::cout << "�ּ� = " << s.min<< '\t';
		std::cout << "�ִ� = " << s.max<< '\t';
		std::cout << std::endl;

	}
	std::cout << "===================================" << std::endl;
	//for s in vStudents:
	for (auto& s: vStudents)
	{
		std::cout << s.name << " = ";

		for (size_t k = 0; k < eSubjectsMax; k++)
		{
			std::cout << SubjectNames[k] << " : " << s.score[k] << '\t';
		}
		std::cout << "���� = " << s.sum << '\t';
		std::cout << "��� = " << s.avg << '\t';
		std::cout << "�ּ� = " << s.min << '\t';
		std::cout << "�ִ� = " << s.max << '\t';
		std::cout << std::endl;
	}
	
	std::cout << "===================================" << std::endl;

	//���� ��/���/�ּ�/�ִ�
	int total_Sum = 0;
	int total_Avg = 0;
	int total_Min = 999999999;
	int total_Max = -999999999;

	for (auto& s : vStudents)
	{
		total_Sum += s.sum;
		total_Avg += s.avg;
		if (total_Min > s.min)total_Min = s.min;
		if (total_Max < s.max)total_Max = s.max;
	}

	total_Avg = total_Avg /vStudents.size();

	{
		std::cout << "\t\t\t\t\t\t\t���� = " << total_Sum << '\t';
		std::cout << "��� = " << total_Avg << '\t';
		std::cout << "�ּ� = " << total_Min << '\t';
		std::cout << "�ִ� = " << total_Max << '\t';
		std::cout << std::endl;
	}

	return 1;
}
int StudentScore::GetSum()
{
	si.sum = 0;
	for (size_t i = 0; i < eSubjectsMax; i++)
	{
		si.sum += si.score[i];
	}
	return si.sum;
}

float StudentScore::GetAvg()
{
	si.avg = static_cast<float>(GetSum()) / eSubjectsMax;

	return 0.0f;
}

int StudentScore::GetMin()
{
	int minTmp = 9999999;
	for (size_t i = 0; i < eSubjectsMax; i++)
	{
		if (minTmp > si.score[i])
		{
			minTmp = si.score[i];
		}
	}
	si.min = minTmp;
	return 0;
}

int StudentScore::GetMax()
{
	int maxTmp = -9999999;
	for (size_t i = 0; i < eSubjectsMax; i++)
	{
		if (maxTmp < si.score[i])
		{
			maxTmp = si.score[i];
		}
	}
	si.max = maxTmp;
	return 0;
}

