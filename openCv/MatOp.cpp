#include "../Common/Common.h"
#include <opencv2/opencv.hpp>
// 외부 라이브러리를 추가하는 방법

void MatOp1()
{
	Mat img1; // empty matrix

	Mat img2(480, 640, CV_8UC1); // unsigned char, 1-channel
	Mat img3(480, 640, CV_8UC3); // unsigned char, 3-channel
	Mat img4(Size(640, 480), CV_8UC3); // Size(width, heigth)

	Mat img5(480, 640, CV_8UC1, Scalar(128)); // initial values, 128
	Mat img6(480, 640, CV_8UC3, Scalar(0,0,255)); // initial values, red
	
	Mat mat1 = Mat::zeros(3, 3, CV_32SC1); // 0`s matrix
	Mat mat2 = Mat::ones(3, 3, CV_32FC1); // 1`s matrix
	Mat mat3 = Mat::eye(3, 3, CV_32FC1);  // identity matrix

	float data[] = { 1,2,3,4,5,6 };
	Mat mat4(2, 3, CV_32FC1, data);

	//Mat mat5(Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	//Mat mat6(Mat_<uchar>{2, 3}, { 1, 2, 3, 4, 5, 6 });

	cout << "mat4_1 address is" << &mat4 << endl;

	mat4.create(256, 256, CV_8UC3);

	cout << "mat4_2 address is" << &mat4 << endl;

	Mat mat5 = (Mat_<float>(2,3) << 1,2,3,4,5,6);
	Mat mat6 = Mat_<uchar>({ 2, 3 }, { 1, 2, 3, 4, 5, 6 });
}



int main()
{
	MatOp1();
}