#include "../Common/Common.h"
#include <cmath>

string fileDir = "C:/Users/AIOT2/Desktop/image/brake_disk/";

string fileName = fileDir + "brake_disk_part_07.png";


int main()
{
	Mat input_img = cv::imread(fileName, cv::ImreadModes::IMREAD_ANYCOLOR);

	Mat Region;

	threshold(input_img, Region, 254,255, ThresholdTypes::THRESH_BINARY);

	size_t width = input_img.cols;
	size_t height = input_img.rows;

	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	Mat morphologyImg;

	Mat kernel = Mat::ones(Size(3, 3), CV_8UC1);
	erode(Region, Region, kernel);
	dilate(Region, Region, kernel);

	findContours(Region, contours, hierachy, RETR_CCOMP, CHAIN_APPROX_NONE);

	Mat drawColor = Mat::zeros(Size(input_img.cols, input_img.rows), CV_8SC3);


	Mat resut_img = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	
	int count = 1;
	string desc = "";
	RNG rng(12345);
	RotatedRect ellipse;
	for (int i = 0; i < contours.size(); i++)
	{
		double d_mm;
		ellipse = cv::minAreaRect(contours[i]);
		double r = ellipse.size.width / 2; // sqrt(sub_x * sub_x + sub_y * sub_y);
		if (contours[i].size() > 100 && r > 20)
		{
			Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
			drawContours(resut_img, contours, i, color, 2, LINE_8, hierachy, 0);

			//RotatedRect r_rt = cv::minAreaRect(contours[i]);
			cv::ellipse(drawColor, ellipse, Scalar(0, 0, 255));

			float sub_x = abs(contours[i][0].x - ellipse.center.x);
			float sub_y = abs(contours[i][0].y - ellipse.center.y);
			double d = ellipse.size.width;
			d_mm = d * (100.0 / 512.0);

			desc += std::format("id {} : {} pxls ", count, (int)r);
			desc += std::format("d is {:4.2f} mm", d_mm);

			printf("ellipse size i %d is  %d\n", count, ellipse.size);
			printf("ellipse i %d radius is  %f\n", count, r);
			printf("ellipse i %d angle is  %f\n", count, ellipse.angle);
			printf("ellipse i %d d is  %f\n", count, d);
			printf("ellipse i %d d_mm is  %f\n", count, d_mm);

			putText(resut_img, std::format("{}", count), Point(ellipse.center.x - r, ellipse.center.y - r),
				1, 3, color, 3, 8);
				
			putText(resut_img, desc, Point(50, 50 + count * 30),
				1, 2, color, 3, 8);

			desc = "";
			count += 1;
		}
	}

	int x = 1;
}