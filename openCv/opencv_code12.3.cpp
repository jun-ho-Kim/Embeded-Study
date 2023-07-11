#include "../Common/Common.h"

void contours_basic()
{
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "contours2.png";
	Mat src = imread(fileName, IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed!" << endl;
		return;
	}


	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(src, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int i = 0; i < contours.size(); i++)
	{
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, i, c, 2);
	}

	for (int idx = 0; idx >= 0; idx = hierarchy[idx][0])
	{
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, idx, c, -1, LINE_8, hierarchy);
	}

	imshow("src", src);
	imshow("dst", dst);

	

	waitKey();
	destroyAllWindows();
}

int main()
{
	contours_basic();
}