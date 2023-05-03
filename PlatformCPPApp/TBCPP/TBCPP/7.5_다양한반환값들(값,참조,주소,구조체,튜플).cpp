// 함수의 반환값을 어떻게 돌려받을 것인지 살펴보자.

#include <iostream>
#include <array>
using namespace std;

int getValue(int x)
{
	int value = x * 2;
	return value;
}

int* getAddress(int x)
{
	int value = x * 2;
	return &value;
}

int* allocateMemoery(int size)
{
	return new int[size]; // 주소를 반환
}

int& getReference(int x)
{
	int value = x * 2;

	cout << "getReference Value is" << &value << endl; // getReference Value is000000C3C44FF9E4
	return value;
}

int& get(std::array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

int main()
{
	// 값에 의한 리턴
	int value = getValue(3); 
	// 가장 안전하고 간단하지만 복사나 변수의 생성이 여러번 일어나서 속도가 떨어질 것이다.
	// structure나 class, array 등을 사용할 때 데이터가 많다면 값으로 리턴하는 방식은 오래 걸릴 것이다.

	// 주소에 의한 리턴
	//int *address = getAddress(3);// 더 위험// 주소는 함수가 끝날 때 이미 사라졌기 때문에
	//int address = *getAddress(3); // 권장 X // 사라질 변수를 reference를 하는 것이 좋은 방법이 아니다.
	//문제가 생기지는 않지만 이렇게 하는 방법은 권장X

	int* array = allocateMemoery(1024); 

	delete[] array; // new가 있으면 delete가 있어야 되는데 함수와 따로 있다.

	int &referenceValue = getReference(5); // 리턴값 받는 동안만 임시로 잡아주고 있다가 사라진다.

	cout << referenceValue << endl;
	cout << referenceValue << endl;
	cout << &referenceValue << endl; // 000000C3C44FF9E4

	int x = 5;


	std::array<int, 100> my_array;
	my_array[30] = 10;

	get(my_array, 30) = 1024;
	cout << my_array[30] << endl; // 1024
	x = 5;
	return 0;
}