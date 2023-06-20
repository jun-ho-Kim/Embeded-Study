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

// 구조요소를 구조요소 크기 / 2 한 값을 부터 하나 씩 조회하여 구조요소의 중심을 기준으로 구조요소의 값이 1과 겹치는 부분이 없으면 구조요소의 중심 값은 255로 바꾼다.
void erosion(uchar* pData, int data_w, int data_h, uchar* pDataDst)
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
					// 검 && 1
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
				pDataDst[row * data_w + col] = 255;//255
		}
	}
}

// 구조요소의 중심을 고정점으으로 사용하여 겹치는 부분이 있으면 구조요소가 1인 부분을 포함된 0 값으로 변경
void dilation(uchar* pData, int data_w, int data_h, uchar* pDataDst)
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
		{1,1,1} 
	};
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
					if (cond == false)
					{
						pDataDst[(row+j) * data_w + (col+i)] = 255;
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
	//string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	//string fileName = "jetson.bmp";
	string fileName = "./shapes.jpg";
	Mat gray_img = cv::imread(fileName, cv::ImreadModes::IMREAD_GRAYSCALE);
	size_t width = gray_img.cols;
	size_t height = gray_img.rows;

	Mat erod_img = Mat::zeros(height, width, CV_8UC1);
	Mat dil_img = Mat::zeros(height, width, CV_8UC1);
	Mat se = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));


	Mat bin_img = Mat::zeros(height, width, CV_8UC1);
	Mat edge = Mat::zeros(height, width, CV_8UC1);
	cv::threshold(gray_img, bin_img, 128, 255, ThresholdTypes::THRESH_BINARY);
	erosion(bin_img.data, width, height, erod_img.data);
	dilation(bin_img.data, width, height, dil_img.data);

	//std::cout << "=======================================================" << std::endl;
	//for (size_t row = 0; row < data_h; row++)
	//{
	//	for (size_t col = 0; col < data_w; col++)
	//	{
	//		std::cout << DataDst[row * data_w + col] << "\t";
	//	}
	//	std::cout << std::endl;
	//}

	//dilation(DataDst, data_w, data_h, Datas);

	/*
	std::cout << "=======================================================" << std::endl;
	for (size_t row = 0; row < data_h; row++)
	{
		for (size_t col = 0; col < data_w; col++)
		{
			std::cout << Datas[row * data_w + col] << "\t";
		}
		std::cout << std::endl;
	}
	*/

	/*
	//cv lib
	//cv::erode();
	//cv::dilate();
	string fileName = "jetson.bmp";
	Mat gray_img = cv::imread(fileName, cv::ImreadModes::IMREAD_GRAYSCALE);
	Mat bin_img;
	cv::threshold(gray_img, bin_img, 128, 255, ThresholdTypes::THRESH_BINARY);
	Mat erod_img, dil_img, edge;
	Mat se = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
	//cv::erode(bin_img, erod_img,se);
	//cv::dilate(erod_img, dil_img, se);

	cv::dilate(bin_img, dil_img, se);
	cv::erode(dil_img, erod_img, se);

	edge = dil_img - erod_img;
	//cv::erode(dil_img, edge, se);
	*/

	int a = 0;
}