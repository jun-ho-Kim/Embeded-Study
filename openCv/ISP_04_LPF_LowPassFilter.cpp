#include "../Common/Common.h"
#include "ISP.h"

void main()
{
	ISP _isp;

	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "lena.jpg";
	Mat color_img = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	uchar* pDataColor = color_img.data;
	size_t width = color_img.cols;
	size_t height = color_img.rows;

	//#1. Convert Color To Gray
	Mat gray_img = Mat::zeros(height, width, CV_8UC1);
	uchar* pDataGray = gray_img.data;
	_isp.Convert_BGR2Gray(pDataColor, width, height, pDataGray);


	//#2. new Alloc Buffer LPF_Image
	Mat lpf_img = Mat::zeros(height, width, CV_8UC1);
	uchar* pDataLPF = lpf_img.data;
	_isp.Get_LPF(pDataGray, width, height, pDataLPF);

	Mat hpf_img = Mat::zeros(height, width, CV_8UC1);
	uchar* pDataHPF = hpf_img.data;
	_isp.Get_HPF(pDataGray, width, height, pDataHPF);


	Mat lap_img = Mat::zeros(height, width, CV_8UC1);
	uchar* pDataLap = lap_img.data;
	_isp.Get_HPF2(pDataGray, width, height, pDataLap);


	lap_img *= 2;





	//상황.. Low Pass Filter 이미지를 전송하다 아래 위치에서 이미지 손실이 발생했습니다.
	//아래 위치에서 손실된 부분을 찾아서 이미지를 개선하세요
	int row, col;
	row = 10; col = 10;
	lpf_img.data[(row)*width + (col)] = 0;
	row = 100; col = 100;
	lpf_img.data[(row)*width + (col)] = 0;
	//선형 보간을 이용하여 (10,10), (100,100) 위치의 값을 채워넣으세요
	
	int x0, x1, g0, g1, x, g;
	{
		row = 10; col = 10;
		x0 = col - 1;
		x1 = col + 1;
		g0 = lpf_img.data[(row)*width + (x0)];
		g1 = lpf_img.data[(row)*width + (x1)];
		x = col;
		g = g0 + (g1 - g0) * (x - x0) / (x1 - x0);
		lpf_img.data[(row)*width + (col)] = g;
	}
	
	{
		row = 100; col = 100;
		x0 = col - 1;
		x1 = col + 1;
		g0 = lpf_img.data[(row)*width + (x0)];
		g1 = lpf_img.data[(row)*width + (x1)];
		x = col;
		g = g0 + (g1 - g0) * (x - x0) / (x1 - x0);
		lpf_img.data[(row)*width + (col)] = g;
	}
	

	return;
}