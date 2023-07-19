#include "../Common/Common.h"
#include <filesystem>

namespace fs = std::filesystem;

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

void Split_Color2R(uchar* pDataBGR, size_t& w, size_t& h, uchar* pR)
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
			int r = pDataBGR[index + 2];

			int band_index = row * w + col;
			pR[band_index] = r;
		}
	}
}

int main()
{
	string fileDir = "C:/Users/AIOT2/Desktop/image/patty/";

	string fileName1 = fileDir + "raw_patty_1.jpg";
	string fileName2 = fileDir + "result2.jpg";
	//string fileName2 = fileDir + "ripe_patties_3.jpg";
	//string fileName2 = fileDir + "ripping_patties__1.jpg";
	string fileName3 = fileDir + "ripe_patty_2.jpg";

	//Mat raw_patties_1 = imread(fileName1, COLOR_BGR2GRAY);
	Mat raw_patties_1 = imread(fileName1, COLOR_RGB2GRAY);
	Mat ripe_patties_1 = imread(fileName2, COLOR_BGR2GRAY);
	Mat ripe_patties_2 = imread(fileName3, COLOR_BGR2GRAY);

	size_t width = raw_patties_1.cols;
	size_t height = raw_patties_1.rows;

	Mat img_R = Mat(height, width, CV_8UC1);
	Mat img_G = Mat(height, width, CV_8UC1);
	Mat img_B = Mat(height, width, CV_8UC1);
	Mat img_Gray = Mat(height, width, CV_8UC1);

	cvtColor(ripe_patties_1, img_Gray, ColorConversionCodes::COLOR_RGB2GRAY);
	uchar* pData = raw_patties_1.data;
	uchar* pData_R = img_R.data;
	uchar* pData_G = img_G.data;
	uchar* pData_B = img_B.data;
	
	Mat eqImgR = Mat(height, width, CV_8UC1);
	//equalizeHist(img_R, eqImgR);

	Split_Color2RGB(pData, width, height, pData_R, pData_G, pData_B);
	
	size_t width2 = ripe_patties_1.cols;
	size_t height2 = ripe_patties_1.rows;

	Mat img_R_2 = Mat(height2, width2, CV_8UC1);
	Mat img_G_2 = Mat(height2, width2, CV_8UC1);
	Mat img_B_2 = Mat(height2, width2, CV_8UC1);

	uchar* pData_2 = ripe_patties_1.data;
	uchar* pData_R_2 = img_R_2.data;
	uchar* pData_G_2 = img_G_2.data;
	uchar* pData_B_2 = img_B_2.data;

	Split_Color2RGB(pData_2, width2, height2, pData_R_2, pData_G_2, pData_B_2);

	Mat test;
	Mat ori_img_R = img_R_2;
	//threshold(img_R, test, 200, 255, ThresholdTypes::THRESH_BINARY);

	Mat test2;
	//threshold(~img_R_2, test2, 25, 0, ThresholdTypes::THRESH_TOZERO);

	//test2 = ~test2;
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;

	//threshold(test2, test2, 254, 0, ThresholdTypes::THRESH_TOZERO_INV);
	//Mat test3;
	//cv::erode(test2, test3, Mat::ones(Size(3, 3), CV_8UC1));
	//cv::dilate(test3, test3, Mat::ones(Size(3, 3), CV_8UC1));
	findContours(img_R_2, contours, hierachy, RETR_CCOMP, CHAIN_APPROX_NONE);

	Mat draw_color = Mat(height2, width2, CV_8UC3);
	RNG rng(12345);
	for (int i = 0; i < contours.size(); i++)
	{
		if (contours[i].size() < 400 || contours[i].size() > 3000) continue;
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		RotatedRect r_rt = cv::minAreaRect(contours[i]);
		double area = cv::contourArea(contours[i]);

		drawContours(draw_color, contours, (int)i, color, 2, LINE_8, hierachy, 0);
		Rect roi = cv::boundingRect(contours[i]);

		Mat roi_img = img_R_2(roi).clone();//Mat(height, width, CV_8UC1);//
		size_t roi_width = roi_img.cols;
		size_t roi_height = roi_img.rows;


		// rate가 200 값이 80% 이상인 경우 raw
		// rate가 100이상이 80% 이상인 경우 well
		// = rsize/area
		int r_size = 0;
		for (int row = 0; row < roi_height; row++)
		{
			for (int cols = 0; cols < roi_width; cols++)
			{
				roi_img[row];
			}
		}

		//Mat roi_R = Mat(roi_height, roi_width, CV_8UC1);
		//uchar* roi_data = roi_R.data;

		//Split_Color2R(roi_img.data, roi_width, roi_height, roi_data);
		


		putText(draw_color, std::format("id [{}]\n", i), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
			1, 2, Scalar(0, 255, 255), 1, 2);





		//RotatedRect ellipse = cv::minAreaRect(contours[i]);;
		//cv::ellipse(draw_color, ellipse, Scalar(10, 10, 10));
		//cv::rectangle(draw_color, r_rt.boundingRect(), Scalar(128, 128, 255));
		//draw rotated rectangle
		Rect tet;
		//const int rect_poly_vertexs = 4;
		//cv::Point2f vertices2f[rect_poly_vertexs];
		//r_rt.points(vertices2f);
		//cv::Point vertices[rect_poly_vertexs];
		//for (int i = 0; i < rect_poly_vertexs; ++i) { vertices[i] = vertices2f[i]; }
		////cv::fillConvexPoly(draw_color,vertices, rect_poly_vertexs, Scalar(255, 0, 255));
		//for (int i = 0; i < 4; i++)
		//	line(ripe_patties_1, vertices[i], vertices[(i + 1) % 4], Scalar(128, 128, 255), 2);
		//cv::ellipse(ripe_patties_1, r_rt, Scalar(0, 0, 255));
		////Mat roi(ripe_patties_1, r_rt.,Scalar(0, 0, 255)));
		
		//
	}

	

	int z = 5;
}