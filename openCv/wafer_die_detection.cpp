#include "../Common/Common.h"

string fileDir = "C:/Users/AIOT2/Desktop/image/wafer/";

//string fileName = fileDir + "wafer_dies.png";
string fileName = fileDir + "wafer_dies.png";

int main()
{
	Mat input_img = cv::imread(fileName, cv::ImreadModes::IMREAD_ANYCOLOR);

	int x_num = 4;
	int y_num = 6;

	int count = 0;

	size_t width = input_img.cols;
	size_t height = input_img.rows;

	size_t ori_width = input_img.cols/ x_num;
	size_t ori_height = input_img.rows / y_num;

	Mat Region;
	// 격자 테스트
	//algorithm 1
	/*
	threshold(input_img, Region, 170, 255, ThresholdTypes::THRESH_BINARY);

	Mat draw_img = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);

	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;

	findContours(Region, contours, hierachy, RETR_CCOMP, CHAIN_APPROX_NONE);
	
	RNG rng(12345);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		RotatedRect r_rt = cv::minAreaRect(contours[i]);
		size_t rt_width = r_rt.boundingRect2f().width;
		size_t rt_height = r_rt.boundingRect2f().height;
		if (contours[i].size() > 10 && rt_width > 45 && rt_height > 45)
		{
			drawContours(draw_img, contours, (int)i, color, 2, LINE_8, hierachy, 0);
			count += 1;
			printf("%d is width %f\n", count, r_rt.boundingRect2f().width);
			printf("%d is height %f",count, r_rt.boundingRect2f().height);
			putText(draw_img, std::format("{}", count), Point(r_rt.center.x, r_rt.center.y),
				1, 2, color, 1, 2);
		}
	}
	*/

	//315 154
	//365 205
	//Rect bounds(315, 154, 365, 205);
	//Mat roi = input_img(bounds);
	//Mat draw_img = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	///
	
	Rect bounds(0, 0, ori_width, ori_height);
	//Rect r(x, y, width, height); // partly outside
	Mat roi = input_img(bounds); // cropped to fit image
	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;

	Mat draw_img = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	//Mat morphologyImg;
	for (int x = 0; x < x_num; x++)
	{
		for (int y = 0; y < y_num; y++)
		{
			Rect objectRange(ori_width * (x), ori_height * (y), ori_width, ori_height);
			Mat object = input_img(objectRange);

			Mat result = roi - object;

			
			threshold(result, result, 20, 0, ThresholdTypes::THRESH_BINARY);
			findContours(result, contours, hierachy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
			
			if (contours.size() == 0)
			{
				cv::rectangle(draw_img, objectRange, Scalar(0, 0, 255));
				count += 1;
				
				putText(draw_img, std::format("{}", count), Point(ori_width * (x) + ori_width / 2 -50, ori_height * (y) + ori_height / 2),
					1, 2, Scalar(255, 255, 0), 1, 2);
			}
			//drawContours(draw_img, contours, (int)i, color, 2, LINE_8, hierachy, 0);
		}
	}

	printf("%d 개의 object가 같습니다.", count);
	//findContours(Region, contours, hierachy, RETR_TREE, CHAIN_APPROX_NONE);

	RNG rng(12345);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		drawContours(draw_img, contours, (int)i, color, 2, LINE_8, hierachy, 0);
	}

	
	int z = 9;
}