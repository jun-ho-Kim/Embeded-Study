//c++ image processing 
//morpology :: erosion, dilation raw code

//c++ .. image processing ... function(params)... algorithms
//opencv .. github..opencv...cvv

//histogram...data/imgdata...
//cvt color
//edge
//feature...area, length, momentum
//enhancement color ... histogram eq...CLAHE
//segment ... threshold ... 기준값...0 or 1(255)
//
//opencv findcontour
// Point {int x, y}
//vector<vector<Point>> contours ... [1]contour :: (x1,y1)~(xn,yn)
// [1]contour   :: (x1,y1)~(xn,yn)
// [...]contour :: (x1,y1)~(xk,yk)
// [m]contour   :: (x1,y1)~(xr,yr)
//Point**
//computer vision + image processing

//ml ... basic 파이썬으로 배우는 머신러닝의 교과서
//....   tensor/keras...


#pragma once
#include "../Common/Common.h"

//침식 - erosion
//침식 후 팽창 - erosion->dilation -> opening
// 
//팽창 - dilation
//팽창 후 침식 - dilation->erosion -> closing
// 
//윤곽선 - edge - origin -> diff erosion -> edge

//void erosion(vector<uchar> vData, int stride);
//morpology : input - 2D image matrix
//			 (input) - struct element/kernel/mask/convolusion/filter
//            output - 2D image matrix
void erosion(int* pData, int data_w, int data_h, int* pDataDst)
{
	//pData - 이진화 된 이미지 .... 0 or 1(255)

	//struct element
	// cross     dot..rect  3x3
	// 0 1 0    1 1 1
	// 1 1 1    1 1 1 
	// 0 1 0    1 1 1
	const int se_size = 3;
	const int se_half_size = se_size / 2;///1.5->1
	int SE[se_size][se_size] = {
		{1,1,1},
		{1,1,1},
		{1,1,1} };
	//image whole searching...for for
	for (int row = se_half_size; row < data_h - se_half_size; row++) {//y
		for (int col = se_half_size; col < data_w - se_half_size; col++) {//x

			//struct elem ... 모든 픽셀이 1인지지 확인
			bool allOne = true;
			//struct element proceesing
			for (int j = -se_half_size; j <= se_half_size; j++) {
				for (int i = -se_half_size; i <= se_half_size; i++) {
					//pData
					//SE
					int index = (row+j)* data_w + (col+i);
					bool cond = (pData[index] == 0 && SE[j + se_half_size][i + se_half_size] == 1);
					if (cond == true)
					{
						allOne = false;
						break;
					}
				}
				if (!allOne) break;
			}
			if (allOne)
				pDataDst[row * data_w + col] = 1;//255
		}
	}
}
void dilation(int* pData, int data_w, int data_h, int* pDataDst)
{
	//pData - 이진화 된 이미지 .... 0 or 1(255)

	//struct element
	// cross     dot..rect  3x3
	// 0 1 0    1 1 1
	// 1 1 1    1 1 1 
	// 0 1 0    1 1 1
	const int se_size = 3;
	const int se_half_size = se_size / 2;///1.5->1
	int SE[se_size][se_size] = {
		{1,1,1},
		{1,1,1},
		{1,1,1} };
	//image whole searching...for for
	for (int row = se_half_size; row < data_h - se_half_size; row++) {//y
		for (int col = se_half_size; col < data_w - se_half_size; col++) {//x
			//struct element proceesing
			for (int j = -se_half_size; j <= se_half_size; j++) {
				for (int i = -se_half_size; i <= se_half_size; i++) {
					//if (SE[j + 1][i + 1] == 1) {
					//	pDataDst[row * data_w + col] = 1;
					//}
					int index = (row) * data_w + (col);
					bool cond = (pData[index] == 0 && SE[j + se_half_size][i + se_half_size] == 1);
					if (cond == true)
					{
						pDataDst[(row+j) * data_w + (col+i)] = 1;
					}
				}
			}
		}
	}
}
//pointer? not -> copy ... out:100MB  in:100MB
//           std::move ... out:  0MB  in:100MB
//pointer? yes -> access data area
//pointer access all (r/w)

void main()
{
	const int data_w = 5;
	const int data_h = 5;
	int Datas[data_w* data_h] = {
		1,1,0,1,1,
		1,1,0,1,1, 
		0,0,0,0,0, 
		1,1,0,1,1, 
		1,1,0,1,1
	};
	//
	//rgb->gray->threshold [0:255]
	//
	for (size_t row = 0; row < data_h; row++)
	{
		for (size_t col = 0; col < data_w; col++)
		{
			std::cout << Datas[row * data_w + col] << "\t";
		}
		std::cout << std::endl;
	}
	int DataDst[data_w * data_h] = {
		1,1,0,1,1,
		1,1,0,1,1,
		0,0,0,0,0,
		1,1,0,1,1,
		1,1,0,1,1
	};

	erosion(Datas, data_w, data_h, DataDst);

	std::cout << "=======================================================" << std::endl;
	for (size_t row = 0; row < data_h; row++)
	{
		for (size_t col = 0; col < data_w; col++)
		{
			std::cout << DataDst[row * data_w + col] << "\t";
		}
		std::cout << std::endl;
	}

	dilation(DataDst, data_w, data_h, Datas);


	std::cout << "=======================================================" << std::endl;
	for (size_t row = 0; row < data_h; row++)
	{
		for (size_t col = 0; col < data_w; col++)
		{
			std::cout << Datas[row * data_w + col] << "\t";
		}
		std::cout << std::endl;
	}



	//cv lib
	//cv::erode();
	//cv::dilate();
	string fileName = "jetson.bmp";
	Mat gray_img = cv::imread(fileName, cv::ImreadModes::IMREAD_GRAYSCALE);
	Mat bin_img;
	cv::threshold(gray_img, bin_img, 128, 255, ThresholdTypes::THRESH_BINARY);
	Mat erod_img, dil_img;
	Mat se = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
	//cv::erode(bin_img, erod_img,se);
	//cv::dilate(erod_img, dil_img, se);

	cv::dilate(bin_img, dil_img, se);
	cv::erode(dil_img, erod_img, se);
	int a = 0;
}