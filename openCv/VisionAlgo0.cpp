

/*
library include
library link
*/
#include "../Common/Common.h"
#include <filesystem>
namespace fs = std::filesystem;
int main()
{
	//image path
	string fileDir = "D:/Pub/KCCImageNet/camera module";
	vector<string> filelist;
	for (const auto& entry : fs::directory_iterator(fileDir)) {
		std::cout << entry.path().string() << std::endl;
		filelist.push_back(entry.path().string());
	}

	for (const std::string& filePath : filelist) {
		std::cout << filePath << std::endl;
		Mat input_img = cv::imread(filePath, cv::ImreadModes::IMREAD_ANYCOLOR);
		//to do 
		int width = input_img.cols;
		int height = input_img.rows/4;
		int channel = input_img.channels();
		Rect roi = Rect(1200, 400, 3400 - 1200, 2600 - 400);
		Mat img_1 = input_img(Rect(0, 0, width, height));
		Mat hole_img = img_1(roi).clone();
		hole_img = ~hole_img;
		Mat bin_hole_img;
		double thres_min = 200;
		double thres_max = 255;
		threshold(hole_img, bin_hole_img, thres_min, thres_max, ThresholdTypes::THRESH_BINARY);
		//get sub images
		//get roi
		//make mask
		//reduce image
		//run algorithm
		//decision
		//draw
		int result = 1;
	}

	return 1;
	string fileName = fileDir + "shapes.jpg";


	//load image
	Mat src_color = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	Mat draw_color = src_color.clone();

	//pre-processing
	Mat gray_img, bin_img;
	cvtColor(src_color, gray_img, ColorConversionCodes::COLOR_BGR2GRAY);

	cv::Mat gray_img_inv = cv::Mat::zeros(gray_img.size(), CV_8UC1);
	gray_img_inv = ~gray_img;
	double thres_min = 20;
	double thres_max = 255;
	threshold(gray_img_inv, bin_img, thres_min, thres_max, ThresholdTypes::THRESH_BINARY);

	//findcontours
	// À±°û¼± Ã£±â
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(bin_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

	//Æ¯Â¡°ª ÀúÀå
	vector<string> vDesc;

	cv::Mat labels = cv::Mat::zeros(bin_img.size(), CV_8UC1);

	// À±°û¼± ±×¸®±â
	RNG rng(12345);
	for (size_t i = 0; i < contours.size(); i++)
	{
		if (contours[i].size() < 3) continue;
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		drawContours(draw_color, contours, (int)i, color, 2, LINE_8, hierarchy, 0);
		//cv::Rect rt = cv::boundingRect(contours[i]);
		//cv::rectangle(draw_color, rt, Scalar(255, 100, 0), 1);

		double length = cv::arcLength(contours[i], false);
		double area = cv::contourArea(contours[i]);
		RotatedRect r_rt = cv::minAreaRect(contours[i]);
		RotatedRect ellipse;
		if (contours[i].size() > 5)
		{
			ellipse = cv::minAreaRect(contours[i]); //cv::fitEllipse(contours[i]);
			cv::ellipse(draw_color, ellipse, Scalar(10, 10, 10));
		}

		//ÆÄ¶ûÆÄ¶û
		cv::rectangle(draw_color, r_rt.boundingRect(), Scalar(128, 128, 255));
		//draw rotated rectangle
		{
			const int rect_poly_vertexs = 4;
			cv::Point2f vertices2f[rect_poly_vertexs];
			r_rt.points(vertices2f);
			cv::Point vertices[rect_poly_vertexs];
			for (int i = 0; i < rect_poly_vertexs; ++i) { vertices[i] = vertices2f[i]; }
			//cv::fillConvexPoly(draw_color,vertices, rect_poly_vertexs, Scalar(255, 0, 255));
			for (int i = 0; i < 4; i++)
				line(draw_color, vertices[i], vertices[(i + 1) % 4], Scalar(128, 128, 255), 2);
		}





		Point2f center(0, 0);
		float radius = 0;
		cv::minEnclosingCircle(contours[i], center, radius);
		cv::circle(draw_color, center, radius, Scalar(255, 255, 255));

		cv::drawMarker(draw_color, center, Scalar(0, 255, 255), MarkerTypes::MARKER_CROSS);
		cv::drawMarker(draw_color, center, Scalar(128, 255, 255), MarkerTypes::MARKER_TILTED_CROSS);

		string desc = "";
		desc += std::format("id [{}]\n", i + 1);
		desc += std::format("len {}\n", length);
		desc += std::format("area {}\n", area);
		desc += std::format("min radius {}\n", radius);
		desc += std::format("major len {}\n", std::max(r_rt.boundingRect().size().width, r_rt.boundingRect().size().height));
		desc += std::format("minor len {}\n", std::min(r_rt.boundingRect().size().width, r_rt.boundingRect().size().height));
		desc += std::format("ratio {}\n", r_rt.boundingRect().size().aspectRatio());

		//get mean value from graysacle
		{
			drawContours(labels, contours, i, cv::Scalar(i), CV_FILLED);
			Rect roi = cv::boundingRect(contours[i]);
			Scalar mean = cv::mean(gray_img(roi), labels(roi) == i);
			desc += std::format("gray {}\n", mean[0]);
		}
		desc += std::format("x {}\n", r_rt.boundingRect().tl().x);
		desc += std::format("y {}\n", r_rt.boundingRect().tl().y);

		putText(draw_color, std::format("id [{}]\n", i + 1), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
			1, 2, Scalar(255, 255, 0), 1, 8);
		cout << desc << endl;
	}
	//show contours
	const char* draw_window = "draw image";
	namedWindow(draw_window);
	imshow(draw_window, draw_color);
	waitKey(0);
	//show text result


	for (size_t i = 0; i < contours.size(); i++)
	{
		labels = 0;
		drawContours(labels, contours, i, cv::Scalar(255), CV_FILLED);
		Mat mask_color;
		cvtColor(labels, mask_color, ColorConversionCodes::COLOR_GRAY2BGR);
		Mat reduced_color = src_color & mask_color;
		imshow(draw_window, reduced_color);
		waitKey(0);
	}

}
