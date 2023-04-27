#include <iostream>
//������(Pointer): �����ΰ��� ����Ű�� ��
//�����Ͱ� : �޸� �ּҸ� �ǹ�
//������ ������ ���...�������� ��

//�������� ��� ����
//	�迭�� ���� ���ӵ� �����Ϳ� ���ٰ� ������ ����
//ex) int arr[10]={1,2,3,...}
//int* p = arr
//p 1~10.... arr[index] // �����Ͱ� �ƴ� �ּ� ������ ��� �ٴ� �� ����
//�޸��� �����Ҵ�/������ ���� �������� �޸� ������ �����մϴ�.
//int arr[10]...size ����
//int* p = nullptr;

//���ϴ� ����...p = new int[size];//�������� Ȯ��...�ڿ��� ��ȯ delete []
//������ �� ������ ȿ�������� ó��
//call by address�� ���� ���� ������ ����� �����մϴ�.

//�������� �����
//[type..int double char]*	[������ ���� �̸�] = nullptr;
//�������� �ʱ�ȭ
//[type..int double char]*	[������ ���� �̸�] = &[����];

int main()
{
	if (0)
	{
		int num = 10;
		int* pnum = nullptr;
		pnum = &num; // �����Ͱ� �����ϴ� �޸��� �ּҸ� ����

		const int sz = 10;
		int nArray[sz] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int* pArr1 = nArray; // pArr �ּҰ��� ������ �ִ�.
		int* pArr2 = &nArray[0]; //[0] => 1,�����Ͱ� �����ϴ� �޸��� �ּҸ� ����

		//	����...��...��������
		// i = 0, i<10, i++, 0,1,2
		// i = 10, i>=0, i--, 10,9,8
		size_t length = sizeof(nArray) / sizeof(int);//10
		//sizeof(nArray) ... 10*scale(int..4) --40bytes
		//void func(int * pData, int length)
		//{  pData  }

		// ���������� �����Ϳ� ���� // nArray[i]
		// ���������� �����Ϳ� ���� // (pArr + i)

		int* pArr = nArray;
		for (size_t i = 0; i < length; i++)
		{

			std::cout << "data= " << *(pArr + i) << "  " << nArray[i];

			std::cout << "addr= " << (pArr + i) << "  " << &nArray[i] << std::endl;



			//std::cout << "addr = " << *(pArr+i) << "" << &nArray[i] << "  " << std::endl;
			//std::cout << "index= " << i << "data = " << *(pArr++) << "addr = " << *(pArr + i) << std::endl;

		}
		pArr = nArray;
		for (size_t i = 0; i < length; i++)
		{
			std::cout << "data = " << *(pArr) << "  " << (pArr) << "  ";
			// ���������� �����Ϳ� ����
			std::cout << "data = " << *(pArr) << "  address = " << (pArr) << std::endl;
			std::cout << "data = " << *(pArr) << "  address = " << (pArr) << std::endl;
			pArr++;
			// ���������� �����Ϳ� ����

		/*	std::cout << "index= " << i << "data = " << *(pArr + i) << "addr = " << (pArr + i) << std::endl;
			std::cout << "index= " << i << "data = " << *(pArr++) << "addr = " << *(pArr) << std::endl;
			std::cout << "data= " << *(pArr++) << "address = " << (pArr++) << std::endl;*/
		}
	}

	if (0)
	{
		//pointer ���� �޸� �Ҵ�/����
		const int sz = 100;
		//int* pArr = new int[sz]; // �����޸� ����..������ ���� �� ���� //(�ʱ�ȭ�� �����־)
		int* pArr = new int[100]{ 0, }; // �����޸� ����...�ʱ�ȭ 0���� ��
		for (size_t i = 0; i < sz; i++)
		{
			std::cout << i << "  init " << pArr[i];
			pArr[i] = i;
			std::cout << "    new Data    " << pArr[i] << std::endl;
		}

		int value = 100;
		if (value > 10)
			return -1;
		// �����Ҵ� �� delete�� �����ִ� ��� 

		if (pArr != nullptr)
		{
			delete[] pArr;
			pArr = nullptr;
		}


		//�����޸��Ҵ��� �� ��쿡�� CPU�� �޸𸮰� ������ �־�� ���������� �߻��� �Ͼ �� �ִ�.
	}

	if (0)
	{
		const int sz = 10000000;
		int* pArr = nullptr;
		for (size_t i = 0; i < 50; i++)
		{
			//create memory
			pArr = new int[sz] {0, };

			//algorithm
			int value = 100;
			if (value > 10)
			{
				continue;
			}
			else
			{
				break;
			}
		}

		if (pArr != nullptr)
		{
			delete[] pArr;
			pArr = nullptr;
		}
	}

	if (0)
	{
		const int sz = 100000000;
		int* pArr = nullptr;

		int a = 20;

		{
			int a = 10;
			int b = 0;
		}

		{
			int* pArr = nullptr;
			pArr = new int[sz] {0, };

			if (false)
			{
				if (pArr != nullptr)
				{
					delete[] pArr;
					pArr = nullptr;
				}
			}

		}
	}

	int* pArr = nullptr;
	//create memoery
	const int sz = 100000000;

	pArr = new int[sz] {0, };

	//����Ʈ ������...smart pointer
	//new�� ���... create()....destory() ???
	//std::shared_ptr<int> students = std::make_shared<int>(sz);
	std::shared_ptr<int> students(new int[10]);
	int* pstd = students.get();
	for (size_t i = 0; i < 10; i++)
	{
		pstd[i] = i + 100;
	}

	return 1;
}