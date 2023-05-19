
#include "../Common/Common.h"
#include <opencv2/opencv.hpp>
// 외부 라이브러리를 추가하는 방법
int main()
{
    std::cout << "Hello OpenCV" << endl;

    cv::Mat img;

    img = cv::imread("jetson.bmp");

    if (img.empty())
    {
        std::cerr << "Image load failed!" << std::endl;

        return -1;
    }

 // cv::namedWindow("image");
    cv::imshow("imagssse", img);

    cv::waitKey();

    int z = 3;

    return 0;
}
