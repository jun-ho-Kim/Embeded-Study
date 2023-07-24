#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "D:/VisionAI/codes/Common/Common.h"

using namespace std;
int ReverseInt(int i);
void ReadMNIST(int NumberOfImages, int DataOfAnImage, vector<vector<double>>& arr);
void ReadMNISTLabel(vector<unsigned char>& arr);

void MnistTrainingDataRead(std::string filePath, std::vector<cv::Mat>& vec, int readDataNum);
void MnistLabelDataRead(std::string filePath, std::vector<uint8_t>& vec, int readDataNum);
int ConvertCVGrayImageType(int magicNumber);
void MatPrint(std::vector<cv::Mat>& trainingVec, std::vector<cv::uint8_t>& labelVec);

int main()
{
    vector<vector<double>> ai;
    vector<unsigned char> al;
    ReadMNIST(10000, 784, ai);                // 훈련데이터를 불러옴
    ReadMNISTLabel(al);                       // 레이블을 읽어 옴

    printf("label is %d", ai[0]);

              
    for (int i = 0; i < 784; i++)
    {
        if (i % 28 == 0)
            printf("\n");
        printf("%4.0f ", ai[0][i]);

    }
    printf("\n");
    std::vector<cv::Mat> trainingVec;
    //std::vector<uchar> labelVec;

    MnistTrainingDataRead("train-images-idx3-ubyte", trainingVec, 10);
    //MnistLabelDataRead("train-images-idx3-ubyte", labelVec, 10);
    //MatPrint(trainingVec, labelVec);

    Mat test = trainingVec[1];
    Mat test_bin;
    threshold(test, test_bin, 50, 255, THRESH_BINARY);

    Mat im_floodfill = test_bin.clone();
    floodFill(im_floodfill, cv::Point(0, 0), Scalar(255));
    Mat im_floodfill_inv;
    bitwise_not(im_floodfill, im_floodfill_inv);
    Mat detect_img_R_fill = (test_bin | im_floodfill_inv);




    return 0;
}


int ReverseInt(int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1 = i & 255;
    ch2 = (i >> 8) & 255;
    ch3 = (i >> 16) & 255;
    ch4 = (i >> 24) & 255;
    return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}
void ReadMNIST(int NumberOfImages, int DataOfAnImage, vector<vector<double>>& arr)   // MNIST데이터를 읽어온다.
{
    arr.resize(NumberOfImages, vector<double>(DataOfAnImage));
    ifstream file("train-images-idx3-ubyte", ios::binary);
    if (file.is_open())
    {
        int magic_number = 0;
        int number_of_images = 0;
        int n_rows = 0;
        int n_cols = 0;

        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);
        file.read((char*)&n_rows, sizeof(n_rows));
        n_rows = ReverseInt(n_rows);
        file.read((char*)&n_cols, sizeof(n_cols));
        n_cols = ReverseInt(n_cols);

        char inputstring[1000];
        for (int i = 0; i < 10000; ++i)
        {
            for (int r = 0; r < n_rows; ++r)
            {

                for (int c = 0; c < n_cols; ++c)
                {
                    unsigned char temp = 0;
                    file.read((char*)&temp, sizeof(temp));
                    arr[i][(n_rows * r) + c] = (double)temp;
                }
            }
        }
    }
}

void ReadMNISTLabel(vector<unsigned char>& arr) {                // 레이블을 읽어온다.
    ifstream file("train-images-idx3-ubyte");
    for (int i = 0; i < 10000; ++i)
    {
        unsigned char temp = 0;
        file.read((char*)&temp, sizeof(temp));
        if (i > 7)
            arr.push_back((unsigned char)temp);

    }
}

void MnistTrainingDataRead(std::string filePath, std::vector<cv::Mat>& vec, int readDataNum)
{
    std::ifstream file(filePath, std::ios::binary);
    if (file.is_open())
    {
        int magic_number = 0;
        int number_of_images = 0;
        int n_rows = 0;
        int n_cols = 0;

        //ifstream::read(str, count)로 count만큼 읽어 str에 저장
        //char은 1바이트, int는 4바이트이므로 int 1개당 char 4개의 정보만큼 가져옴
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);
        file.read((char*)&n_rows, sizeof(n_rows));
        n_rows = ReverseInt(n_rows);
        file.read((char*)&n_cols, sizeof(n_cols));
        n_cols = ReverseInt(n_cols);

        if (readDataNum > number_of_images || readDataNum <= 0)
            readDataNum = number_of_images;

        for (int i = 0; i < readDataNum; ++i)
        {
            cv::Mat tp = cv::Mat::zeros(n_rows, n_cols, ConvertCVGrayImageType(magic_number));
            for (int r = 0; r < n_rows; ++r)
            {
                for (int c = 0; c < n_cols; ++c)
                {
                    //magicnumber에서 얻은 타입 정보가 unsigned byte 일 경우
                    if (ConvertCVGrayImageType(magic_number) == CV_8UC1) {
                        unsigned char temp = 0;
                        file.read((char*)&temp, sizeof(temp));
                        tp.at<uchar>(r, c) = (int)temp;
                    }
                }
            }
            vec.push_back(tp);
        }
    }
}

void MnistLabelDataRead(std::string filePath, std::vector<uint8_t>& vec, int readDataNum)
{
    std::ifstream file(filePath, std::ios::binary);
    if (file.is_open())
    {
        int magic_number = 0;
        int number_of_images = 0;

        //ifstream::read(str, count)로 count만큼 읽어 str에 저장
        //char은 1바이트, int는 4바이트이므로 int 1개당 char 4개의 정보만큼 가져옴
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);
        if (readDataNum > number_of_images || readDataNum <= 0)
            readDataNum = number_of_images;

        for (int i = 0; i < readDataNum; ++i)
        {
            //magicnumber에서 얻은 타입 정보가 unsigned byte 일 경우
            if (ConvertCVGrayImageType(magic_number) == CV_8UC1) {
                uint8_t temp = 0;
                file.read((char*)&temp, sizeof(temp));
                vec.push_back(temp);
            }
        }
    }
}

int ConvertCVGrayImageType(int magicNumber)
{
    magicNumber = (magicNumber >> 8) & 255; //3번째 바이트(픽셀 타입)만 가져오기
    //리틀 엔디안 CPU에서 magicNumber = ((char*)&magicNumber)[1];와 같음
    //빅 엔디안 CPU에서 magicNumber = ((char*)&magicNumber)[2];와 같음

    switch (magicNumber) {
    case 0x08: return CV_8UC1;//unsigned byte, 흑백 채널 단일
    case 0x09: return CV_8SC1;//signed byte, 흑백 채널 단일
    case 0x0B: return CV_16SC1;//short(2 바이트), 흑백 채널 단일
    case 0x0C: return CV_32SC1;//int(4 바이트), 흑백 채널 단일
    case 0x0D: return CV_32FC1;//float(4 바이트), 흑백 채널 단일
    case 0x0E: return CV_64FC1;//double(8 바이트), 흑백 채널 단일
    default: return CV_8UC1;
    }
}


void MatPrint(std::vector<cv::Mat>& trainingVec, std::vector<cv::uint8_t>& labelVec)
{
    std::cout << "읽어온 훈련 데이터 수 : " << trainingVec.size() << std::endl;
    std::cout << "읽어온 정답 데이터 수 : " << labelVec.size() << std::endl;

    cv::namedWindow("Window", cv::WINDOW_AUTOSIZE);

    for (int i = 0; i < labelVec.size() && i < trainingVec.size(); i++) {
        imshow("Window", trainingVec[i]);
        std::cout << i << "번째 이미지 정답 : " << (int)labelVec[i] << std::endl;
        //아무 키나 누르면 다음
        if (cv::waitKey(0) != -1)
            continue;
    }
}