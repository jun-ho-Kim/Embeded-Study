#include "../Common/Common.h"
#include "ISP.h"
#include <io.h>
#include <filesystem>
namespace fs = std::filesystem;
//image path
//string fileDir = "C:/Users/AIOT2/Desktop/camera module/*.*";

string fileDir = "C:/Users/AIOT2/Desktop/camera module/";
//string fileName = fileDir + "2018121014312634_Lens_6_2_0_PASS.jpg";

string fileName = fileDir + "20181210143119869_Lens_8_1_0_FAIL_Scratch.jpg";
vector<string> filelist;

int main()
{
	//for (const auto& entry : fs::directory_iterator(fileDir)) {
	//	std::cout << entry.path().string() << std::endl;
	//	filelist.push_back(entry.path().string());
	//}

	//for (const std::string filePath : filelist)
	//{
	//	std::cout << filePath << std::endl;
	//	Mat input_img = cv::imread(filePath, cv::ImreadModes::IMREAD_ANYCOLOR);
	//	//to do
	//	int width = input_img.cols;
	//	int heigth = input_img.rows / 4;
	//	int channel = input_img.channels();
	//	Rect roi = Rect(1200, 400, 3400 - 1200, 2600 - 400); // 1200, 400, 2200, 2200
	//	Mat img_1 = input_img(Rect(0, 0, width, heigth));
	//	Mat hole_img = img_1(roi).clone();
	//	hole_img = ~hole_img;
	//	Mat bin_hole_img;
	//	double thres_min = 200;
	//	double thres_max = 255;
	//	threshold(hole_img, bin_hole_img, thres_min, thres_max, ThresholdTypes::THRESH_BINARY);
	//}


	//	todo
	//get sub image
	
	//Mat src_camera = cv::imread(fileName, cv::ImreadModes::IMREAD_ANYCOLOR);
	//get roi
	Mat input_img = cv::imread(fileName, cv::ImreadModes::IMREAD_ANYCOLOR);
	int width = input_img.cols;
	int heigth = input_img.rows / 4;
	int channel = input_img.channels();
	Rect roi = Rect(1200, 400, 2200, 2200);

	Mat img_1 = input_img(Rect(0, 0, width, heigth));
	Mat obj_img = img_1(roi).clone();
	Mat hole_img = ~obj_img;
	Mat bin_hole_img;

	double thres_min = 200;
	double thres_max = 255;
	threshold(hole_img, bin_hole_img, thres_min, thres_max, ThresholdTypes::THRESH_BINARY);
	
	dilate(bin_hole_img, bin_hole_img, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
	erode(bin_hole_img, bin_hole_img, Mat::ones(Size(3,3), CV_8UC1), Point(-1, -1), 2);

	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(bin_hole_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
	
	RNG rng(12345);
	for (size_t i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		cv::drawContours(bin_hole_img, contours, (int)i, Scalar(0,0,255), 1, LINE_8, hierarchy, 0);
	}

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
	// make masks
	cv::Mat mask = cv::Mat::zeros(bin_hole_img.size(), CV_8UC1);
	if (max_index >= 0)
	{
		drawContours(mask, contours, max_index, cv::Scalar(255), LineTypes::FILLED);
	}

	Mat reduced_obj_img = obj_img & mask;

	dilate(bin_hole_img, bin_hole_img, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);

	Mat mask_donut = mask - bin_hole_img;

	//erode(mask_donut, mask_donut, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
	//dilate(mask_donut, mask_donut, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
	Mat mask_small = cv::Mat::zeros(bin_hole_img.size(), CV_8UC1);;
	std::vector<cv::Vec4i> donut_hierarchy;

	std::vector<std::vector<cv::Point>> donut_contours;

	erode(mask_small, mask_small, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
	dilate(mask_small, mask_small, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);

	findContours(mask_donut, donut_contours, donut_hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
	

	max_index = -1;
	max_area = -1;

	for (size_t i = 0; i < donut_contours.size(); i++)
	{
		double area = cv::contourArea(donut_contours[i]);
		if (max_area < area)
		{
			max_area = area;
			max_index = i;
		}
	}

	drawContours(mask_small, donut_contours, max_index, cv::Scalar(255), LineTypes::FILLED);
	erode(mask_small, mask_small, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
	dilate(mask_small, mask_small, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);

	mask_donut = mask - mask_small;

	int t = 3;

	vector<Mat> vObj_Imgs;
	for (size_t i = 0; i < 4; i++)
	{
		Mat img_sub = input_img(Rect(0, i * heigth, width, heigth));
		Mat obj_sub = img_sub(roi) & mask;
		vObj_Imgs.push_back(obj_sub);
	}

	Mat test = mask_donut - vObj_Imgs[0];
	Mat test1 = mask_donut - vObj_Imgs[1];
	Mat test2 = mask_donut - vObj_Imgs[2];
	Mat test3 = mask_donut - vObj_Imgs[3];

	//test = ~test;

	std::vector<std::vector<cv::Point>> lens_contours;
	std::vector<cv::Vec4i> lens_hierarchy;

	
	threshold(test, test, 100, thres_max, ThresholdTypes::THRESH_BINARY);
	Mat result = test.clone();
	cvtColor(result, result, COLOR_GRAY2BGR);

	dilate(test, test, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
	erode(test, test, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);

	findContours(test, lens_contours, lens_hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);



	for (size_t i = 0; i< lens_contours.size(); ++i)
	{
		RotatedRect r_rt = cv::minAreaRect(lens_contours[i]);
		cv::rectangle(result, r_rt.boundingRect(), Scalar(0,0,255));

		string desc = "";
		desc += std::format("id [{}]\n", i);
		putText(result, std::format("id [{}]\n", i), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
			1, 2, Scalar(255, 255, 0), 1, 8);
	}

	//740 600 1500 1360
	Rect inner_roi = Rect(740, 600, 1500 - 740, 1360 - 600);
	Mat inner_img1 = obj_img(inner_roi).clone();
	Mat rev_inner_img = ~inner_img1;
	Mat bin_inner_img;

	std::vector<std::vector<cv::Point>> inner_contours;
	std::vector<cv::Vec4i> inner_hierarchy;
	threshold(rev_inner_img, bin_inner_img, 180, thres_max, ThresholdTypes::THRESH_BINARY);
	cv::findContours(bin_inner_img, inner_contours, inner_hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

	max_index = -1;
	max_area = -1;

	for (size_t i = 0; i < inner_contours.size(); i++)
	{
		double area = inner_contours[i].size();
		if (max_area < area)
		{
			max_area = area;
			max_index = i;
		}
	}



	Mat src_color = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	Mat draw_color = src_color.clone();

	int z = 9;



	cv::Mat inner_mask = cv::Mat::zeros(bin_inner_img.size(), CV_8UC1);
	drawContours(inner_mask, inner_contours, max_index, cv::Scalar(255), LineTypes::FILLED);

	dilate(inner_mask, inner_mask, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
	erode(inner_mask, inner_mask, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);

	inner_mask = ~inner_mask;

	Mat reduced_inner_obj_img = inner_img1 & inner_mask;


	//run algorithm




	/*
	Mat bin_img;
	Mat detect_circle = src_camera.clone();
	//Mat im_floodfill = src_camera.clone();
	Mat detect_circle_inv;
	threshold(detect_circle, bin_img, 100, 255, ThresholdTypes::THRESH_BINARY_INV);
	detect_circle_inv = ~detect_circle;
	Mat bin_img_inv = ~bin_img;
	//floodFill(bin_img_inv, cv::Point(0, 0), Scalar(0));
	*/


	//Mat draw_camera = src_camera.clone();
	//Rect roi = cv::boundingRect
	 
	//make mask
	//reduce image
	//run algorithm
	//decision
	//draw

	int y = 5;

	struct _finddata_t fd;

	intptr_t handle;

	if ((handle = _findfirst(fileDir.c_str(), &fd)) == -1L)

		cout << "No file in directory!" << endl;
	do
	{
		cout << fd.name << endl;




	} while (_findnext(handle, &fd) == 0);



	_findclose(handle);


	//int z = 3;

	return 0;

}