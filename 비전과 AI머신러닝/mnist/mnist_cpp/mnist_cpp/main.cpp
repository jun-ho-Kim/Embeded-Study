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
    ReadMNIST(10000, 784, ai);                // �Ʒõ����͸� �ҷ���
    ReadMNISTLabel(al);                       // ���̺��� �о� ��

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
void ReadMNIST(int NumberOfImages, int DataOfAnImage, vector<vector<double>>& arr)   // MNIST�����͸� �о�´�.
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

void ReadMNISTLabel(vector<unsigned char>& arr) {                // ���̺��� �о�´�.
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

        //ifstream::read(str, count)�� count��ŭ �о� str�� ����
        //char�� 1����Ʈ, int�� 4����Ʈ�̹Ƿ� int 1���� char 4���� ������ŭ ������
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
                    //magicnumber���� ���� Ÿ�� ������ unsigned byte �� ���
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

        //ifstream::read(str, count)�� count��ŭ �о� str�� ����
        //char�� 1����Ʈ, int�� 4����Ʈ�̹Ƿ� int 1���� char 4���� ������ŭ ������
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = ReverseInt(magic_number);
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = ReverseInt(number_of_images);
        if (readDataNum > number_of_images || readDataNum <= 0)
            readDataNum = number_of_images;

        for (int i = 0; i < readDataNum; ++i)
        {
            //magicnumber���� ���� Ÿ�� ������ unsigned byte �� ���
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
    magicNumber = (magicNumber >> 8) & 255; //3��° ����Ʈ(�ȼ� Ÿ��)�� ��������
    //��Ʋ ����� CPU���� magicNumber = ((char*)&magicNumber)[1];�� ����
    //�� ����� CPU���� magicNumber = ((char*)&magicNumber)[2];�� ����

    switch (magicNumber) {
    case 0x08: return CV_8UC1;//unsigned byte, ��� ä�� ����
    case 0x09: return CV_8SC1;//signed byte, ��� ä�� ����
    case 0x0B: return CV_16SC1;//short(2 ����Ʈ), ��� ä�� ����
    case 0x0C: return CV_32SC1;//int(4 ����Ʈ), ��� ä�� ����
    case 0x0D: return CV_32FC1;//float(4 ����Ʈ), ��� ä�� ����
    case 0x0E: return CV_64FC1;//double(8 ����Ʈ), ��� ä�� ����
    default: return CV_8UC1;
    }
}


void MatPrint(std::vector<cv::Mat>& trainingVec, std::vector<cv::uint8_t>& labelVec)
{
    std::cout << "�о�� �Ʒ� ������ �� : " << trainingVec.size() << std::endl;
    std::cout << "�о�� ���� ������ �� : " << labelVec.size() << std::endl;

    cv::namedWindow("Window", cv::WINDOW_AUTOSIZE);

    for (int i = 0; i < labelVec.size() && i < trainingVec.size(); i++) {
        imshow("Window", trainingVec[i]);
        std::cout << i << "��° �̹��� ���� : " << (int)labelVec[i] << std::endl;
        //�ƹ� Ű�� ������ ����
        if (cv::waitKey(0) != -1)
            continue;
    }
}