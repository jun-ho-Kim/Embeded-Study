#include <iostream>
//�迭...array
//������ �ڷ����� �������� ��, ����ϴ� Ÿ��
int main()
{
	if (0)
	{
		int arrScore[5]; //����...����
		arrScore[0] = 10;
		arrScore[1] = 20;
		arrScore[2] = 30;
		arrScore[3] = 40;
		arrScore[4] = 50;

		//�迭�� Ÿ��...�迭�� �̸�[ũ��] = {�ʱⰪ0...�ʱⰪN-1}
		const int arrSize = 5;
		int arrayScore1[arrSize] = { 10,20,30,40,50 }; //����...����
		double arrayScore2[arrSize] = { 10,20,30,40,50 }; //����...����
		long arrayScore3[arrSize] = { 10,20,30,40,50 }; //����...����

		//�迭�� arr[i] �̷��� �������ֱ� ���ŷο�� Pointer ������ ���Դ�.
		// �迭�� ������ �����ϰ� �ϱ� ���ؼ� �����͸� ���
		//arrScore[0]...data // arrScore...address

		int* pArrScore = nullptr;

		pArrScore = arrScore;
		//index access
		std::cout << "1.address = " << pArrScore << " value = " << *pArrScore << std::endl;
		std::cout << "2.address = " << ++pArrScore << " value = " << *pArrScore << std::endl;
		std::cout << "3.address = " << ++pArrScore << " value = " << *pArrScore << std::endl;
		std::cout << "4.address = " << ++pArrScore << " value = " << *pArrScore << std::endl;
		std::cout << "5.address = " << ++pArrScore << " value = " << *pArrScore << std::endl;

		//�����Ͱ� ������ �Ѿ�� �Ǹ� �����Ⱚ�� �� �ٸ� �޸��ּҿ��� ������ ��ĥ �� �ִ�.

		//array access
		//std::cout << "1.address = " << pArrScore[0] << " value = " << *pArrScore << std::endl;
		//std::cout << "2.address = " << ++pArrScore[1] << " value = " << *pArrScore << std::endl;
		//std::cout << "3.address = " << ++pArrScore[2] << " value = " << *pArrScore << std::endl;
		//std::cout << "4.address = " << ++pArrScore[3] << " value = " << *pArrScore << std::endl;
		//std::cout << "5.address = " << ++pArrScore[4] << " value = " << *pArrScore << std::endl;
	}

	//Quize ... �л� ������ DB�� �迭�� ����Ǿ� �ִ�.
	//0-kr, 1-eng, 2-math, 3-music, 4-geometry
	//�Ʒ� ������ �հ� ����� ����Ͻÿ�
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

	//���� �޸� �Ҵ�
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
		memset(pArr, 0x00, sizeof(int)* 10); //10bytes...char[1], int[4], long long[8] // �޸𸮿� 0x00
		//memset�� void �����ͷ� ���
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