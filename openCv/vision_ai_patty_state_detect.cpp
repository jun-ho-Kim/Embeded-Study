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

int main()
{
	string fileDir = "C:/Users/AIOT2/Desktop/image/patty/";

	string fileName2 = fileDir + "result4.jpg";

	Mat patties_img = imread(fileName2, COLOR_BGR2GRAY);

	size_t width = patties_img.cols;
	size_t height = patties_img.rows;

	Mat img_R = Mat(height, width, CV_8UC1);
	Mat img_G = Mat(height, width, CV_8UC1);
	Mat img_B = Mat(height, width, CV_8UC1);
	Mat img_Gray = Mat(height, width, CV_8UC1);

	cvtColor(patties_img, img_Gray, ColorConversionCodes::COLOR_RGB2GRAY);
	uchar* pData = patties_img.data;
	uchar* pData_R = img_R.data;
	uchar* pData_G = img_G.data;
	uchar* pData_B = img_B.data;

	Split_Color2RGB(pData, width, height, pData_R, pData_G, pData_B);

	vector<vector<Point>> contours;
	vector<Vec4i> hierachy;
	findContours(img_R, contours, hierachy, RETR_CCOMP, CHAIN_APPROX_NONE);

	Mat result_img = patties_img.clone();

	Mat draw_color = Mat(height, width, CV_8UC3);
	RNG rng(12345);
	int patty_count = 0;
	for (int i = 0; i < contours.size(); i++)
	{
		int raw_size = 0;
		int medium_size = 0;
		int welldon_size = 0;
		int col_size = 0;

		if (contours[i].size() < 400 || contours[i].size() > 3000) continue;

		patty_count += 1;

		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		RotatedRect r_rt = cv::minAreaRect(contours[i]);
		double area = cv::contourArea(contours[i]);
		drawContours(img_R, contours, (int)i, Scalar(0), 2, LINE_8, hierachy, 0);
		drawContours(draw_color, contours, (int)i, color, 2, LINE_8, hierachy, 0);
		Rect roi = cv::boundingRect(contours[i]);

		Mat roi_img = img_R(roi).clone();
		size_t roi_width = roi_img.cols;
		size_t roi_height = roi_img.rows;
		
		for (int row = 0; row < roi_height; row++)
		{
			for (int col = 0; col < roi_width; col++)
			{

				int value = roi_img.data[row * col + col];
				if (value > 180)
					raw_size++;
				else if (value > 150)
					medium_size++;
				else if (value > 100)
					welldon_size++;
				else if (value < 100 && value > 0)
					col_size++;
			}
		}
		
		string meat_state = "";

		if (raw_size / area > 0.5)
			meat_state = "raw";
		else if(col_size / area > 0.15)
			meat_state = "col";
		else if(medium_size > welldon_size)
			meat_state = "medium";
		else //(medium_size < welldon_size)
			meat_state = "welldon";

		putText(result_img, std::format("[{}]", meat_state), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
			1, 2, Scalar(0, 255, 255), 1, 2);
		cv::rectangle(result_img, r_rt.boundingRect(), Scalar(0, 0, 255));

		putText(result_img, std::format("[{}]", meat_state), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
			1, 2, Scalar(0, 255, 255), 1, 2);

		putText(result_img, std::format("area: {}", area), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y+30),
			1, 2, Scalar(0, 255, 255), 1, 2);
	}

		putText(result_img, std::format("count: {}", patty_count), Point(50, 30),
			1, 2, Scalar(0), 1, 2);

	int z = 5;
}