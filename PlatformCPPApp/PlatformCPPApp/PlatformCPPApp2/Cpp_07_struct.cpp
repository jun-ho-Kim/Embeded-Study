#include <iostream>
#include <string>
#include <vector>
//����ü :: strucrt
//����� ���� ������ Ÿ��

/*
����ü ���� �� ����
struct [��ũ��]
{
	��� ������
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

	//�������� ����� ���
	_stEmployee person = { "ȫ�浿", 100 };
	person.age = 30;
	person.name = "�̼���";

	int* pA = new int(10);
	*pA = 20;
	delete pA;

	//_stEmployee* pPerson = new _stEmployee("ȫ�浿", 100);
	//pPerson->age = 30;
	//pPerson->name = "�̼���";
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
	student.name = "ȫ�浿";
	student.age = 18;
	student.item[0].subject = "����";
	student.item[0].score = 90;
	student.item[1].subject = "����";
	student.item[1].score = 95;
	student.item[2].subject = "����";
	student.item[2].score = 87;
	//����غ��ô�.
	//ȫ�浿 18 ���� 90 ���� 95 ���� 87

	std::cout << student.name;
	std::cout << student.age;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << student.item[i].subject << '\t';
		std::cout << student.item[i].score << '\t';
	}
	std::cout << std::endl;

	std::vector<_stStudent> vStudents;
	vStudents.push_back(student); //����ü ������ ������ �־���.

	student.name = "�̼���";
	student.age = 19;
	//student.item[0].subject = "����";
	student.item[0].score = 100;
	//student.item[1].subject = "����";
	student.item[1].score = 97;
	//student.item[2].subject = "����";
	student.item[2].score = 95;
	vStudents.push_back(student);

	for (size_t i = 0; i < vStudents.size(); i++)
	{
		_stStudent s = vStudents[i];
		//�л� ������ ����ϼ���.
		//�̸�  ���� ���� ���� ...

		std::cout << "vector\n" << s.name << "   " << s.age << "   ";
		for(int i = 0; i < 3; i++)
			std::cout << s.item[i].subject << "   " << s.item[i].score << "   ";
		std::cout << std::endl;
	}

	vStudents[0]; //ȫ�浿
	vStudents[0].item[0]; //ȫ�浿
	vStudents[0].item[1];
	
	std::vector<int> vInt;

	vInt.push_back(1);
	vInt.push_back(2);
	vInt.push_back(3);
	vInt.push_back(4);
	vInt.push_back(5);
	std::cout << vInt[0] << vInt[1] << vInt[2] << vInt[3] << vInt[4] << std::endl;
	//���͸� ����ϸ� ũ�Ⱑ �󸶳� �Ǵ��� �𸣴� �����Ҵ��� �����ϱ� ����
	*/
	return 1;
}