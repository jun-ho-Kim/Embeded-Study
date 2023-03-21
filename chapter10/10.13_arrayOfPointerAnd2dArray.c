#include <stdio.h>

int main()
{
	/* Two of 1D arrays */
	//int arr0[3] = { 1,2,3 };
	//int arr1[3] = { 4,5,6 };

	//int* parr[2] = { arr0, arr1 }; // an array of pointers

	//for (int j = 0; j < 2; j++)
	//{
	//	for (int i = 0; i < 3; ++i)
	//		printf("%d(==%d, %d) ", parr[j][i], *(parr[j] + i), *(*(parr+j)+i)); //(*(parr + j))[i]
	//	/*
	//		1(== 1, 1) 2(== 2, 2) 3(== 3, 3)
	//		4(== 4, 4) 5(== 5, 5) 6(== 6, 6)
	//	*/
	//	printf("\n");
	//}
	//printf("\n");

	/* 2D arrays are arrays of 1D arrays */

	//int arr[2][3] = { {1,2,3}, {4,5,6} };

	//int* parr0 = arr[0];
	//int* parr1 = arr[1];

	//for (int i = 0; i < 3; ++i)
	//	printf("%d ", parr0[i]); // 1 2 3
	//printf("\n");

	//for (int i = 0; i < 3; ++i)
	//	printf("%d ", parr1[i]); // 4 5 6
	//printf("\n");

	/* arrays of pointers works like a 2D array */

	int arr[2][3] = { {1,2,3}, {4,5,6} };

	// int* parr[2] = {arr[0], arr[1]};

	int* parr[2];
	parr[0] = arr[0];
	parr[1] = arr[1];

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
			printf("%d %d %d %d\n", arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i));
	}

	//Notes
	//	- parr[0] and parr[1] do not point valid memory by default
	//	- &parr[0] != &arr[0]
	//	- &parr[0] != parr[0] but &arr[0] == arr[0]

	printf("%p\n", &parr[0]);
	printf("%p\n", parr[0]);
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%p\n", arr[0]);
	printf("%p\n", &arr[0][0]);


	/* Array of string of diverse lengths example */

	char* name[] = { "Aladdin", "Jasmine", "Magic carpet", "Genie" };

	const int n = sizeof(name) / sizeof(char*);

	for (int i = 0; i < n; ++i)
		printf("%s at %u\n", name[i], name[i]);
	/*
		Aladdin at 10058720
		Jasmine at 10058728
		Magic carpet at 10058736
		Genie at 10058976
	*/
	// 해당 배열의 크기인 경우 배열 원소가 8byte 단위가 넘으면 8byte 씩 끊어서 각각 다른 곳에 저장하므로 메모리 주소가 다르게 나올 수 있다.
	printf("\n");

	char aname[][15] = { "Aladdin", "Jasmine", "Magic carpet", "Genie", "Jafar"};

	const int an = sizeof(aname) / sizeof(char[15]);

	for(int i = 0; i <an; ++i)
		printf("%s at %u\n", aname[i], (unsigned)& aname[i]);
		/*
			Aladdin at 19921860
			Jasmine at 19921875
			Magic carpet at 19921890
			Genie at 19921905
			Jafar at 19921920
		*/
	// 배열 원소의 크기를 15byte로 지정해준 경우 배열 원소 크기가 15byte 넘어가면 에러 발생
	printf("\n");

	return 0;
}