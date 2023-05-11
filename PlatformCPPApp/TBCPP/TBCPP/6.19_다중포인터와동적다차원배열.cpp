// ���� �迭�� ����Ͽ� ������ �迭�� ����� ����� ���� �����ߴ�.
// ���� �޸� �Ҵ��� ���� ������ �迭�� ����� ����� ���캸��.
// ���������͸� ����ϴ� ����� ���������͸� ������� �ʴ� ����� �˾ƺ���.

// ����� �ϸ鼭 õõ�� ����

#include <iostream>

using namespace std;

int main()
{
	int* ptr = nullptr;

	int** ptrptr = nullptr; // �������� �������ε� ���� ������ int�̴�.

	int value = 5;

	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;	// 008FFA3C 5 008FFA54
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl; // 008FFA54 008FFA3C 008FFA48
	cout << **ptrptr << endl; // 5 // *(*ptrptr)

	// ���������ʹ� ���������� ������ �࿭�� ������ �� ���ȴ�.

	const int row = 3;
	const int col = 5;

	const int s2da[][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	//���������͸� �̿��Ͽ� 2���� �迭�� �����޸��Ҵ����� ����� ���
	cout << "�����ͷ� array�� �����ϴ� ���" << endl;
	// �����ͷ� array�� �����ϴ� ���
	int* r1 = new int[col] {1, 5, 3, 4, 5};
	int* r2 = new int[col] {6, 7, 8, 9, 10};
	int* r3 = new int[col] {11, 12, 13, 14, 15};

	int** rows = new int* [row] {r1, r2, r3}; // array�� �ּҸ� ��� ���� ���������� ���
	
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

	
	//for������ ���������� �����ϴ� ���
	int** matrix = new int* [row]; // array�� �ּҸ� ��� ���� ���������� ���

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

	// 1���� ���� �迭�� 2���� �࿭�� ���ϴ� ���
	// (���������͸� ������� �ʴ� ���)
	/*
	int *matrix = new int[row * col];

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; ++c)
			matrix[c + col * r] = s2da[r][c];
	cout << endl;
	*/
	return 0;
} 
