#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// �迭�� ����� �� �ݺ��Ǵ� �ڵ��� �Լ� �ĸ����ͷ� �־��� �� �����ͷ� ���� ��ȯ�Ǿ ����� ���ư��� ������ ���� ���Ҵ�.
// �̸� ������ ���� std::array�̴�.

void printLength(array<int, 5> my_arr) // �Լ��� �Ķ���ͷ� ���� ���� ������ �״�� �����ȴ�.
// �Ϲݺ����� ��� ���簡 �Ǳ� ������  array�� ���� ū ��쿡�� &�� �������.
{
	cout << my_arr.size() << endl;
}

int main()
{
	//int array[5] = { 1,2,3,4,5 };

	array<int, 5> my_arr = { 1,2,3,4,5 };
	// std::array�� <Ÿ��, �迭ũ��>�� ����� �� �迭ũ�⸦ �� ������־�� �Ѵ�.
	// �Լ� �Ķ���͸� �ѱ� �� �ſ� ���ϴ�.
	my_arr = { 0,1,2,3,4 };
	my_arr = { 0,1,2 };
	//my_arr = { 0,1,2,3,4,5 }; //Error

	//cout << my_arr[10] << endl; // �Ҵ�� �迭�� ũ�⸦ üũ���� �ʴ´�.
	//cout << my_arr.at(10) << endl; //  �Ҵ�� �迭�� ũ�⸦ üũ�Ͽ� ����ó���� �Ѵ�. ������ �� �� �ణ ������.

	cout << my_arr.size() << endl; // 5


	array<int, 5> my_arr2 = { 1,21, 3, 40, 5 };
	for (auto &element : my_arr2)
		cout << element << " "; //1 21 3 40 5 
	cout << endl;
	
	std::sort(my_arr2.begin(), my_arr2.end());

	for (auto& element : my_arr2)
		cout << element << " "; //1 3 5 21 40
	cout << endl;

	//std::sort(my_arr2.rbegin(), my_arr2.rend()); // ��������

	return 0;
}