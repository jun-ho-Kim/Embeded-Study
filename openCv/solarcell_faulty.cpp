#include "../Common/Common.h"
#include "ISP.h"
#include <io.h>
#include <filesystem>
namespace fs = std::filesystem;

string fileDir = "C:/Users/AIOT2/Desktop/solar_cell/";
//string fileName = fileDir + "2018121014312634_Lens_6_2_0_PASS.jpg";

string fileName = fileDir + "solar_cell_03.png";
vector<string> filelist;

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

int main()
{
	Mat input_img = cv::imread(fileName, cv::ImreadModes::IMREAD_ANYCOLOR);

	size_t width = input_img.cols;
	size_t height = input_img.rows;

	uchar* pData = input_img.data;


	Mat Img_R = Mat(height, width, CV_8UC1);
	Mat Img_G = Mat(height, width, CV_8UC1);
	Mat Img_B = Mat(height, width, CV_8UC1);

	uchar* pData_R = Img_R.data;
	uchar* pData_G = Img_G.data;
	uchar* pData_B = Img_B.data;


	Split_Color2RGB(pData, width, height, pData_R, pData_G, pData_B);

	Mat Region = Mat::ones(Size(width, height), CV_8UC1);
	//Region = Img_R.clone();
	threshold(Img_R, Region, 159, 255, ThresholdTypes::THRESH_BINARY);

	Mat connectedRegion = Mat::zeros(Size(width, height), CV_8UC1);
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;

	//dilate(Region, Region, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
	//erode(Region, Region, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);

	Mat labels = Mat::ones(Size(width, height), CV_8UC1);

	connectedComponents(Region, labels, 8);
	//findContours(Region, contours, hierachy, RETR_TREE, CHAIN_APPROX_NONE);
	findContours(labels, contours, hierachy, RETR_CCOMP, CHAIN_APPROX_NONE);
	
	Mat test2 = Mat::zeros(Size(width, height), CV_8UC3);

	for (int i = 0; i < contours.size(); i++)
	{
		drawContours(test2, contours, (int)i, Scalar(0,0,255), 1, LineTypes::LINE_4);
	}

	Mat drawRegion = Region.clone();

	cvtColor(drawRegion, drawRegion, COLOR_GRAY2BGR);

	int max_index = -1;
	double max_area = -1;

	for (size_t i = 0; i < contours.size(); i++)
	{
		double area = cv::contourArea(contours[i]);
		if (max_area < area)
		{
			max_area = area;
			max_index = i;
		}
	}

	Mat GoodSmallParts = Mat::zeros(Size(width, height), CV_8UC1);
	Mat GoodLongParts = Mat::zeros(Size(width, height), CV_8UC1);

	for (int i = 0; i < contours.size(); i++)
	{
		double area = cv::contourArea(contours[i]);
		double length = cv::arcLength(contours[i], false);
		RotatedRect r_rt = cv::minAreaRect(contours[i]);
		float width = std::max(r_rt.boundingRect().size().width, r_rt.boundingRect().size().height);
		if (area < 10) continue;
		if ((area > 3500 && area < 35000) && (width < 500) && (length > 1300) && (i != max_index))
		{
			printf("GoodSmallParts i %d is is area is %f, width is %f\n", i, area, width);
			//printf("i %d is isarea is %f\n", i, area);
			//RotatedRect r_rt = cv::minAreaRect(contours[i]);
			//cv::rectangle(connectedRegion, r_rt.boundingRect2f(), Scalar(255));

			//string desc = "";
			//desc += std::format("id [{}]\n", i);
		drawContours(GoodSmallParts, contours, (int)i, Scalar(255), 1, LineTypes::LINE_8);

			putText(drawRegion, std::format("id [{}]\n", i), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
				1, 2, Scalar(255, 255, 0), 1, 8);
			//polylines(connectedRegion, contours[i], false, (255));
		}
		if ((area > 6000) && (width < 350) && (i != max_index))
		{

			printf("longparts i %d is is area is %f, width is %f\n", i, area, width);
			RotatedRect r_rt = cv::minAreaRect(contours[i]);
			drawContours(GoodLongParts, contours, (int)i, Scalar(255), 1, LineTypes::LINE_4);
			//putText(GoodLongParts, std::format("id [{}]\n", i), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
			//1, 2, Scalar(255, 255, 0), 1, 8);
		}

	}

	vector<vector<Point>> goodLargePartscontours;
	vector<Vec4i> goodLargePartsHierachy;
	//Mat GoodLongParts = Mat::zeros(Size(width, height), CV_8UC1);


	//findContours(Region, contours, hierachy, RETR_TREE, CHAIN_APPROX_NONE);
	findContours(GoodLongParts, goodLargePartscontours, goodLargePartsHierachy, RETR_TREE, CHAIN_APPROX_NONE);

	Mat test0 = Region - GoodLongParts - GoodSmallParts;

	Mat test = Mat::zeros(Size(width, height), CV_8UC3);

	for (int i = 0; i < goodLargePartscontours.size(); i++)
	{
		drawContours(input_img, goodLargePartscontours, (int)i, Scalar(0, 0, 255), 1, LineTypes::LINE_4);
		drawContours(test, goodLargePartscontours, (int)i, Scalar(0,0,255), 1, LineTypes::LINE_4);
	}
	vector<vector<Point>> goodSmallPartscontours;
	vector<Vec4i> goodSmallPartsHierachy;
	//Mat GoodLongParts = Mat::zeros(Size(width, height), CV_8UC1);


	//findContours(Region, contours, hierachy, RETR_TREE, CHAIN_APPROX_NONE);
	findContours(GoodSmallParts, goodSmallPartscontours, goodSmallPartsHierachy, RETR_TREE, CHAIN_APPROX_NONE);

	for (int i = 0; i < goodLargePartscontours.size(); i++)
	{
		drawContours(input_img, goodLargePartscontours, (int)i, Scalar(0, 0, 255), 1, LineTypes::LINE_4);
		drawContours(test, goodLargePartscontours, (int)i, Scalar(0, 0, 255), 1, LineTypes::LINE_4);
	}

	Mat defference = Region - 


	//Mat test = Region - connectedRegion;



	int z = 3;
}