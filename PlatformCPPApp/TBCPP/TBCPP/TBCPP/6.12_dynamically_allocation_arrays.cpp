// �����迭�� ������ Ÿ�ӿ��� ũ�Ⱑ �����Ǿ�� ����� �� �ִ�.
// �����Ҵ� �迭�� ��Ÿ�ӿ� �迭�� ����� �����ϰ� Os���� �������� ������ �������ְ� ����� �� �ִ�.

#include <iostream>
using namespace std;

int main()
{
	//���� �迭�� ����� �� ���Ұ� ��� �� �� �������� ������ Ÿ�ӿ� ������ �Ǿ� �־�� �Ѵ�. �׷��� ���� �տ� const�� ����ؾ� �Ѵ�.
	//const int length = 5;
	//int array[length];
	/*
	int length;
	cin >> length;
	int* array = new int[length];
	//int* array = new int[length](); // 0���� �ʱ�ȭ
	//int* array = new int[length]{}; // 0���� �ʱ�ȭ
	//int* array = new int[length]{11,22,33,44}; // 44 ���� 0���� �ʱ�ȭ
	// length�� �ʱ�ȭ���� ũ�⺸�� ���� ��� ������ �߻�. ���� �ʱ�ȭ ���� �ٸ� �޸𸮿� �Ҵ��Ϸ��ٰ� ������ �߻�

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
	// 1. �迭�� ũ�⸦ �� �ø��� ����� �ٸ� �޸𸮸� �޾ƿ� ������ ���� �ִ� �迭�� �����ؼ� �ٿ� ���� �ڿ� ���� �߰� �Ǵ� �迭�� �߰��Ѵ�.
	// ���� �迭�� ���� ���� �۾��� �ȵȴ�.
	// 2. OS���� �޸𸮿��� �� ��û�� �� �ִµ� �� ���� �ְ� �ȵ� �� �� �ִ�.

	// �ڿ� ��� vector���� resizsing�� ���ش�.

	delete[] array;

	return 0;
}