
#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <fstream> // ofstream header
#include <format>

using namespace std;

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

#ifdef OPENCV_470
	#include <openvc2/opencv.hpp>
	#include <openvc2/imgproc/imgproc_c.h>
	#include <openvc2/imgproc/types_c.h>
#endif //OPENCV_470

#ifdef _Debug
	#pragma comment(lib, "opencv_world470d.lib")
#else // RELEASE
	#pragma comment(lib, "opencv_world470d.lib")
#endif

using namespace std;
using namespace cv;

// add/lib