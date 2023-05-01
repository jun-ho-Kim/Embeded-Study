// 정적배열은 컴파일 타임에서 크기가 결정되어야 사용할 수 있다.
// 동적할당 배열은 런타임에 배열의 사이즈를 결정하고 Os에서 가져오기 때문에 유동성있게 사용할 수 있다.

#include <iostream>
using namespace std;

int main()
{
	//정적 배열을 사용할 때 원소가 몇개가 들어갈 수 있을지는 컴파일 타임에 고정이 되어 있어야 한다. 그래서 변수 앞에 const를 사용해야 한다.
	//const int length = 5;
	//int array[length];
	/*
	int length;
	cin >> length;
	int* array = new int[length];
	//int* array = new int[length](); // 0으로 초기화
	//int* array = new int[length]{}; // 0으로 초기화
	//int* array = new int[length]{11,22,33,44}; // 44 이후 0으로 초기화
	// length가 초기화해준 크기보다 작은 경우 에러가 발생. 남은 초기화 값은 다른 메모리에 할당하려다가 에러가 발생

	array[0] = 1;
	array[1] = 2;

	for (int i = 0; i < length; ++i)
	{ 
		cout << (uintptr_t)& array[i] << endl;
		cout << array[i] << endl;
	}

	delete[] array;
	*/


	int fixedArray[] = { 1,2,3,4,5 };
	int* array = new int[5] {1, 2, 3, 4, 5};


	//resizing
	// 1. 배열의 크기를 더 늘리는 방법은 다른 메모리를 받아온 다음에 원래 있던 배열을 복사해서 붙여 놓고 뒤에 새로 추가 되는 배열을 추가한다.
	// 정적 배열은 위와 같은 작업도 안된다.
	// 2. OS에서 메모리에서 더 요청할 수 있는데 될 수도 있고 안될 수 도 있다.

	// 뒤에 배울 vector에서 resizsing을 해준다.

	delete[] array;

	return 0;
}