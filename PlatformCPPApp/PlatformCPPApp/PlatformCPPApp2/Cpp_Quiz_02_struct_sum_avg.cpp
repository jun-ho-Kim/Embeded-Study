#include <iostream>
#include <string>
#include <vector>
/*
학생 성적관리 프로그램을 만듭니다.
구성요소 :
	1) 학생 추가 (5명 제한) for(<5)...cin 
	2) 학생 과목과 성적 입력 (국어, 영어, 수학, 과학, 음악)...input items
	3) 5명 입력 완료 후 각 과목별 합계, 평균을 계산...5명입력이 완료되면 sumKorFor
	4) 입력한 데이터와 3)의 값을 출력하시오.
	(strcut, vector, cout, cin을 활용)
	이름		나이		국어		영어		수학		과학		음악
	-----------------------------------------------------
	홍길동1	29		80		80		80		80		80
	홍길동2	29		80		80		80		80		80
	홍길동3	29		80		80		80		80		80
	홍길동4	29		80		80		80		80		80
	홍길동5	29		80		80		80		80		80
	-----------------------------------------------------
			합계		400		400		400		400		400
			평균		80		80		80		80		80
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
	// 학생 정보 입력
	for (int i = 0; i < kMaxNumStudents; i++) {
		Student student;

		cout << "이름을 입력하세요: ";
		cin >> student.name;

		cout << "나이를 입력하세요: ";
		cin >> student.age;

		cout << "국어 성적을 입력하세요: ";
		cin >> student.kor;

		cout << "영어 성적을 입력하세요: ";
		cin >> student.eng;

		cout << "수학 성적을 입력하세요: ";
		cin >> student.math;

		cout << "과학 성적을 입력하세요: ";
		cin >> student.sci;

		cout << "음악 성적을 입력하세요: ";
		cin >> student.music;

		students.push_back(student);
	}

	// 각 과목별 합계, 평균 계산
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

	//정수 1 -> 실수 1.00000000
	
	const int kNumStudents = students.size();

	const double kAvgKor = static_cast<double>(kor_sum) / kNumStudents;
	//1. (kor_sum*1.0)....temp obj double...float
	//2. temp obj / studentcnt
	//3.
	const double kAvgEng = static_cast<double>(eng_sum) / kNumStudents;
	const double kAvgMath = static_cast<double>(math_sum) / kNumStudents;
	const double kAvgSci = static_cast<double>(sci_sum) / kNumStudents;
	const double kAvgMusic = static_cast<double>(music_sum) / kNumStudents;

	// 학생 정보와 각 과목별 합계, 평균 출력
	cout << "이름\t나이\t국어\t영어\t수학\t과학\t음악" << endl;
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
	cout << "합계\t\t" << kor_sum << "\t" << eng_sum << "\t" << math_sum << "\t" << sci_sum << "\t" << music_sum << endl;
	cout << "평균\t\t" << kAvgKor << "\t" << kAvgEng << "\t" << kAvgMath << "\t" << kAvgSci << "\t" << kAvgMusic << endl;

	//pushback은 메모리 copy

	/*
	//내가 쓴 정답
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
	std::cout << "성적을 입력할 학생 수를 입력하시오: ";
	std::cin >> studentcnt;
	//std::cin.getline(s1.name, sizeof(s1.name));
	//std::cout << "학생이름을 입력하세요2" << std::endl;
	//std::cin >> student.name;
	student.item[0].subject = "국어";
	student.item[1].subject = "영어";
	student.item[2].subject = "수학";
	student.item[3].subject = "과학";
	student.item[4].subject = "음악";
	
	for (int i = 0; i < studentcnt; i++)
	{
		std::cout << "학생이름을 입력하세요";
		std::cin >> student.name;
		for (int j = 0; j < 5; j++)
		{
			std::cout << student.item[j].subject << "의 점수를 입력하세요:";
			std::cin >> student.item[j].score;
		}

		vStudents.push_back(student);
	}

	std::cout << "이름\t국어\t영어\t수학\t과학\t음악" << "  " << std::endl;
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
	//std::cin >> "학생이름은2" << student.name << std::endl;
	*/
}
