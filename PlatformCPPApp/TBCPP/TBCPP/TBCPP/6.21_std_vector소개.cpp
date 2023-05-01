// �����迭�� ��ü�� �� �ִ� std::array�� �����.
// �����迭�� ��ü�� �� �ִ� std::vector�� �������.

// std::vector�� std::array���� ����ϱ� ���� �δ��� �پ���.

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

	// vector�� ������ �޸𸮸� �˾Ƽ� �����ش�. delete�� ��������� �ʾƵ���.
	// �޸𸮰� leak���� �ʴ´�.
	// �ڽ��� ���̸� ����ؼ� �Լ��� �Ķ���ͷ� ���� ��� ���� ǥ�� �����־�ȴ�.
	// �޸� ������ �����ϰ� ����� �� �ְ� ���� �޸� �Ҵ��� ����� Ȱ���� �� �ִ�.
	

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