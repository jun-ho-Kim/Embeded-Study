

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
	string fileDir = "C:/Users/AIOT2/Desktop/solar_cell/";
	//string fileName = fileDir + "2018121014312634_Lens_6_2_0_PASS.jpg";

	string fileName = fileDir + "solar_cell_03.png";
	vector<string> filelist;
	for (const auto& entry : fs::directory_iterator(fileName)) {
		//std::cout << entry.path().string() << std::endl;
		if (entry.is_regular_file() && entry.path().extension() == ".jpg" ||
			entry.is_regular_file() && entry.path().extension() == ".png")
			filelist.push_back(entry.path().string());
	}

	for (const std::string& filePath : filelist) {
		std::cout << filePath << std::endl;
		Mat input_img = cv::imread(filePath, cv::ImreadModes::IMREAD_ANYCOLOR);
		Mat draw_color = input_img.clone();
		
		//to do 
		int width = input_img.cols;
		int height = input_img.rows;
		int channel = input_img.channels();

		// 채널별로 분할할 변수를 생성합니다.
		enum eChannels { eCh_B = 0, eCh_G, eCh_R, eCh_Max };
		std::vector<cv::Mat> channels;

		// 이미지를 채널별로 분할합니다.
		cv::split(input_img, channels);
		Mat img = channels[eCh_R].clone();
		//check rotation
		Mat ptrn_rgn;
		double thres_min = 159;
		threshold(img, ptrn_rgn, thres_min, 255, ThresholdTypes::THRESH_BINARY_INV);
		

		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;
		cv::findContours(ptrn_rgn, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

		RNG rng(12345);
		for (size_t i = 0; i < contours.size(); i++)
		{
			Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
			cv::Rect rt = cv::boundingRect(contours[i]);

			cv::rectangle(draw_color, rt, color, 1);


		}


		// 연결된 구성 요소 찾기
		cv::Mat labels;
		int numComponents = cv::connectedComponents(ptrn_rgn, labels);

		// 각 구성 요소에 대해 등고선 찾기
		//std::vector<std::vector<cv::Point>> contours;
		//std::vector<cv::Vec4i> hierarchy;

		
		for (int label = 1; label < numComponents; label++) {
			cv::Mat componentMask = (labels == label);

			// 등고선 찾기
			cv::findContours(componentMask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

			for (size_t i = 0; i < contours.size(); i++)
			{
				Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
				cv::Rect rt = cv::boundingRect(contours[i]);
				cv::rectangle(draw_color, rt, color, 1);

			}
			// 등고선 시각화
			//cv::drawContours(draw_color, contours, -1, cv::Scalar(0, 255, 0), 2);

		}
		return 1;
		//std::vector<std::vector<cv::Point>> contours;
		//std::vector<cv::Vec4i> hierarchy;
		cv::findContours(ptrn_rgn, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

		//RNG rng(12345);
		for (size_t i = 0; i < contours.size(); i++)
		{
			Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
			cv::Rect rt = cv::boundingRect(contours[i]);

			cv::rectangle(draw_color, rt, color, 1);


		}


		//closing
		int kernelSize = 3;
		cv::Mat closed_rgn;
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(kernelSize, kernelSize));
		cv::morphologyEx(ptrn_rgn, closed_rgn, cv::MORPH_CLOSE, kernel);

		Mat diff_rgn = closed_rgn - ptrn_rgn;

		

		// 세로 방향의 커널을 생성합니다.
		

		cv::Mat small_rgn;
		vector<cv::Rect> vSmallLine, vMiddleLine;
		{
			kernelSize = 5;
			kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(1, kernelSize));
			cv::erode(diff_rgn, small_rgn, kernel);

			std::vector<std::vector<cv::Point>> contours;
			std::vector<cv::Vec4i> hierarchy;
			cv::findContours(small_rgn, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

			RNG rng(12345);
			for (size_t i = 0; i < contours.size(); i++)
			{
				Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
				cv::Rect rt = cv::boundingRect(contours[i]);
				int offset = 5;
				rt.x -= offset;
				rt.y -= offset;
				rt.width += offset*2;
				rt.height += offset * 2;
				cv::rectangle(draw_color, rt, color, 1);

				//cv::Rect rt = cv::boundingRect(contours[i]);
				int h_m = 730 - 262;//middle
				int h_tp = 245 - 10;//middle
				int margin = 30;
				if (h_m - margin < rt.height && rt.height < h_m + margin)
					vMiddleLine.push_back(rt);
				if (h_tp - margin < rt.height && rt.height < h_tp + margin)
					vSmallLine.push_back(rt);
			}
		}
		
		for (size_t i = 0; i < vMiddleLine.size(); i++)
		{
			Scalar color = Scalar(0, 0, 255);
			cv::rectangle(draw_color, vMiddleLine[i], color, 1);
		}
		for (size_t i = 0; i < vSmallLine.size(); i++)
		{
			Scalar color = Scalar(0, 255, 0);
			cv::rectangle(draw_color, vSmallLine[i], color, 1);
		}



		cv::Mat dilate_rgn;
		cv::dilate(small_rgn, dilate_rgn, kernel, Point(-1,-1),2);


		////get roi
		//Rect roi = Rect(1200, 400, 3400 - 1200, 2600 - 400);

		//Mat img_1 = input_img(Rect(0, 0, width, height));
		//Mat obj_img = img_1(roi).clone();
		//Mat hole_img = ~obj_img;
		//Mat bin_hole_img;
		//double thres_min = 200;
		//double thres_max = 255;
		//threshold(hole_img, bin_hole_img, thres_min, thres_max, ThresholdTypes::THRESH_BINARY);

		////erosion
		//erode(bin_hole_img, bin_hole_img, Mat::ones(Size(3, 3), CV_8UC1), Point(-1, -1), 2);
		//// 윤곽선 그리기
		//std::vector<std::vector<cv::Point>> contours;
		//std::vector<cv::Vec4i> hierarchy;
		//cv::findContours(bin_hole_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

		//int max_index = -1;
		//double max_area = -1;
		//for (size_t i = 0; i < contours.size(); i++)
		//{
		//	double area = cv::contourArea(contours[i]);
		//	if (max_area < area)
		//	{
		//		max_area = area;
		//		max_index = i;
		//	}
		//}
		////make mask

		//cv::Mat mask = cv::Mat::zeros(bin_hole_img.size(), CV_8UC1);
		//if (max_index >= 0)
		//{
		//	drawContours(mask, contours, max_index, cv::Scalar(255), CV_FILLED);
		//}
		////reduce image
		//Mat reduced_obj_img = obj_img & mask;
		//

		////get sub images
		//vector<Mat> vObj_Imgs;
		//for (size_t i = 0; i < 4; i++)
		//{
		//	Mat img_sub = input_img(Rect(0, i*height, width, height));
		//	Mat obj_sub = img_sub(roi) & mask;
		//	vObj_Imgs.push_back(obj_sub);
		//}
		//
		//
		//
		////run algorithm
		////decision
		////draw
		//int result = 1;
	}

	return 1;
	//string fileName = fileDir + "shapes.jpg";


	////load image
	//Mat src_color = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	//Mat draw_color = src_color.clone();

	////pre-processing
	//Mat gray_img, bin_img;
	//cvtColor(src_color, gray_img, ColorConversionCodes::COLOR_BGR2GRAY);

	//cv::Mat gray_img_inv = cv::Mat::zeros(gray_img.size(), CV_8UC1);
	//gray_img_inv = ~gray_img;
	//double thres_min = 20;
	//double thres_max = 255;
	//threshold(gray_img_inv, bin_img, thres_min, thres_max, ThresholdTypes::THRESH_BINARY);

	////findcontours
	//// 윤곽선 찾기
	//std::vector<std::vector<cv::Point>> contours;
	//std::vector<cv::Vec4i> hierarchy;
	//cv::findContours(bin_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

	////특징값 저장
	//vector<string> vDesc;

	//cv::Mat labels = cv::Mat::zeros(bin_img.size(), CV_8UC1);

	//// 윤곽선 그리기
	//RNG rng(12345);
	//for (size_t i = 0; i < contours.size(); i++)
	//{
	//	if (contours[i].size() < 3) continue;
	//	Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
	//	drawContours(draw_color, contours, (int)i, color, 2, LINE_8, hierarchy, 0);
	//	//cv::Rect rt = cv::boundingRect(contours[i]);
	//	//cv::rectangle(draw_color, rt, Scalar(255, 100, 0), 1);

	//	double length = cv::arcLength(contours[i], false);
	//	double area = cv::contourArea(contours[i]);
	//	RotatedRect r_rt = cv::minAreaRect(contours[i]);
	//	RotatedRect ellipse;
	//	if (contours[i].size() > 5)
	//	{
	//		ellipse = cv::minAreaRect(contours[i]); //cv::fitEllipse(contours[i]);
	//		cv::ellipse(draw_color, ellipse, Scalar(10, 10, 10));
	//	}

	//	//파랑파랑
	//	cv::rectangle(draw_color, r_rt.boundingRect(), Scalar(128, 128, 255));
	//	//draw rotated rectangle
	//	{
	//		const int rect_poly_vertexs = 4;
	//		cv::Point2f vertices2f[rect_poly_vertexs];
	//		r_rt.points(vertices2f);
	//		cv::Point vertices[rect_poly_vertexs];
	//		for (int i = 0; i < rect_poly_vertexs; ++i) { vertices[i] = vertices2f[i]; }
	//		//cv::fillConvexPoly(draw_color,vertices, rect_poly_vertexs, Scalar(255, 0, 255));
	//		for (int i = 0; i < 4; i++)
	//			line(draw_color, vertices[i], vertices[(i + 1) % 4], Scalar(128, 128, 255), 2);
	//	}





	//	Point2f center(0, 0);
	//	float radius = 0;
	//	cv::minEnclosingCircle(contours[i], center, radius);
	//	cv::circle(draw_color, center, radius, Scalar(255, 255, 255));

	//	cv::drawMarker(draw_color, center, Scalar(0, 255, 255), MarkerTypes::MARKER_CROSS);
	//	cv::drawMarker(draw_color, center, Scalar(128, 255, 255), MarkerTypes::MARKER_TILTED_CROSS);

	//	string desc = "";
	//	desc += std::format("id [{}]\n", i + 1);
	//	desc += std::format("len {}\n", length);
	//	desc += std::format("area {}\n", area);
	//	desc += std::format("min radius {}\n", radius);
	//	desc += std::format("major len {}\n", std::max(r_rt.boundingRect().size().width, r_rt.boundingRect().size().height));
	//	desc += std::format("minor len {}\n", std::min(r_rt.boundingRect().size().width, r_rt.boundingRect().size().height));
	//	desc += std::format("ratio {}\n", r_rt.boundingRect().size().aspectRatio());

	//	//get mean value from graysacle
	//	{
	//		drawContours(labels, contours, i, cv::Scalar(i), CV_FILLED);
	//		Rect roi = cv::boundingRect(contours[i]);
	//		Scalar mean = cv::mean(gray_img(roi), labels(roi) == i);
	//		desc += std::format("gray {}\n", mean[0]);
	//	}
	//	desc += std::format("x {}\n", r_rt.boundingRect().tl().x);
	//	desc += std::format("y {}\n", r_rt.boundingRect().tl().y);

	//	putText(draw_color, std::format("id [{}]\n", i + 1), Point(r_rt.boundingRect().tl().x, r_rt.boundingRect().tl().y),
	//		1, 2, Scalar(255, 255, 0), 1, 8);
	//	cout << desc << endl;
	//}
	////show contours
	//const char* draw_window = "draw image";
	//namedWindow(draw_window);
	//imshow(draw_window, draw_color);
	//waitKey(0);
	////show text result


	//for (size_t i = 0; i < contours.size(); i++)
	//{
	//	labels = 0;
	//	drawContours(labels, contours, i, cv::Scalar(255), CV_FILLED);
	//	Mat mask_color;
	//	cvtColor(labels, mask_color, ColorConversionCodes::COLOR_GRAY2BGR);
	//	Mat reduced_color = src_color & mask_color;
	//	imshow(draw_window, reduced_color);
	//	waitKey(0);
	//}

}
