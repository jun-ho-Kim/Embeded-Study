#include <iostream>
//포인터(Pointer): 무엇인가를 가리키는 것
//포인터값 : 메모리 주소를 의미
//포인터 변수를 사용...포인터의 값

//포인터의 사용 이유
//	배열과 같은 연속된 데이터에 접근과 조작이 용이
//ex) int arr[10]={1,2,3,...}
//int* p = arr
//p 1~10.... arr[index] // 데이터가 아닌 주소 값으로 들고 다닐 수 있음
//메모리의 동적할당/해제를 통해 유동적인 메모리 관리가 가능합니다.
//int arr[10]...size 결정
//int* p = nullptr;

//원하는 시점...p = new int[size];//유동성을 확보...자원의 반환 delete []
//복잡한 잘 구조를 효율적으로 처리
//call by address에 의한 전역 변수의 사용을 억제합니다.

//포인터의 선언부
//[type..int double char]*	[포인터 변수 이름] = nullptr;
//포인터의 초기화
//[type..int double char]*	[포인터 변수 이름] = &[변수];

int main()
{
	if (0)
	{
		int num = 10;
		int* pnum = nullptr;
		pnum = &num; // 데이터가 존재하는 메모리의 주소를 전달

		const int sz = 10;
		int nArray[sz] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int* pArr1 = nArray; // pArr 주소값을 가지고 있다.
		int* pArr2 = &nArray[0]; //[0] => 1,데이터가 존재하는 메모리의 주소를 전달

		//	시작...끝...증감조건
		// i = 0, i<10, i++, 0,1,2
		// i = 10, i>=0, i--, 10,9,8
		size_t length = sizeof(nArray) / sizeof(int);//10
		//sizeof(nArray) ... 10*scale(int..4) --40bytes
		//void func(int * pData, int length)
		//{  pData  }

		// 직접적으로 데이터에 접근 // nArray[i]
		// 간접적으로 데이터에 접근 // (pArr + i)

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
			// 직접적으로 데이터에 접근
			std::cout << "data = " << *(pArr) << "  address = " << (pArr) << std::endl;
			std::cout << "data = " << *(pArr) << "  address = " << (pArr) << std::endl;
			pArr++;
			// 간접적으로 데이터에 접근

		/*	std::cout << "index= " << i << "data = " << *(pArr + i) << "addr = " << (pArr + i) << std::endl;
			std::cout << "index= " << i << "data = " << *(pArr++) << "addr = " << *(pArr) << std::endl;
			std::cout << "data= " << *(pArr++) << "address = " << (pArr++) << std::endl;*/
		}
	}

	if (0)
	{
		//pointer 동적 메모리 할당/해제
		const int sz = 100;
		//int* pArr = new int[sz]; // 동적메모리 생성..쓰레기 값이 들어가 있음 //(초기화를 안해주어서)
		int* pArr = new int[100]{ 0, }; // 동적메모리 생성...초기화 0으로 됨
		for (size_t i = 0; i < sz; i++)
		{
			std::cout << i << "  init " << pArr[i];
			pArr[i] = i;
			std::cout << "    new Data    " << pArr[i] << std::endl;
		}

		int value = 100;
		if (value > 10)
			return -1;
		// 동적할당 후 delete를 안해주는 경우 

		if (pArr != nullptr)
		{
			delete[] pArr;
			pArr = nullptr;
		}


		//동적메모리할당을 할 경우에는 CPU와 메모리가 여유가 있어야 비정상적인 발생이 일어날 수 있다.
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

	//스마트 포인터...smart pointer
	//new만 사용... create()....destory() ???
	//std::shared_ptr<int> students = std::make_shared<int>(sz);
	std::shared_ptr<int> students(new int[10]);
	int* pstd = students.get();
	for (size_t i = 0; i < 10; i++)
	{
		pstd[i] = i + 100;
	}

	return 1;
}