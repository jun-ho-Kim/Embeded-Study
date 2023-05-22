// �Ʒ� ������ Ǯ�����

/*
void Calc(int* pData, int size, int* sum, double* avg)
{}

int arr[10] = {2,9,4,2,3,5,2,3,4,5}
����� ����Ͻÿ�
*/

#include <string>
#include <iostream>

using namespace std;


/*
int* pSum // int Ÿ���� �ּҸ� sum�̶�� ������ ����(int Ÿ���� �ּ�)
int *sum // int Ÿ���� *sum�̶�� ������ ����
// c
func(int* sum)

func(int *sum)
*/

/*
swap1(&a, &b);
void swap1(int* lhs, int* rhs)// window�� �ٷΰ��� + extern storage
{
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}
swap2(a, b);
void swap2(int lhs, int rhs) // copy
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}
*/

struct _stResult
{
	int sum = 0;
	double avg = 0.0;
};

/*
void Calc(int* pData, int size, int* sum, double* avg)
{
	int _sum = 0;
	double _avg = 0.0;
	for (size_t i = 0; i < size; i++)
	{
		_sum = _sum + pData[i];
	}
	_avg = _sum / size;

	*sum = _sum;
	*avg = _avg;

	if (pData != nullptr && sum != nullptr && avg != nullptr)
	{
		for (size_t i = 0; i < size; i++)
		{
			*sum = _sum + pData[i];
		}
		*avg = *sum / size;
	}
}
*/

void Calc(int* pData, int size, _stResult* pResult)
{

	if (pData != nullptr && pResult != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			//pResult->sum += *(pData + i);
			pResult->sum += pData[i]; // ���������� ������ �������� üũ�� ���ش�.
		}
		pResult->avg = static_cast<double>(pResult->sum) / static_cast<double>(size);
		cout << "Calc pResult addr: " << pResult << endl; // 000000F850FBF758
		cout << "Calc pResult.sum addr: " << &pResult->sum << endl; // 000000F850FBF758
		cout << "Calc pResult.avg addr: " << &pResult->avg << endl; // 000000F850FBF760
		cout << "pResult->avg : " << pResult->avg << endl;
		cout << "pResult->sum : " << pResult->sum << endl;
	}
}

int main()
{

	int arr[10] = { 1,2,3,4,1,2,3,12,2,10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	_stResult stResult;
	cout << "stResult addr: " << &stResult << endl; // 000000F850FBF758
	cout << "stResult avg value addr: " << &stResult.avg << endl; // 000000F850FBF760
	cout << "stResult sum value addr: " << &stResult.sum << endl; // 000000F850FBF758
	Calc(arr, size, &stResult);

	int z = 3;

	/*
	int arr1 = { 100 };
	cout << arr1 << endl;
	arr1 = 200; // ���� ������ ������ ����
	int* p = &arr1;
	*p = 100;
	*p = 200;
	int arr[1] = { 100 };
	*/

	/*
	int arr[10] = { 1,2,3,4,1,2,3,12,2,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	double avg = 0.0;

	int* sum = nullptr; // �����迭 �Ҵ翡 ���
	double* avg = nullptr; // �����迭 �Ҵ翡 ���

	Calc(arr, size, &sum, &avg);
	Calc(&arr[0], size, &sum, &avg); // arr = &arr[0]

	*/

	return 1;
}



/*
using namespace std;

void Calc(int* pData, int size, int*sum, double* avg)
{
	cout << "sum is 0 " << *sum << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "i is " << i << "is " << pData + i << " " << *(pData + i) << endl;
		*sum += *(pData + i);
	}
	*avg = static_cast<double>(*sum) / static_cast<double>(size);
}

int main()
{
	int arr[10] = { 2,9,4,2,3,5,2,3,4,5 };
	int sum = 0;
	double avg = 0;
	Calc(arr, 10, &sum, &avg);

	cout << "sum is " << sum << endl;
	cout << "avg is " << avg << endl;

	int z = 4;
}
*/