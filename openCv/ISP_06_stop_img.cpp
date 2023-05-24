#include "../Common/Common.h"
#include "ISP.h"

const int max_value_H = 360 / 2;
const int max_value = 255;
const String window_capture_name = "Video Capture";
const String window_detection_name = "Object Detection";
int low_H = 0, low_S = 0, low_V = 0;
int high_H = max_value_H, high_S = max_value, high_V = max_value;
static void on_low_H_thresh_trackbar(int, void*)
{
	low_H = min(high_H - 1, low_H);
	setTrackbarPos("Low H", window_detection_name, low_H);
}
static void on_high_H_thresh_trackbar(int, void*)
{
	high_H = max(high_H, low_H + 1);
	setTrackbarPos("High H", window_detection_name, high_H);
}
static void on_low_S_thresh_trackbar(int, void*)
{
	low_S = min(high_S - 1, low_S);
	setTrackbarPos("Low S", window_detection_name, low_S);
}
static void on_high_S_thresh_trackbar(int, void*)
{
	high_S = max(high_S, low_S + 1);
	setTrackbarPos("High S", window_detection_name, high_S);
}
static void on_low_V_thresh_trackbar(int, void*)
{
	low_V = min(high_V - 1, low_V);
	setTrackbarPos("Low V", window_detection_name, low_V);
}
static void on_high_V_thresh_trackbar(int, void*)
{
	high_V = max(high_V, low_V + 1);
	setTrackbarPos("High V", window_detection_name, high_V);
}

int main1()
{

	namedWindow(window_capture_name);
	namedWindow(window_detection_name);
	resizeWindow(window_detection_name, Size(1280, 1024));


	// Trackbars to set thresholds for HSV values
	createTrackbar("Low H", window_detection_name, &low_H, max_value_H, on_low_H_thresh_trackbar);
	createTrackbar("High H", window_detection_name, &high_H, max_value_H, on_high_H_thresh_trackbar);
	createTrackbar("Low S", window_detection_name, &low_S, max_value, on_low_S_thresh_trackbar);
	createTrackbar("High S", window_detection_name, &high_S, max_value, on_high_S_thresh_trackbar);
	createTrackbar("Low V", window_detection_name, &low_V, max_value, on_low_V_thresh_trackbar);
	createTrackbar("High V", window_detection_name, &high_V, max_value, on_high_V_thresh_trackbar);
	Mat frame, frame_HSV, frame_threshold;
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "stop_img.png";
	frame = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	while (true) {

		if (frame.empty())
		{
			break;
		}
		// Convert from BGR to HSV colorspace
		cvtColor(frame, frame_HSV, COLOR_BGR2HSV);
		// Detect the object based on HSV Range Values
		inRange(frame_HSV, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), frame_threshold);
		// Show the frames
		imshow(window_capture_name, frame);
		imshow(window_detection_name, frame_threshold);
		char key = (char)waitKey(30);
		if (key == 'q' || key == 27)
		{
			break;
		}
	}
	return 0;
}

int main()
{
	main1();
	ISP _isp;
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "stop_img.png";
	Mat src_color = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);

	Mat src_HSV;
	cvtColor(src_color, src_HSV, COLOR_BGR2HSV);// 새로운 이미지에 대해 메모리 생성을 해줌

	//int low_H = 175;
	int low_H = 120;
	int high_H = 180;
	int low_S = 0;
	int high_S = 255;
	int low_V = 0;
	int hight_V = 255;

	Scalar lower_R(low_H, low_S, low_V);
	Scalar high_R(high_H, high_S, hight_V);

	Mat detect_img_R;
	inRange(src_HSV, lower_R, high_R, detect_img_R);


	RNG rng(12345);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(detect_img_R, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

	Mat reduced_R = src_color.clone();
	cvtColor(detect_img_R, detect_img_R, COLOR_GRAY2BGR);
	bitwise_and(src_color, detect_img_R, reduced_R);

	int max_index = 0;
	double max_length = 0;


	for (size_t i = 0; i < contours.size(); i++)
	{
		if (contours[i].size() < 200) continue;

	double length = cv::arcLength(contours[i], false);
	double area = cv::contourArea(contours[i]);
	RotatedRect rt = cv::minAreaRect(contours[i]);

	//if (contours[i].size() < 5) continue;
	Point2f center(0, 0);
	float radius = 0;
	RotatedRect ellipse = cv::fitEllipse(contours[i]);
	
	cout << "contours[i] " << i <<  "is " << contours[i];
	cout << "contours[i] type is " << typeid(contours[i]).name();
	//contours[i] type is class std::vector<class cv::Point_<int>,class std::allocator<class cv::Point_<int> > >
	//for (int i = 0; i < contours[i].size(); i++)
	//{
	//	contours[i].data
	//}

	
	cout << endl;


	Point2f rowLine(47, 109);
	Point2f rowLine2(181, 109);

	Point2f colLine(115, 45);
	Point2f colLine2(115, 183);

	cv::rectangle(src_color, rt.boundingRect(), Scalar(255, 0, 255));
	cv::line(src_color, rowLine, rowLine2, Scalar(153, 255, 255), 3);
	cv::line(src_color, colLine, colLine2, Scalar(153, 255, 255), 3);
	int z = 1;
	}

}