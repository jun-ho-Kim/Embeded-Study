//function - 함수
//함수...기능, 특정한 작업을 수행하기 위한 명령문의 그룹
//표준함수, 사용자 정의 함수
//표준함수 ... standard function - C/C++ 표준라이브러리(std) 제공
//				#include <string> 헤더를 선언하고 기능과 호출방법만 알면 사용
//사용자 정의 함수, (user defined function)
//	개발자가 필요에 따라 만들어 사용하는 함수
//	선언과 정의를 해야, 보통 헤더파일, 소스파일 (선언/구현) 부를 파일로 가지고 있어야 함
//함수 선언....usage
//	[반환할 데이터 타입] [함수이름] [(매개변수)]

//함수정의 방법
//	[반환할 데이터 타입] [함수이름] [(매개변수)] 
// {
//		return [반환할 데이터 타입];
//	}
//함수 호출방법
//	[함수이름](매개변수)

#include <iostream>
void showName(const char* pMsg = nullptr, int length = 10);
//함수 선언에 값을 지정해주는 경우 그 매개변수의 default 값이다.

void swap1(int* lhs = nullptr, int* rhs = nullptr);
void swap2(int* lhs = nullptr, int* rhs = nullptr);

void ShowGuGuDan(int DanStart, int DanFinish, int StepStart=1, int StepFinish=9)
{
	for (int i = StepStart; i <= StepFinish; i++)
	{
		for (int j = DanStart; j <= DanFinish; j++)
		{
			std::cout << j << " * " << i << "\t";
		}
		std::cout << std::endl;
	}

	/*
	2 * 1 = 2	3 * 1 = 3 ... 9 * 1 = 9;
	2 * 2 = 4	3 * 2 = 6 ... 9 * 2 = 18;
	...	...		...
	2 * 9 = 18	3 * 9 = 27 ... 9 * 9 = 81;
	*/

}

int main()
{
	if (0)
	{
		showName("KCCI");
		showName("Intel", 5);

		int a = 10;
		int b = 20;

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		swap1(&a, &b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		a = 10;
		b = 20;

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		swap2(&a, &b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
	}

	ShowGuGuDan(5, 8);

	return 1;
}

void swap1(int* lhs, int* rhs)
{
	int tmp = *lhs; //임시객체를 생성 -> 복사 연산자 -> 대입
	*lhs = *rhs;	//열쇠를 가지고 데이터를 복사(*lhs = *rhs) ? true
	*rhs = tmp;		//임시객체가 가지고 있는 데잍를 복사(*rhs == tmp) ? true
}

void swap2(int* lhs, int* rhs)
{
	int* tmp = lhs; //임시객체를 생성 -> 복사 연산자 -> 대입
	lhs = rhs;	//열쇠를 가지고 데이터를 복사(*lhs = *rhs) ? true
	rhs = tmp;		//임시객체가 가지고 있는 데잍를 복사(*rhs == tmp) ? true
}


void showName(const char* pMsg, int length)
{
	std::cout << pMsg << "_______" << length << std::endl;

	return;
}
