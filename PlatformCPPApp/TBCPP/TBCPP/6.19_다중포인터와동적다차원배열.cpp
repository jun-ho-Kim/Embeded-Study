// 정적 배열을 사용하여 다차원 배열을 만드는 방법에 대해 공부했다.
// 동적 메모리 할당을 통해 다차원 배열을 만드는 방법을 살펴보자.
// 이중포인터를 사용하는 방법과 이중포인터를 사용하지 않는 방법을 알아보자.

// 디버그 하면서 천천히 보기

#include <iostream>

using namespace std;

int main()
{
	int* ptr = nullptr;

	int** ptrptr = nullptr; // 포인터의 포인터인데 원래 변수는 int이다.

	int value = 5;

	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;	// 008FFA3C 5 008FFA54
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl; // 008FFA54 008FFA3C 008FFA48
	cout << **ptrptr << endl; // 5 // *(*ptrptr)

	// 이중포인터는 교과서적인 이차원 행열를 구현할 때 사용된다.

	const int row = 3;
	const int col = 5;

	const int s2da[][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	//이중포인터를 이용하여 2차원 배열을 동적메모리할당으로 만드는 방법
	cout << "포인터로 array를 구현하는 방법" << endl;
	// 포인터로 array를 구현하는 방법
	int* r1 = new int[col] {1, 5, 3, 4, 5};
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};

	int** rows = new int* [row] {r1, r2, r3}; // array의 주소를 담기 위해 이중포인터 사용
	
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << rows[r][c] << " ";
		cout << endl;
	}

	delete[] r1;
	delete[] r2;
	delete[] r3;
	delete[] rows;

	
	//for문으로 이중포인터 구현하는 방법
	int** matrix = new int* [row]; // array의 주소를 담기 위해 이중포인터 사용

	for (int r = 0; r < row; ++r)
		matrix[r] = new int[col];

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; ++c)
			matrix[r][c] = s2da[r][c];

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

	for (int r = 0; r < row; ++r)
		delete[] matrix[r];

	delete[] matrix;

	// 1차원 동적 배열로 2차원 행열을 구하는 방법
	// (이중포인터를 사용하지 않는 방법)
	/*
	int *matrix = new int[row * col];

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; ++c)
			matrix[c + col * r] = s2da[r][c];
	cout << endl;
	*/
	return 0;
} 
