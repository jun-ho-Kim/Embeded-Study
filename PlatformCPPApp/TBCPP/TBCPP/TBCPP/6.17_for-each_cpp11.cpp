#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	//for(int i = 0; i< ... l i++)

	//for-each
	for (int number : fibonacci) // fibonacci�� �ִ� ���ҵ��� �� ���� ������ �ȴ�.
		cout << number << " ";

	cout << endl;

	//for (int number : fibonacci)�� ���� �ٲ��� ����
	// for (auto& number : fibonacci)
	for (int& number : fibonacci) // for-each���� ���� �ٲٷ��� ���������� ����ؾ��Ѵ�.
	{
		number = 10;
		cout << number << " ";
	}
	cout << endl;

	// ������ �����Ҵ��� ����ϴ� ��쿡�� for-each�� ����� �� ���� �ȴ�.
	// �̷� ��� for-each���� �� ���� vector�� ����ϸ� �ȴ�.
	//vector<int> fibonacci = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	//�ִ밪 ����
	int max_number = numeric_limits<int>::lowest();

	for (const auto& n : fibonacci)
		max_number = std::max(max_number, n);

	cout << max_number << endl;

	return 0;
}