#include <iostream>
#include <string>

int main()
{
	int size = 20;

	int* arr = new int[size];

	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 1;
	}

	std::cout << "�迭 ũ�� = " << size << std::endl;

	std::cout << "������ �� = ";
	for (int i = 0; i < 20; i++)
	{
		if (i == (size - 1))
			std::cout << arr[i];
		else
			std::cout << arr[i] << ", ";
	}

	std::cout << std::endl;

	delete [] arr;

	arr = nullptr;

	int z = 4;

}