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
	string fileName = fileDir + "find_google_area.png";
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
	//main1();
	//TODO: ��ó���� ���콺 ����
	ISP _isp;
	string fileDir = "../thirdparty/opencv_470/sources/samples/data/";
	string fileName = fileDir + "find_google_area.png";
	Mat src_color = cv::imread(fileName, cv::ImreadModes::IMREAD_COLOR);
	
	// Blur ó��
	Mat src_color_blur;
	//blur(src_color, src_color_blur, Size());
	
	Mat src_HSV;
	cvtColor(src_color, src_HSV, COLOR_BGR2HSV);
	//cvtColor(src_color, src_HSV, COLOR_BGR2HSV);// ���ο� �̹����� ���� �޸� ������ ����

	int low_H = 0;
	int high_H = 180;
	int low_S = 130;
	int high_S = 250;
	int low_V = 55;
	int hight_V = 255;

	Scalar lower_R(low_H, low_S, low_V);
	Scalar high_R(high_H, high_S, hight_V);

	Mat detect_img_G;
	inRange(src_HSV, lower_R, high_R, detect_img_G);
	
	// Invert floodfiiled image
	// character���� �ش��ϴ� ������ ���(���� O �ȿ� o�� �ɷ���
	Mat im_floodfill = detect_img_G.clone();
	floodFill(im_floodfill, cv::Point(0, 0), Scalar(255));
	Mat im_floodfill_inv;
	bitwise_not(im_floodfill, im_floodfill_inv);
	Mat detect_img_R_fill = (detect_img_G | im_floodfill_inv);

	RNG rng(12345);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(detect_img_R_fill, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

	Mat reduced_R = src_color.clone();
	cvtColor(detect_img_G, detect_img_G, COLOR_GRAY2BGR);
	bitwise_and(src_color, detect_img_G, reduced_R);
	
	int txt_index = 0;
	int length_spec = 130;
	vector<Rect> vCharROI;
	for (int i = 0; i < contours.size(); i++)
	{
		double area = cv::contourArea(contours[i]);
		double length = cv::arcLength(contours[i],false);
		if (area < 10) continue;
		if (length < length_spec) continue;

		// text �����
		// ������ �ڵ�
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));

		drawContours(src_color, contours, (int)i, color, 1, LINE_8, hierarchy, 0);

		RotatedRect rt = cv::minAreaRect(contours[i]);

		string msg = std::format("[{}]", i);

		putText(src_color, msg, rt.boundingRect().tl(), HersheyFonts::FONT_HERSHEY_SIMPLEX, 0.4, Scalar(255, 0, 255), 1);

		// �ܵ� ���� �и��ϱ� ���ؼ� ���İ��� ���ϱ�

		msg = std::format("[{}] A {} -L {}", i, (int)area, (int)length);

		putText(src_color, msg, Point(10, 50+txt_index*20), HersheyFonts::FONT_HERSHEY_SIMPLEX, 0.4, Scalar(255, 0, 255), 1);
		txt_index++;
		vCharROI.push_back(rt.boundingRect());
	}

	for (size_t i = 0; i < vCharROI.size(); i++)
	{
		cv::rectangle(src_color, vCharROI[i], Scalar(0, 0, 255));
	}

	/*
	for (int i = 0; i < contours.size(); i++)
	{
		if (contours[i].size() < 50) continue;

		double length = cv::arcLength(contours[i], false);
		double area = cv::contourArea(contours[i]);
		RotatedRect rt = cv::minAreaRect(contours[i]);
		cv::rectangle(reduced_R, rt.boundingRect(), Scalar(255, 0, 255));
	}
	*/
	int z = 3;
}