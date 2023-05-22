#include "../Common/Common.h"

void Convert_BGR2Gray(uchar* pDataBRG, size_t& w, size_t& h, uchar* pY)
{
	/*
	Y = 0.299R+0.587G+0.114B
	Color를 Gray를 변환하시오.
	*/
	for (size_t row = 0; row < h; row++)
	{
		for (size_t col = 0; col < h; col++)
		{
			int index = row * w + col;
			index *= 3;
			int b = pDataBRG[index + 0];
			int g = pDataBRG[index + 1];
			int r = pDataBRG[index + 2];
			int band_index = row * w + col;
			pY[band_index] = 0.299 * r + 0.587 * g + 0.114 * b;
		}
	}
}

void Get_Histogram(uchar* pDataGray, size_t& length, int* pHisto)
{
	for (size_t i = 0; i < length; i++)
	{
		pHisto[pDataGray[i]]++;
	}
}

void Get_Accumulated(int* histo, int histoSz, int* acc)
{
	cout << "getAccumulated acc is " << acc << endl;
	cout << "getAccumulated acc value is " << *acc << endl;
	cout << "getAccumulated histo addr is " << histo << endl;
	for (size_t i = 1; i < histoSz; i++) { acc[i] = acc[i - 1] + histo[i]; }
	
	/*
	for (int i = 0; i < length; i++)
	{
		//*acc += histo[i];
	}
	*/
	cout << "getAccumulated acc value is " << *acc << endl;
}

void main()
{
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "lena.jpg";
	Mat color_img = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);

	uchar* pDataColor = color_img.data;
	size_t width = color_img.cols;
	size_t height = color_img.rows;

	// #1.Convert Color To Gray
	Mat gray_img = Mat::zeros(height, width, CV_8UC1);
	Mat gray_img_histoEq = Mat::zeros(height, width, CV_8UC1);
	uchar* pDataGray = color_img.data;
	Convert_BGR2Gray(pDataColor, width, height, pDataGray);

	// #2. Get Histogram
	int histo[256] = { 0, };
	size_t length = width * height;
	Get_Histogram(pDataGray, length, histo);

	// #3. Get Accumulated P:  확률 밀도 함수
	const int histoSz = 256;
	int acc[histoSz] = {0, };
	acc[0] = histo[0];
	Get_Accumulated(histo, 256, acc);

	// #4. 영상의 각 화소 값들로부터 대응화소값으로의 매핑
	int new_gray[histoSz] = { 0, };
	size_t N = length;											 //밝기 최대값 / 전체크기
	for (size_t i = 0; i < histoSz; i++) { new_gray[i] = 1.0 * (acc[i] * 255) / N; }
	for (size_t i = 0; i < N; i++) { gray_img_histoEq.data[i] = new_gray[gray_img.data[i]]; }

	int histo_new[histoSz] = { 0, };
	Get_Histogram(gray_img_histoEq.data, length, histo_new);
	std::ofstream ofile("histogram_eq.csv");

	std::string str = "";
	if (ofile.is_open())
	{
		for (size_t i = 0; i < histoSz; i++)
		{
			str = std::format("{}, {}, {}\n", i, histo[i], histo_new[i]); // C++ 20 std::foramt
			ofile << str;
		}
		ofile.close();
	}

		//Mat gray_img, 
		Mat gray_img_eq;
		cvtColor(color_img, gray_img, COLOR_BGR2GRAY);
		cv::equalizeHist(gray_img, gray_img_eq);
		int a = 0;
	
		// equalizeHist() 라이브러리랑 raw코드랑 얼마나 다른지 비교
		Mat diff = gray_img_eq - gray_img_histoEq;
		Scalar sum = cv::sum(diff);

	int  z = 4;
	return;
}