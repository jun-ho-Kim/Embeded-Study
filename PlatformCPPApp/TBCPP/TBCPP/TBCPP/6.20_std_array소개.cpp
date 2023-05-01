#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

// 배열을 사용할 때 반복되는 코딩과 함수 파리마터로 넣었을 때 포인터로 강제 변환되어서 사이즈가 날아가서 불편한 점이 많았다.
// 이를 보완한 것이 std::array이다.

void printLength(array<int, 5> my_arr) // 함수의 파라미터로 보낼 때도 성질이 그대로 유지된다.
// 일반변수인 경우 복사가 되기 때문에  array가 값이 큰 경우에는 &를 사용하자.
{
	cout << my_arr.size() << endl;
}

int main()
{
	//int array[5] = { 1,2,3,4,5 };

	array<int, 5> my_arr = { 1,2,3,4,5 };
	// std::array는 <타입, 배열크기>를 사용할 때 배열크기를 꼭 명시해주어야 한다.
	// 함수 파라미터를 넘길 때 매우 편하다.
	my_arr = { 0,1,2,3,4 };
	my_arr = { 0,1,2 };
	//my_arr = { 0,1,2,3,4,5 }; //Error

	//cout << my_arr[10] << endl; // 할당된 배열의 크기를 체크하지 않는다.
	//cout << my_arr.at(10) << endl; //  할당된 배열의 크기를 체크하여 예외처리를 한다. 로직이 더 들어가 약간 느리다.

	cout << my_arr.size() << endl; // 5


	array<int, 5> my_arr2 = { 1,21, 3, 40, 5 };
	for (auto &element : my_arr2)
		cout << element << " "; //1 21 3 40 5 
	cout << endl;
	
	std::sort(my_arr2.begin(), my_arr2.end());

	for (auto& element : my_arr2)
		cout << element << " "; //1 3 5 21 40
	cout << endl;

	//std::sort(my_arr2.rbegin(), my_arr2.rend()); // 역순정렬

	return 0;
}