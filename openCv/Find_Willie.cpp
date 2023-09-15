

/*
library include
library link
*/
#include "../Common/Common.h"
#include <filesystem>
namespace fs = std::filesystem;


void thresholdIntegral(cv::Mat& inputMat, cv::Mat& outputMat)
{
	// accept only char type matrices
	CV_Assert(!inputMat.empty());
	CV_Assert(inputMat.depth() == CV_8U);
	CV_Assert(inputMat.channels() == 1);
	CV_Assert(!outputMat.empty());
	CV_Assert(outputMat.depth() == CV_8U);
	CV_Assert(outputMat.channels() == 1);

	// rows -> height -> y
	int nRows = inputMat.rows;
	// cols -> width -> x
	int nCols = inputMat.cols;

	// create the integral image
	cv::Mat sumMat;
	cv::integral(inputMat, sumMat);

	CV_Assert(sumMat.depth() == CV_32S);
	CV_Assert(sizeof(int) == 4);

	int S = 10;// MAX(nRows, nCols) / 8;
	double T = 0.15;

	// perform thresholding
	int s2 = S / 2;
	int x1, y1, x2, y2, count, sum;

	// CV_Assert(sizeof(int) == 4);
	int* p_y1, * p_y2;
	uchar* p_inputMat, * p_outputMat;

	for (int i = 0; i < nRows; ++i)
	{
		y1 = i - s2;
		y2 = i + s2;

		if (y1 < 0)
		{
			y1 = 0;
		}
		if (y2 >= nRows)
		{
			y2 = nRows - 1;
		}

		y1++;
		y2++;

		p_y1 = sumMat.ptr<int>(y1);
		p_y2 = sumMat.ptr<int>(y2);
		p_inputMat = inputMat.ptr<uchar>(i);
		p_outputMat = outputMat.ptr<uchar>(i);

		for (int j = 0; j < nCols; ++j)
		{
			// set the SxS region
			x1 = j - s2;
			x2 = j + s2;

			if (x1 < 0)
			{
				x1 = 0;
			}
			if (x2 >= nCols)
			{
				x2 = nCols - 1;
			}

			x1++;
			x2++;

			count = (x2 - x1) * (y2 - y1);

			// I(x,y)=s(x2,y2)-s(x1,y2)-s(x2,y1)+s(x1,x1)
			sum = p_y2[x2] - p_y1[x2] - p_y2[x1] + p_y1[x1];

			if ((int)(p_inputMat[j] * count) < (int)(sum * (1.0 - T)))
				p_outputMat[j] = 255;
			else
				p_outputMat[j] = 0;
		}
	}
}

int main()
{
	//image path
	string fileDir = "D:\\Pub\\KCCImageNet\\Willie";
	//vector<string> filelist;
	//for (const auto& entry : fs::directory_iterator(fileDir)) {
	//	//std::cout << entry.path().string() << std::endl;
	//	if (entry.is_regular_file() && entry.path().extension() == ".jpg" ||
	//		entry.is_regular_file() && entry.path().extension() == ".png")
	//		filelist.push_back(entry.path().string());
	//}

	//for (const std::string& filePath : filelist) 
	{
		//std::cout << filePath << std::endl;
		string fileDir = "D:\\Pub\\KCCImageNet\\Willie\\";
		//string fileName = "wafer_dies.png";
		string fileName_Search = "Willie.jpg";
		string fileName_Pattern = "me.jpg";

		const string& filePath = fileDir + fileName_Search;
		Mat search_img = cv::imread(filePath, cv::ImreadModes::IMREAD_ANYCOLOR);
		Mat draw_color = search_img.clone();

		const string& filePath_ptrn = fileDir + fileName_Pattern;
		Mat pattern_img = cv::imread(filePath_ptrn, cv::ImreadModes::IMREAD_ANYCOLOR);


		Mat search_gray_img, pattern_gray_img;
		cvtColor(search_img, search_gray_img, ColorConversionCodes::COLOR_BGR2GRAY);
		cvtColor(pattern_img, pattern_gray_img, ColorConversionCodes::COLOR_BGR2GRAY);
		
		//image whole
		// 템플릿 매칭 수행
		cv::Mat result;
		cv::matchTemplate(search_gray_img, pattern_gray_img, result, cv::TM_CCOEFF_NORMED);

		// 매칭 결과를 정규화하여 최대값 위치 찾기
		double minVal, maxVal;
		cv::Point minLoc, maxLoc;
		cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

		double threshold_matching = 0.8;
		Mat result_areas;
		threshold(result, result_areas, threshold_matching, 255, ThresholdTypes::THRESH_BINARY);
		result_areas.convertTo(result_areas, CV_8UC1);
		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;
		cv::findContours(result_areas, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

		RNG rng(12345);
		for (size_t i = 0; i < contours.size(); i++)
		{
			Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
			cv::Rect rt = cv::boundingRect(contours[i]);
			cv::drawMarker(draw_color, rt.tl(), Scalar(255, 255, 255), MarkerTypes::MARKER_CROSS);
			cv::rectangle(draw_color, Rect(rt.x, rt.y, pattern_gray_img.cols, pattern_gray_img.rows), color, 1);

		}
		return 1;


	}

	return 1;

}
