
#include <iostream>

/*
library include
library link
*/
#include "../Common/Common.h"

int main()
{
	//main1();
	//image path
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "find_google_area.png";


	//load image
	Mat src_color = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	Mat draw_color = src_color.clone();

	Mat gray_img, bin_img;

	Mat src_HSV;
	cvtColor(src_color, src_HSV, COLOR_BGR2HSV);

	int low_H = 147;
	int high_H = 180;
	int low_S = 54;
	int high_S = 250;
	int low_V = 111;
	int hight_V = 219;
	
	Scalar lower_R(low_H, low_S, low_V);
	Scalar high_R(high_H, high_S, hight_V);
	Mat detect_img_R;
	inRange(src_HSV, lower_R, high_R, detect_img_R);
	
	RNG rng(12345);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	cv::erode(detect_img_R, detect_img_R, Mat::ones(Size(3, 3), CV_8UC1));
	cv::dilate(detect_img_R, detect_img_R, Mat::ones(Size(5, 5), CV_8UC1));

	cv::dilate(detect_img_R, detect_img_R, Mat::ones(Size(5, 5), CV_8UC1));
	cv::erode(detect_img_R, detect_img_R, Mat::ones(Size(3, 3), CV_8UC1));
	findContours(detect_img_R, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	int max_idx = INT_MIN;
	int max_size = 0;

	for (size_t i = 0; i < contours.size(); i++)
	{
		if (contours[i].size() > max_size)
		{
			max_size = contours[i].size();
			max_idx = i;
		};
	}
	int i = max_idx;

	Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
	double length = cv::arcLength(contours[i], false);
	double area = cv::contourArea(contours[i]);
	RotatedRect r_rt = cv::minAreaRect(contours[i]);

	RotatedRect eclipse = cv::fitEllipse(contours[i]);
	cv::Point2f rectPoint[4];
	eclipse.points(rectPoint);

	{
		const int rect_poly_vertexs = 4;
		cv::Point2f vertices2f[rect_poly_vertexs];
		r_rt.points(vertices2f);
		cv::Point vertices[rect_poly_vertexs];
		for (int i = 0; i < rect_poly_vertexs; ++i) { vertices[i] = vertices2f[i]; }
		for (int i = 0; i < 4; i++)
			line(draw_color, rectPoint[i], rectPoint[(i + 1) % 4], Scalar(128, 128, 255), 2);
	}

	Point2f center(0, 0);
	float radius = 0;
	cv::minEnclosingCircle(contours[i], center, radius);


	string desc = "";
	desc += std::format("id [{}]\n", 1);
	desc += std::format("len {}\n", length);
	desc += std::format("area {}\n", area);
	desc += std::format("min radius {}\n", radius);
	desc += std::format("major len {}\n", std::max(r_rt.boundingRect().size().width, r_rt.boundingRect().size().height));
	desc += std::format("minor len {}\n", std::min(r_rt.boundingRect().size().width, r_rt.boundingRect().size().height));
	desc += std::format("ratio {}\n", r_rt.boundingRect().size().aspectRatio());	
	//get mean value from graysacle
	cv::Mat labels = cv::Mat::zeros(detect_img_R.size(), CV_8UC1);
	
	{
		RotatedRect r_rt = cv::minAreaRect(contours[i]);

		Rect roi = cv::boundingRect(contours[i]);
		Scalar mean = cv::mean(detect_img_R(roi), labels(roi) == i);
		desc += std::format("gray {}\n", mean[0]);
	}
	
	desc += std::format("x {}\n", r_rt.boundingRect().tl().x);
	desc += std::format("y {}\n", r_rt.boundingRect().tl().y);

	putText(draw_color, std::format("id [{}]\n", i+1), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
		1, 2, Scalar(0, 0, 0), 1, 2);
	cout << desc << endl;

	//show contours
	const char* draw_window = "draw image";
	int z = 8;
}
