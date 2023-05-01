// 정적배열을 대체할 수 있는 std::array를 배웠다.
// 동적배열을 대체할 수 있는 std::vector를 배워보자.

// std::vector는 std::array보다 사용하기 편해 부담이 줄어든다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//std::array<int, 5> array;
	std::vector<int> array;

	std::vector<int> array2 = {1,2,3,4,5};
	cout << array2.size() << endl; // 5

	std::vector<int> array3 = { 1,2,3, };
	cout << array3.size() << endl; // 3

	std::vector<int> array4 { 1,2,3, };
	cout << array4.size() << endl; // 3

	vector<int> arr = { 1,2,3,4,5 };

	for (auto& itr : arr)
		cout << itr << " "; // 1 2 3 4 5
	cout << endl;

	// vector의 장점은 메모리를 알아서 지워준다. delete를 사용해주지 않아도됨.
	// 메모리가 leak하지 않는다.
	// 자신의 길이를 기억해서 함수의 파라미터로 보낼 경우 따로 표시 안해주어도된다.
	// 메모리 관리를 유용하게 사용할 수 있고 동적 메모리 할당을 충분히 활용할 수 있다.
	

	//resize
	arr.resize(10);
	for (auto& itr : arr)
		cout << itr << " "; // 1 2 3 4 5 0 0 0 0 0
	cout << endl;

	arr.resize(2);
	for (auto& itr : arr)
		cout << itr << " "; // 1 2
	cout << endl;


	return 0;
}