#include <iostream>
#include <string>
#include <vector>
/*
�л� �������� ���α׷��� ����ϴ�.
������� :
	1) �л� �߰� (5�� ����) for(<5)...cin 
	2) �л� ����� ���� �Է� (����, ����, ����, ����, ����)...input items
	3) 5�� �Է� �Ϸ� �� �� ���� �հ�, ����� ���...5���Է��� �Ϸ�Ǹ� sumKorFor
	4) �Է��� �����Ϳ� 3)�� ���� ����Ͻÿ�.
	(strcut, vector, cout, cin�� Ȱ��)
	�̸�		����		����		����		����		����		����
	-----------------------------------------------------
	ȫ�浿1	29		80		80		80		80		80
	ȫ�浿2	29		80		80		80		80		80
	ȫ�浿3	29		80		80		80		80		80
	ȫ�浿4	29		80		80		80		80		80
	ȫ�浿5	29		80		80		80		80		80
	-----------------------------------------------------
			�հ�		400		400		400		400		400
			���		80		80		80		80		80
*/

int main()
{
	using namespace std;

	struct Student {
		string name;
		int age;
		int kor;
		int eng;
		int math;
		int sci;
		int music;
	};

	vector<Student> students;
	const int kMaxNumStudents = 5;

	//python
	//for student in student:

	// c++
	//for (const auto& student : students) 
	//{
	//	kor_sum += student.kor;
	//	eng_sum += student.eng;
	//	math_sum += student.math;
	//	sci_sum += student.sci;
	//	music_sum += student.music;
	//}

	//c, c++
	// �л� ���� �Է�
	for (int i = 0; i < kMaxNumStudents; i++) {
		Student student;

		cout << "�̸��� �Է��ϼ���: ";
		cin >> student.name;

		cout << "���̸� �Է��ϼ���: ";
		cin >> student.age;

		cout << "���� ������ �Է��ϼ���: ";
		cin >> student.kor;

		cout << "���� ������ �Է��ϼ���: ";
		cin >> student.eng;

		cout << "���� ������ �Է��ϼ���: ";
		cin >> student.math;

		cout << "���� ������ �Է��ϼ���: ";
		cin >> student.sci;

		cout << "���� ������ �Է��ϼ���: ";
		cin >> student.music;

		students.push_back(student);
	}

	// �� ���� �հ�, ��� ���
	int kor_sum = 0;
	int eng_sum = 0;
	int math_sum = 0;
	int sci_sum = 0;
	int music_sum = 0;

	//for (const auto& student : students) {
	//    kor_sum += student.kor;
	//    eng_sum += student.eng;
	//    math_sum += student.math;
	//    sci_sum += student.sci;
	//    music_sum += student.music;
	//}
	for (size_t i = 0; i < students.size(); i++)
	{
		Student student = students[i];
		kor_sum += student.kor;
		eng_sum += student.eng;
		math_sum += student.math;
		sci_sum += student.sci;
		music_sum += student.music;
	}

	//���� 1 -> �Ǽ� 1.00000000
	
	const int kNumStudents = students.size();

	const double kAvgKor = static_cast<double>(kor_sum) / kNumStudents;
	//1. (kor_sum*1.0)....temp obj double...float
	//2. temp obj / studentcnt
	//3.
	const double kAvgEng = static_cast<double>(eng_sum) / kNumStudents;
	const double kAvgMath = static_cast<double>(math_sum) / kNumStudents;
	const double kAvgSci = static_cast<double>(sci_sum) / kNumStudents;
	const double kAvgMusic = static_cast<double>(music_sum) / kNumStudents;

	// �л� ������ �� ���� �հ�, ��� ���
	cout << "�̸�\t����\t����\t����\t����\t����\t����" << endl;
	cout << "---------------------------------------------------" << endl;

	//for (const auto& student : students) {
	//    cout << student.name << "\t" << student.age << "\t" << student.kor << "\t" << student.eng << "\t" << student.math << "\t" << student.sci << "\t" << student.music << endl;
	//}
	for (size_t i = 0; i < students.size(); i++)
	{
		Student student = students[i];
		cout << student.name << "\t" << student.age << "\t" << student.kor << "\t" << student.eng << "\t" << student.math << "\t" << student.sci << "\t" << student.music << endl;
	}

	cout << "---------------------------------------------------" << endl;
	cout << "�հ�\t\t" << kor_sum << "\t" << eng_sum << "\t" << math_sum << "\t" << sci_sum << "\t" << music_sum << endl;
	cout << "���\t\t" << kAvgKor << "\t" << kAvgEng << "\t" << kAvgMath << "\t" << kAvgSci << "\t" << kAvgMusic << endl;

	//pushback�� �޸� copy

	/*
	//���� �� ����
	struct _stClass
	{
		std::string subject;
		int score;
	};

	struct _sStudent
	{
		std::string name;
		_stClass item[5];
	};

	std::vector<_sStudent> vStudents;

	_sStudent student;
	//vStudents.push_back(student);

	int studentcnt;
	std::cout << "������ �Է��� �л� ���� �Է��Ͻÿ�: ";
	std::cin >> studentcnt;
	//std::cin.getline(s1.name, sizeof(s1.name));
	//std::cout << "�л��̸��� �Է��ϼ���2" << std::endl;
	//std::cin >> student.name;
	student.item[0].subject = "����";
	student.item[1].subject = "����";
	student.item[2].subject = "����";
	student.item[3].subject = "����";
	student.item[4].subject = "����";
	
	for (int i = 0; i < studentcnt; i++)
	{
		std::cout << "�л��̸��� �Է��ϼ���";
		std::cin >> student.name;
		for (int j = 0; j < 5; j++)
		{
			std::cout << student.item[j].subject << "�� ������ �Է��ϼ���:";
			std::cin >> student.item[j].score;
		}

		vStudents.push_back(student);
	}

	std::cout << "�̸�\t����\t����\t����\t����\t����" << "  " << std::endl;
	for (int i = 0; i < studentcnt; i++)
	{
		int sum = 0;
		int avg = 0;
		std::cout << vStudents[i].name << "\t";
		for (int j = 0; j < 5; j++)
		{
			std::cout << vStudents[i].item[j].score << "\t";
		}	
		std::cout << std::endl;
	}


	for (int i = 0; i < 5; i++)
	{
		std::cout << vStudents[i].item[j].score << "\t";
	}
	//std::cin >> "�л��̸���2" << student.name << std::endl;
	*/
}
