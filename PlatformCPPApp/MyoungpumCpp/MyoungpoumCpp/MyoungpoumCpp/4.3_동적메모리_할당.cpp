#include <iostream>
using namespace std;

int main()
{
	/*
	// ����4.5
	int* p;

	p = new int;
	if (!p)
	{
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";

		return 0;
	}

	*p = 5;
	int n = *p;
	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;

	delete p;
	*/

	/*
	// ����4.6	
	cout << "�Է��� ������ ������?";
	int n;
	cin >> n;

	if (n <= 0) return 0;
	int* p = new int[n];
	if (!p)
	{
		cout << "�޸𸮸� �Ҵ� �� �� �����ϴ�.";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "��° ����: ";
		cin >> p[i];
	}

	int sum = 0;
	for (int i = 0; i < n;i++)
	{
		sum += p[i];

	}

	cout << "��� = " << sum / n << endl;

	delete[] p;
	*/
	return 1;
}