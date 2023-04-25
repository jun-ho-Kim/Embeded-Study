#include <iostream>
//배열...array
//동일한 자료형이 연속적일 때, 사용하는 타입
int main()
{
	if (0)
	{
		int arrScore[5]; //선언...생성
		arrScore[0] = 10;
		arrScore[1] = 20;
		arrScore[2] = 30;
		arrScore[3] = 40;
		arrScore[4] = 50;

		//배열의 타입...배열의 이름[크기] = {초기값0...초기값N-1}
		const int arrSize = 5;
		int arrayScore1[arrSize] = { 10,20,30,40,50 }; //선언...생성
		double arrayScore2[arrSize] = { 10,20,30,40,50 }; //선언...생성
		long arrayScore3[arrSize] = { 10,20,30,40,50 }; //선언...생성

		//배열을 arr[i] 이렇게 지정해주기 번거로우니 Pointer 개념이 나왔다.
		// 배열의 접근을 용이하게 하기 위해서 포인터를 사용
		//arrScore[0]...data // arrScore...address

		int* pArrScore = nullptr;

		pArrScore = arrScore;
		//index access
		std::cout << "1.address = " << pArrScore << " value = " << *pArrScore << std::endl;
		std::cout << "2.address = " << ++pArrScore << " value = " << *pArrScore << std::endl;
		std::cout << "3.address = " << ++pArrScore << " value = " << *pArrScore << std::endl;
		std::cout << "4.address = " << ++pArrScore << " value = " << *pArrScore << std::endl;
		std::cout << "5.address = " << ++pArrScore << " value = " << *pArrScore << std::endl;

		//포인터가 범위를 넘어가게 되면 쓰레기값이 들어가 다른 메모리주소에도 영향을 미칠 수 있다.

		//array access
		//std::cout << "1.address = " << pArrScore[0] << " value = " << *pArrScore << std::endl;
		//std::cout << "2.address = " << ++pArrScore[1] << " value = " << *pArrScore << std::endl;
		//std::cout << "3.address = " << ++pArrScore[2] << " value = " << *pArrScore << std::endl;
		//std::cout << "4.address = " << ++pArrScore[3] << " value = " << *pArrScore << std::endl;
		//std::cout << "5.address = " << ++pArrScore[4] << " value = " << *pArrScore << std::endl;
	}

	//Quize ... 학생 성적의 DB는 배열에 저장되어 있다.
	//0-kr, 1-eng, 2-math, 3-music, 4-geometry
	//아래 성저의 합과 평균을 출력하시오
	const int subjects = 5;
	int score[subjects] = { 89,90,95,79,93 };

	int sum = 0;
	int avg = 0;
	for (int len = 0; len < subjects; len++)
	{
		sum += score[len];
		avg = sum / subjects;
	}
	std::cout << "sum is " << sum << std::endl;
	std::cout << "avg is " << avg << std::endl;

	//동적 메모리 할당
	int* pArr = nullptr;

	if (0)
	{
		pArr = new int[10];
		if (pArr)
		{
			delete[] pArr;
			pArr = nullptr;
		}
	}
	else if (1)
	{
		//create
		pArr = new int[10];
		//Data Processing
		//init
		//for (size_t i = 0; i < 10; i++) pArr[i] = 0;
		memset(pArr, 0x00, sizeof(int)* 10); //10bytes...char[1], int[4], long long[8] // 메모리에 0x00
		//memset은 void 포인터로 사용
		for (size_t subject = 0; subject < subjects; subject++)
		{
			pArr[subject] = pArr[subject];
		}

		if (pArr)
		{
			delete[] pArr;
			pArr = nullptr;
		}
	}


}