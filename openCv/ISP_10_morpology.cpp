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
					bool cond = (pData[index] == 0 && SE[j + se_half_size][i + se_half_size] == 1);
					if (cond == true)
					{
						pDataDst[(row + j) * data_w + (col + i)] = 1;//1
						//allOne = false;
						//break;
					}
				}
				//if (!allOne) break;
			}

		}
	}
}
/*
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
		{1,1,1} };
	//image whole searching...for for
	for (int row = se_half_size; row < data_h - se_half_size; row++) {//y
		for (int col = se_half_size; col < data_w - se_half_size; col++) {//x

			//struct elem ... 모든 픽셀이 1인지지 확인
			bool allOne = true;
			//struct element proceesing
			for (int j = -se_half_size; j <= se_half_size; j++) {
				for (int i = -se_half_size; i <= se_half_size; i++) {
					if (SE[j+1][i+1] == 1)
					{
						pDataDst[row * data_w + col] = 1;
					}
				}
			}
		}
	}
}
*/

//pointer? not -> copy ... out:100MB  in:100MB
//           std::move ... out:  0MB  in:100MB
//pointer? yes -> access data area
//pointer access all (r/w)

void main()
{
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "shapes.jpg";
	Mat color_img = cv::imread(fileName, cv::ImreadModes::IMREAD_GRAYSCALE);
	size_t width = color_img.cols;
	size_t height = color_img.rows;

	Mat gray_img = Mat::zeros(height, width, CV_8UC1);
	Mat bin_img = Mat::zeros(height, width, CV_8UC1);
	Mat erod_img, dil_img;
	Mat se = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::erode(bin_img, erod_img, se);
	cv::erode(bin_img, dil_img, se);

	uchar* Datas = color_img.data;



	//gray_img.data = color_img.data;
	const int data_w = 5;
	const int data_h = 5;
	//int Datas[data_w * data_h] = {
	//	1,1,0,1,1,
	//	1,1,0,1,0,
	//	0,0,0,0,0,
	//	1,1,0,1,1,
	//	1,1,0,1,1
	//};

	//int Datas[data_w* data_h] = {
	//	0,1,1,1,1,
	//	0,1,1,1,0, 
	//	1,1,1,1,0, 
	//	1,1,1,1,1, 
	//	1,1,1,1,1
	//};
	//
	//rgb->gray->threshold [0:255]
	//
	cv::threshold(color_img, bin_img, 128, 255, ThresholdTypes::THRESH_BINARY);
	//uchar* DataDst = new uchar[width * height]{ 0, };
	erosion(Datas, width, height, gray_img.data);
	for (size_t row = 0; row < height; row++)
	{
		for (size_t col = 0; col < width; col++)
		{
			std::cout << Datas[row * width + col] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	

	//dilation(Datas, data_w, data_h, gray_img.data);


	for (size_t row = 0; row < data_h; row++)
	{
		for (size_t col = 0; col < data_w; col++)
		{
			std::cout << gray_img.data[row * data_w + col] << "\t";
		}
		std::cout << std::endl;
	}
	int a = 0;



}