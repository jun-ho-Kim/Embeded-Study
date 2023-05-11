#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	//for(int i = 0; i< ... l i++)

	//for-each
	for (int number : fibonacci) // fibonacci에 있는 원소들이 한 번씩 들어오게 된다.
		cout << number << " ";

	cout << endl;

	//for (int number : fibonacci)는 값이 바뀌지 않음
	// for (auto& number : fibonacci)
	for (int& number : fibonacci) // for-each에서 값을 바꾸려면 참조변수를 사용해야한다.
	{
		number = 10;
		cout << number << " ";
	}
	cout << endl;

	// 하지만 동적할당을 사용하는 경우에는 for-each를 사용할 수 없게 된다.
	// 이럴 경우 for-each보다 더 좋은 vector를 사용하면 된다.
	//vector<int> fibonacci = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	//최대값 예제
	int max_number = numeric_limits<int>::lowest();

	for (const auto& n : fibonacci)
		max_number = std::max(max_number, n);

	cout << max_number << endl;

	return 0;
}