#include "../Common/Common.h"

void contours_basic()
{
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "shapes.jpg";
	Mat src = imread(fileName, IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed!" << endl;
		return;
	}


	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(src, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int i = 0; i < contours.size(); i++)
	{
		Scalar c(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, i, c, 2);
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