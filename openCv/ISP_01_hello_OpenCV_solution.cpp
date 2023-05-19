#pragma once
#include "../Common/Common.h"

int* normalization(const int* pHisto, size_t data_len, int& new_min, int& new_max)
{
	const int sz = 256;
	int Histo_norm[sz] = { 0, };
	int histo_min(pHisto[0]), histo_max(pHisto[0]);
	for (size_t i = 0; i < data_len; i++)
	{
		if (histo_min > pHisto[i]) histo_min = pHisto[i];
		if (histo_max < pHisto[i]) histo_max = pHisto[i];
	}

	//동적-Pointer                     start, start+length
	auto minmax = std::minmax_element(pHisto, pHisto + data_len);
	//정적
	//auto minmax = std::minmax_element(std::begin(Histo_norm), std::end(Histo_norm));
	histo_min = *minmax.first;
	histo_max = *minmax.second;

	int histo[sz] = { 0, };
	memcpy( histo, const_cast<int*>(pHisto), sizeof(int) * data_len);
	std::sort(histo, histo + sz);//오름차순
	histo_min = histo[0];
	histo_max = histo[sz-1];

	for (size_t i = 0; i < data_len; i++)
	{
		int x = pHisto[i];
		Histo_norm[i] = new_min + (1.0*(x - histo_min) / (histo_max - histo_min))* (new_max - new_min);
	}
	return Histo_norm;
}
void histoDisplay(uchar* pData, size_t& width, size_t& height)
{
	cout << (int)pData[0] << endl;
	//typedef unsigned char uchar; 256
	int size = sizeof(uchar);//pData[0]...0~255 sizeof(uchar)..BYTE
	const int histo_sz = 256;
	int histo[histo_sz] = { 0, };//?? size - 10, 100??
	//for (size_t row = 0; row < height; row++)//height ↓	
	//{
	//	for (size_t col = 0; col < width; col++) //---→
	//	{
	//		int index = row * width + col;
	//		//pData[index]...value
	//		histo[pData[index]]++;
	//	}
	//}
	for (size_t i = 0; i < width * height; i++)
	{
		histo[pData[i]]++;
	}

	int histo_norm[histo_sz] = { 0, };
	int newMin = 0;
	int newMax = 130;
	int* pNorm = normalization(histo, histo_sz, newMin, newMax);
	memcpy(histo_norm, pNorm, sizeof(int) * histo_sz);

	for (size_t i = 0; i < histo_sz; i++)
	{
		int count = histo_norm[i];
		string tt = string(count, '=');
		//string tt = " ";
		//for (size_t d = 0; d < count; d++)
		//{
		//	tt += "=";
		//}
		cout << i << "\t" << "|" << tt << " :: " << histo[i] << endl;
	}

}

























int main()
{
	cout << "Hello OpenCV World!!" << endl;
	string fileName = "jetson.bmp";
	Mat gray_img = cv::imread(fileName, cv::ImreadModes::IMREAD_GRAYSCALE);

	//히스토그램을 구하는 함수를 만들고 함수에서 그래프를 출력하시오
	uchar* pData = gray_img.data;
	size_t width = gray_img.cols;
	size_t height = gray_img.rows;

	histoDisplay(pData, width, height);









	//이미지 출력 윈도우 설정
	const char* window_name = "OpenCV Window";
	cv::namedWindow(window_name, cv::WindowFlags::WINDOW_NORMAL);
	//cv::resizeWindow(window_name, 640, 480);//윈도우 크기 변경

	//이미지 출력
	cv::imshow(window_name, gray_img);
	cv::waitKey();

	//이미지 출력 윈도우 해제
	cv::destroyWindow(window_name);
	return 1;
}