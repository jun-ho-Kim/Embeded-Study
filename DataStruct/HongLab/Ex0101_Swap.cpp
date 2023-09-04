#include <iostream>

using namespace std;

/*
int MySwapValue(int i, int j)
{
	// TODO:

	return ? ;
}

void MySwapPtr(int* i, int* j)
{
	// TODO:
}

void MySwapRef(int& i, int& j)
{
	// TODO:
}
*/

bool CheckSorted(int a, int b)
{
	return false;
}

int main()
{
	// Swap
	{
		int a = 3;
		int b = 2;

		cout << a << " " << b << endl;

		// TODO:

		int tmp = a;

		a = b;

		b = tmp;

		cout << a << " " << b << endl;

		int z = 3;
	}


	// 정렬(sorting)
	{
		int arr[] = { 9, 3};

		cout << arr[0] << " " << arr[1] << endl;

		const int arr_len = sizeof(arr) / sizeof(int);

		// TODO:
		int i, j = 0;
		printf("arr size of is %d: \n", sizeof(arr));
		printf("arr_len is %d: \n", arr_len);


		/*
		int sort_arr[arr_len] = { 0, };
		for (i = 0; i < arr_len; i++)
		{
			int idx = 0;
			for (j = i + 1; j < arr_len; j++)
			{
				if (arr[i] > arr[j])
					++idx;
			}
			sort_arr[idx] = arr[i];
		}
		cout << sort_arr[0] << " " << sort_arr[1] << endl;
		*/

		for (i = 0; i < arr_len-1; i++)
		{
			int idx = 0;
			int tmp_i = i;
			for (j = i + 1; j < arr_len; j++)
			{
				if (arr[i] > arr[j])
				{
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
					i = j;

				}
			}
			i = tmp_i;
			
		}

		//printf("arr is %s ", arr);
		cout << arr[0] << " " << arr[1] << endl;

		int z = 3;
	}

	// 값과 상관 없이 항상 작은 값이 먼저 출력되게 하려면?
	// 두 값이 같을 때는 순서가 상관 없음 -> 큰 값이 먼저 출력되지 않게 하려면?
	{
		int arr[2];

		// TODO:
	}

	return 0;
}
