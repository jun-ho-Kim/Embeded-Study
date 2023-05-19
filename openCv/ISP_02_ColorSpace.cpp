#pragma once

#include "../Common/Common.h"

void Split_Color2RGB(uchar* pDataBGR, size_t& w, size_t& h, uchar* pR, uchar* pG, uchar* pB)
{
	/*
	Main에 구현된 코드를 함수화 하시오
	*/

	for (size_t row = 0; row < h; row++)
	{
		for (size_t col = 0; col < w; col++)
		{
			int index = row * w + col;
			index *= 3;
			int b = pDataBGR[index + 0];
			int g = pDataBGR[index + 1];
			int r = pDataBGR[index + 2];

			int band_index = row * w + col;
			pR[band_index] = r;
			pG[band_index] = g;
			pB[band_index] = b;
		}
	}
}

void Convert_BGR2Gray(uchar* pDataBGR, size_t& w, size_t& h, uchar* pY)
{
	for (size_t row = 0; row < h; row++)
	{
		for (size_t col = 0; col < w; col++)
		{
			int index = row * w + col;
			int mulIndex = index * 3;
			int b = pDataBGR[mulIndex + 0];
			int g = pDataBGR[mulIndex + 1];
			int r = pDataBGR[mulIndex + 2];

			pY[index] = 0.299*r + 0.587*g + 0.114*b;
		}
	}

	 /*
	 Y=0.299R+0.587G+0.114B
	 Color를 Gray로 변환하시오
	 */
}
void Convert_BGR2YCbCr(uchar* pDataBGR, size_t& w, size_t& h, uchar* pY, uchar* pCb, uchar* pCr)
{
	for (size_t row = 0; row < h; row++)
	{
		for (size_t col = 0; col < w; col++)
		{
			int index = row * w + col;
			int mulIndex = index * 3;
			int b = pDataBGR[mulIndex + 0];
			int g = pDataBGR[mulIndex + 1];
			int r = pDataBGR[mulIndex + 2];

			pY[index] = 0.299 * r + 0.587 * g + 0.114 * b;
			pCb[index] = - 0.169 * r - (0.331 * g) + 0.500 * b;
			pCr[index] = 0.500 * r - 0.419 * g - 0.0813 * b;
		}
	}
	
	/*
	Y=0.299R+0.587G+0.114B
	Cb=-0.169R-0.331G+0.500B
	Cr=0.500R-0.419G-0.0813B
	Color를 Gray로 변환하시오
	*/
}



int main()
{
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "baboon.jpg";
	Mat color_img = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);

	uchar* pData = color_img.data;
	size_t width = color_img.cols;
	size_t height = color_img.rows;
		
	Mat img_R = Mat(height, width, CV_8UC1); // CV_8UC1 8bit unchar 1 bit
	Mat img_G = Mat(height, width, CV_8UC1, Scalar(128)); // CV_8UC1 8bit unchar 1 bit
	Mat img_B = Mat(height, width, CV_8UC1); // CV_8UC1 8bit unchar 1 bit

	Mat img_Y = Mat(height, width, CV_8UC1); // CV_8UC1 8bit unchar 1 bit
	Mat img_Cb = Mat(height, width, CV_8UC1); // CV_8UC1 8bit unchar 1 bit
	Mat img_Cr = Mat(height, width, CV_8UC1); // CV_8UC1 8bit unchar 1 bit

	Mat mat1 = Mat::zeros(3, 3, CV_32SC1);
	Mat mat2 = Mat::ones(3, 3, CV_32FC1); // 1`s matrix
	Mat mat3 = Mat::eye(3, 3, CV_32FC1);  // identity matrix

	float data[] = { 1,2,3,4,5,6 };
	Mat mat4(2, 3, CV_32FC1, data);

	uchar* pData_R = img_R.data;
	uchar* pData_G = img_G.data;
	uchar* pData_B = img_B.data;
	uchar* pData_Y = img_Y.data;
	uchar* pData_Cb = img_Cb.data;
	uchar* pData_Cr = img_Cr.data;

	Split_Color2RGB(pData, width, height, pData_R, pData_G, pData_B);
	Convert_BGR2Gray(pData, width, height, pData_Y);
	Convert_BGR2YCbCr(pData, width, height, pData_Y, pData_Cb, pData_Cr);

	int z = 3;

	return 1;
}