// 우리가 만든 프로그램에 메모리가 할당되는 건 3가지 종류로 나뉜다.
//	1. static memory allocation(정적 메모리 allocation) 전역변수나 static 변수와 같이 한번 만들면 프로그램이 끝날 때 까지 계속 메모리를 가지고 있음
//	2. 자동 메모리 할당 - 변수나 정적 배열을 선언 했을 때 블록 밖으로 벗어났을 때
//	3. 동적 메모리 할당 - 포인터와 관련지어서 가장 까다로운 부분. 사용법을 잘 알면 여러가지 중요한 개념을 깨달을 수 있고 장기적으로는 표준라이브러리나 직접 만든 라이브러리를 사용하여 편하게 사용하기 때문에 걱정할 필요 X
// 기본적인 사용법과 메모리 관리 부분에 대해서 집중적으로 문제가 될 수 있는 부분에 대해서 알아보자.

#include <iostream>
using namespace std;

int main()
{
	// 데이터를 정적배열을 할당하는 경우
	// int 백만개면 4MB 밖에 되는데 에러가 발생한다.
	// 정적 배열은 static에 들어가는데 static은 용량이 작다.
	// 반면에 동적 배열은 heap에 들어가는데 heap은 용량이 크다.
	//int array[1000000]; // stack

	// OS에서 int 크기(4byte) 메모리 받아오는 방법 2가지
	// 1. 
	int var;
	var = 7;
	// 2. 
	int *ptr = new int{7}; // new int는 메모리 주소를 알려줌
	// *ptr = 7;

	cout << ptr << endl; // 015BB308
	cout << *ptr << endl; // 7

	// OS에서 할당 받은 메모리를 돌려주는 것

	delete ptr;
	cout << "After delete" << endl;
	cout << ptr << endl; // 00008123
	ptr = nullptr;

	if (ptr != nullptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}

	// 메모리가 다 차서 할당받지 못하는 경우
	//	1. 프로그램이 끝나게 프로그래밍을 작성하는 경우
	//	2. 프로그램이 죽지 않고 살아있다가 다른 프로그램이 메모리를 반납하고 다시 할당 받는 방법
	/*
	int* ptr = new (std::nothrow) int{ 7 }; // 예외처리. 오류를 발생시키지 않고 그냥 프로그램이 진행됨
	if (ptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;
	}
	else
	{
		cout << "Could not allocate memoery" << endl;
	}
	*/


	// 최근에는 스마트 포인터를 사용하여 코드를 덜 걱정스럽게 작성할 수 있게 해주지만 직접 new-delete를 사용하는 것 보다 속도가 느리다.


	// memory leak
	while (true)
	{
		int* ptr = new int;
		cout << ptr << endl;

		delete ptr;
	}

	// new - delete는 OS에 갔다오기 때문에 느리기 때문에 적게 사용하는 방식으로 사용하는 것이 좋다.
	// 최근에 나오는 프로그램은 new delete를 다룰 수 없어서 큰 데이터를 다루는 프로그램에서는 느려진다. 그래서 C++를 사용한다.


	return 0;
}