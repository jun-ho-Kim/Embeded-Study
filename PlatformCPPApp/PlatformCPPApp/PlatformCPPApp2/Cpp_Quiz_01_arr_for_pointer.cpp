#include <iostream>
#include <fstream>
#include <string>

int main()
{
	if (0)
	{
		const int w = 5;
		const int h = 5;
		int data[w * h] = {
			1,1,1,1,1,//->열
			2,2,2,2,2,//↓행
			3,3,3,3,3,
			4,4,4,4,4,
			5,5,5,5,5
		};

		int* pData = data;
		int result[w * h] = {
		1,1,1,1,1,//->열
		2,2,2,2,2,//↓행
		3,3,3,3,3,
		4,4,4,4,4,
		5,5,5,5,5
		};
		int* pDataResult = result;

		int sum[h] = { 0, };
		float avg[h] = { 0.0, };
		//해답
		int a = data[0]; // 1...index...start 0
		int d = data[w * h - 1]; // 1...index...finish 24 (w*h-1)
		//2d...1d
		for (size_t row = 0; row < h; row++)
		{
			int sumValue = 0;
			float avgValue = 0.0;
			for (size_t col = 0; col < w; col++)
			{
				int index = row * w + col; //offset = 0;
				//data[index]
				int value = *(pData + index) + 10;

				//std::cout << data[index] << std::endl;
				//if (row == 0 && col == 0)
				//{
				//	result[index] = data[index] + 10;
				//}
				//else if (row == 0 && col == 4)
				//{
				//	result[index] = data[index] + 10;
				//}
				//else if (row == 4 && col == 0)
				//{
				//	result[index] = data[index] + 10;
				//}
				//else if (row == 4 && col == 4)
				//{
				//	result[index] = data[index] + 10;
				//}
				if (row % 4 == 0 && col % 4 == 0)
					result[index] = data[index] + 10;
				//result[index] = *(pData + index) = 10;
				else
					result[index] = data[index] + 100;
				// *(pDataResult+index)= *(pData + index) = 100;
				std::cout << data[index] << "     " << result[index] << std::endl;
				sum[row] = sum[row] + result[index];
				sumValue = sumValue + result[index];
			}
			avg[row] = sumValue / w;
			sum[row] = sumValue;

			std::cout << (row + 1) << "행의 총합은 " << sum[row] << "평균은" << avg[row] << std::endl;

			int sumTotal = 0;
			float avgTotal = 0.0;
			for (size_t row = 0; row < h; row++)
			{
				avgTotal += avg[row];
				sumTotal += sum[row];
			}
			avgTotal /= h;

			std::cout << "배열의 총합은 " << sumTotal << "평균은 " << avgTotal << std::endl;

		}


		//내가 푼 답
		int* data_ptr = data;
		*data_ptr += 10;
		*(data_ptr + 4) += 10;
		*(data_ptr + 20) += 10;
		*(data_ptr + 24) += 10;
		for (int dep = 0; dep < w * h; dep++)
		{
			if (dep != 0 && dep != 4 && dep != 20 && dep != 24)
			{
				*(data_ptr + dep) += 100;
			}
		}
		//for (int dep = 0; dep < w * h; dep++)
		//{
		//	std::cout << dep << "is" << *(data_ptr + dep) << std::endl;
		//}

		int row, col;
		for (row = 0; row < w; row++)
		{
			int sum = 0;
			float avg = 0;
			for (col = 0; col < h; col++)
			{
				sum += data[(row * h) + col];
				avg = sum / h;
			}
			std::cout << row << "행의 합은 " << sum << "," << "평균은" << avg << " 입니다." << std::endl;
			//std::cout << row << "행의 \n" << std::endl;
		}


		//Q >> 
		// 배열 원소 행,열(0,0)의 값에 +10을 합니다.
		// 배열 원소 행,열(4,0)의 값에 +10을 합니다.
		// 배열 원소 행,열(0,4)의 값에 +10을 합니다.
		// 배열 원소 행,열(4,4)의 값에 +10을 합니다.
		// 위 해당하는 행,열을 제외한 나머지는 +100을 합니다.
		// 갱시된 데이터의 각 행의 합과 총합을 구하시오

		/*
		11, 101, 101, 101, 11,
		102, 102, 102, 102, 102
		103, 103, 103, 103, 103,
		104, 104, 104, 104, 104,
		15, 105, 105, 105, 15

		1행의 총합은 ?? 입니다.
		2행의 총합은 ?? 입니다.
		3행의 총합은 ?? 입니다.
		4행의 총합은 ?? 입니다.
		*/
	}
	{
		const int w = 5;
		const int h = 5;
		int data[w * h] = {
			1,1,1,1,1,//->열
			2,2,2,2,2,//↓행
			3,3,3,3,3,
			4,4,4,4,4,
			5,5,5,5,5
		};

		int* pData = data;
		int result[w * h] = {
		1,1,1,1,1,//->열
		2,2,2,2,2,//↓행
		3,3,3,3,3,
		4,4,4,4,4,
		5,5,5,5,5
		};
		int* pDataResult = result;

		int sum[h] = { 0, };
		float avg[h] = { 0.0, };
		//해답
		int a = data[0]; // 1...index...start 0
		int d = data[w * h - 1]; // 1...index...finish 24 (w*h-1)
		//2d...1d
		for (size_t row = 0; row < h; row++)
		{
			int sumValue = 0;
			float avgValue = 0.0;
			for (size_t col = 0; col < w; col++)
			{
				int index = row * w + col; //offset = 0;
				//data[index]
				int value = *(pData + index) + 10;

				//std::cout << data[index] << std::endl;
				//if (row == 0 && col == 0)
				//{
				//	result[index] = data[index] + 10;
				//}
				//else if (row == 0 && col == 4)
				//{
				//	result[index] = data[index] + 10;
				//}
				//else if (row == 4 && col == 0)
				//{
				//	result[index] = data[index] + 10;
				//}
				//else if (row == 4 && col == 4)
				//{
				//	result[index] = data[index] + 10;
				//}
				if (row % 4 == 0 && col % 4 == 0)
					result[index] = data[index] + 10;
				//result[index] = *(pData + index) = 10;
				else
					result[index] = data[index] + 100;
				// *(pDataResult+index)= *(pData + index) = 100;
				std::cout << data[index] << "     " << result[index] << std::endl;
				sum[row] = sum[row] + result[index];
				sumValue = sumValue + result[index];
			}
			avg[row] = sumValue / w;
			sum[row] = sumValue;

			std::cout << (row + 1) << "행의 총합은 " << sum[row] << "평균은" << avg[row] << std::endl;

			int sumTotal = 0;
			float avgTotal = 0.0;
			for (size_t row = 0; row < h; row++)
			{
				avgTotal += avg[row];
				sumTotal += sum[row];
			}
			avgTotal /= h;

			std::cout << "배열의 총합은 " << sumTotal << "평균은 " << avgTotal << std::endl;

		}


		//내가 푼 답
		int* data_ptr = data;
		*data_ptr += 10;
		*(data_ptr + 4) += 10;
		*(data_ptr + 20) += 10;
		*(data_ptr + 24) += 10;
		for (int dep = 0; dep < w * h; dep++)
		{
			if (dep != 0 && dep != 4 && dep != 20 && dep != 24)
			{
				*(data_ptr + dep) += 100;
			}
		}
		//for (int dep = 0; dep < w * h; dep++)
		//{
		//	std::cout << dep << "is" << *(data_ptr + dep) << std::endl;
		//}

		int row, col;
		for (row = 0; row < w; row++)
		{
			int sum = 0;
			float avg = 0;
			for (col = 0; col < h; col++)
			{
				sum += data[(row * h) + col];
				avg = sum / h;
			}
			std::cout << row << "행의 합은 " << sum << "," << "평균은" << avg << " 입니다." << std::endl;
			//std::cout << row << "행의 \n" << std::endl;
		}


		//Q >> 
		// 배열 원소 행,열(0,0)의 값에 +10을 합니다.
		// 배열 원소 행,열(4,0)의 값에 +10을 합니다.
		// 배열 원소 행,열(0,4)의 값에 +10을 합니다.
		// 배열 원소 행,열(4,4)의 값에 +10을 합니다.
		// 위 해당하는 행,열을 제외한 나머지는 +100을 합니다.
		// 갱시된 데이터의 각 행의 합과 총합을 구하시오

		/*
		11, 101, 101, 101, 11,
		102, 102, 102, 102, 102
		103, 103, 103, 103, 103,
		104, 104, 104, 104, 104,
		15, 105, 105, 105, 15

		1행의 총합은 ?? 입니다.
		2행의 총합은 ?? 입니다.
		3행의 총합은 ?? 입니다.
		4행의 총합은 ?? 입니다.
		*/
	}

	const int w = 5;
	const int h = 5;
	int face[w * h] = {
		8,8,8,8,8,//->열
		8,2,9,2,8,//↓행
		3,1,5,1,3,
		1,3,5,3,1,
		1,1,3,1,1
	};
	const int maxValue = 10;
	int histo[maxValue] = { 0, };
	for (size_t i = 0; i < w * h; i++)
	{
		unsigned char f = face[i];//data
		histo[f]++; //python ++ +=1
	}

	std::string str = "======================";
	
	for (size_t i = 0; i < maxValue; i++)
	{
		std::cout << i << " : ";
		std::cout << str.substr(0, histo[i]);
		//for (size_t h = 0; h < histo[i]; h++)
		//{
		//	std::cout << "=";
		//}
		std::cout << histo[i] << std::endl;
	}

	//내가 쓴 답

	int cntArr[10] = { 0, };
	int* face_ptr = face;

	for (int num = 0; num < w * h; num++)
	{
		int inputNum = *(face_ptr + num);
		cntArr[inputNum] += 1;
	}

	std::cout << "====== input data =======\n" << "\t8, 8, 8, 8, 8\n\t8, 2, 9, 2, 8,\n\t3, 1, 5, 1, 3,\n\t1, 3, 5, 3, 1,\n\t1, 1, 3, 1, 1\n";

	for (int cnt = 0; cnt < 10; cnt++)
	{
		std::cout << cnt << ":";
		if (cntArr[cnt] > 0) {
			for (int eq = 0; eq < cntArr[cnt]; eq++)
				std::cout << "=";
			std::cout << " " << cntArr[cnt] << std::endl;
		}
		else 
			std::cout << std::endl;

	}

	//다음 데이터 face 배열의 원소에 해당하는 각 데이터의 빈도수를 구하고 아래와 같이 출력하시오
	//====== input data =======
	//		8, 8, 8, 8, 8,
	//		8, 2, 9, 2, 8,
	//		3, 1, 5, 1, 3,
	//		1, 3, 5, 3, 1,
	//		1, 1, 3, 1, 1
	//0:
	//1: ======== 8
	//2: == 2
	//3: ===== 5
	//4:
	//5: == 2
	//6:
	//7:
	//8: ====== 6
	//9: = 1

	}
