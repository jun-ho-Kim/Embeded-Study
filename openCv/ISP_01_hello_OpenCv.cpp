#pragma once

#include "../Common/Common.h"

int* normalization(int* pHisto, size_t data_len, int& new_min, int& new_max)
{
	const int sz = 256;
	int Histo_norm[sz] = { 0, };
	int histo_min(pHisto[0]), histo_max(pHisto[0]);

	for (size_t i = 0; i < data_len; i++)
	{
		if (histo_min > pHisto[i]) histo_min = pHisto[i];
		if (histo_min < pHisto[i]) histo_max = pHisto[i];
	}
	// 동적-Pointer				start, start+length
	auto minmax = std::minmax_element(pHisto, pHisto + data_len);
	
	// 정적
	// auto minmax = std::minmax_element(std::begin(Histo_norm), std::end(Histo_norm));
	histo_min = *minmax.first;
	histo_max = *minmax.second;
	
	int histo[sz] = { 0, };

	memcpy(histo, const_cast<int*>(pHisto) + sz);
	std::sort(histo, histo+sz); // 오름차순

	histo_min = histo[0];
	histo_max = histo[sz-1];

	for (size_t i = 0; i < data_len; i++)
	{
		int x = pHisto[i];
		Histo_norm[i] = 
	}



	/*
	// 내가 짠 코드
	int Histo_norm[256];
	for (int i = 0; i < data_len; i++)
	{
		cout << "i: " << pHisto[i] << endl;
		//Histo_norm[pHisto[i]]++;
	}

	// 함수는 입력과 출력을 주고 모든 기능들은 함수 안에서 해야한다.
	for (int i = 0; i < 256; i++)
	{
		Histo_norm[i] = ((Histo_norm[i] - new_min) * (100 - 0)) / (new_max - new_min);
	}
	*/


	return Histo_norm;
}


// 교수님이 짠 코드
void histoDisplay(uchar* pData, size_t& width, size_t& heigth)
{
	cout << (int)pData[0] << endl;

	int size = sizeof(uchar); //pData[0]...0~255
	const int histSize = 256;
	int histo[256] = {0,};
	int a = 0;
	int b = 50;

	//for (size_t row = 0; row < heigth; row++)
	//{
	//	for (size_t col = 0; col < width; col++)
	//	{
	//		int index = row * width + heigth;

	//		pData[index];

	//		//pData[index]...value
	//		histo[pData[index]]++;
	//	}
	//}
	// 아래와 같이 2차원으로 치환 가능
	//for (size_t i = 0; i < width * heigth; i++)
	//{
	//	histo[pData[i]]++;
	//}

	
	int max = INT_MIN;
	int min = INT_MAX;
	for (size_t i = 0; i < histSize; i++)
	{
		if (histo[i] > max)
			max = histo[i];
		if (histo[i] < min)
			min = histo[i];
	}

	int* normAddr = normalization((int*)pData, width, min, max);
	cout << "normAddr: " << normAddr << endl;
	cout << "max: " << max << endl;
	cout << "min: " << min << endl;
	float sub = max - min;
	cout << "sub: " << sub << endl;
	for (size_t i = 0; i < histSize; i++)
	{
		int count = histo[i];
		cout << "count: " << i << " is " << count << endl;
		int xs = (((count - min) * (b - a)) / sub);
		
		cout << "v: " << i << "is " << xs << endl;

		string tt = "";

		//int result = xs * 100;
		cout << "result: " << xs << endl;
		for (size_t d = 0; d < xs; d++)
		{
			tt += "=";
		}
		cout << i << "\t" << "|" << tt << endl;
	}
	

}


int main()
{
	cout << "Hello OpenCv World!!" << endl;
	string fileName = "jetson.bmp";
	//Mat gray_img = cv::imread(fileName, cv::ImreadModes::IMREAD_ANYCOLOR);
	Mat gray_img = cv::imread(fileName, cv::ImreadModes::IMREAD_GRAYSCALE);
	
	//밝기 분포를 계산하시오 : 히스토그램
	/*
	int arr[5] = {2,3,2,2,3}
	hist[0] |
	hist[1] |
	hist[2] |= = =
	hist[3] |= =
	hist[4] |
	//int* pArr = arr;
	int* pArr = &arr[0]; pointer address = &2
	int a = 10;
	int* pA = &a;
	
	pArr[0] |
	pArr[1] |
	pArr[2] |= = =
	pArr[3] |= =
	pArr[4] |
	*/

	uchar* pData = gray_img.data; // gray_img.data[0]의 주소
	size_t width = gray_img.cols; //widths
	size_t heigth = gray_img.rows;

	histoDisplay(pData, width, heigth);

	// code = histgram을 구하고 출력하시오

	//cout << "pData is " << pData << endl;
	//cout << "width is " << width << endl;
	//cout << "heigth is " << heigth << endl;

	//내가 짠 코드
	//int arr[255] = { 0, };

	//for (int i = 0; i < width*heigth; i++)
	//{
	//	int temp = *(pData + i);
	//	//cout << "temp is " << temp << endl;
	//	arr[temp] += 1;
	//}

	//for (int i = 0; i < 256; i++)
	//{
	//	cout << "[" << i << "]" << "|";
	//	for (int j = 0; j < arr[i]; j++)
	//	{
	//		cout << "=";
	//	}
	//	cout << endl;
	//}
	
	int z = 3;

	/*
	[  0] |
	[  1] |
	[  2] |= = =
	[  3] |= =
	[  4] |
	[255] |
	*/
	
	// 이미지 출력 윈도우 설정
	const char* window_name = "OpenCV Window";
	cv::namedWindow(window_name, cv::WindowFlags::WINDOW_NORMAL);
	cv::resizeWindow(window_name, 640, 480);

	//이미지 출력
	cv::imshow(window_name, gray_img);
	cv::waitKey();

	//이미지 출력 윈도우 해제
	cv::destroyWindow(window_name);

	return 1;

}