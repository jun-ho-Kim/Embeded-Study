#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <string>
#include "D:/VisionAI/codes/Common/Common.h"

namespace fs = std::filesystem;

int ReverseInt(int i);
void ReadMNIST(int NumberOfImages, int DataOfAnImage, vector<vector<double>>& arr);
void ReadMNISTLabel(vector<unsigned char>& arr);

int resize_img(Mat& src, Mat& dst, Mat& resize_img);
void MnistTrainingDataRead(std::string filePath, std::vector<cv::Mat>& vec, int readDataNum);
void MnistLabelDataRead(std::string filePath, std::vector<uint8_t>& vec, int readDataNum);
int ConvertCVGrayImageType(int magicNumber);
void MatPrint(std::vector<cv::Mat>& trainingVec, std::vector<cv::uint8_t>& labelVec);


// https://studyfield.tistory.com/659
// https://givemesource.tistory.com/1?category=681642
int main()
{
    
    string fileDir = "D:/Image 모음/MNIST Dataset JPG format/MNIST - JPG - training/";
    int i;
  
    vector<string> filelist[10];

    for (int i = 0; i < 10; i++)
    {
        char tmp[5];
        _itoa_s(i, tmp, 10);
        string fileName = (fileDir + tmp + "/");
        printf("fileName is %s ", fileName);
        for (const auto& entry : fs::directory_iterator(fileName))
        {
            if (entry.is_regular_file() && entry.path().extension() == ".jpg" ||
                entry.is_regular_file() && entry.path().extension() == ".png")
                filelist[i].push_back(entry.path().string());
        }
    }

    fileDir = "D:/Image 모음/MNIST Dataset JPG format/MNIST - JPG - testing/8/";
    string fileName = fileDir + "61.jpg";

    int idx_max_arr[10] = { 0, };
    int test_result_arr[10] = { 0, };
    int max_count = 0;


    // 성공률 처리 알고리즘 작성하기
    string test_fileDir = "D:/Image 모음/MNIST Dataset JPG format/MNIST - JPG - testing/";
    vector<string> test_filelist[10];

    for (int i = 0; i < 10; i++)
    {
        char tmp[5];
        _itoa_s(i, tmp, 10);
        string fileName = (test_fileDir + tmp + "/");
        printf("test fileName is %s ", fileName);
        for (const auto& entry : fs::directory_iterator(fileName))
        {
            if (entry.is_regular_file() && entry.path().extension() == ".jpg" ||
                entry.is_regular_file() && entry.path().extension() == ".png")
                test_filelist[i].push_back(entry.path().string());
        }
    }

    Mat test_img = imread(fileName, IMREAD_GRAYSCALE);
    //Mat test_bin;
    //threshold(test_img, test_bin, 50, 255, THRESH_BINARY);
    //Mat test_dst;
    //Mat test_resize_img(50, 50, CV_8UC1);
    //resize_img(test_bin, test_dst, test_resize_img);

    for (int i = 0; i < 10; i++)
    {
        printf("test_filelist[%d] is %d\n", i, test_filelist[i].size());
    }
    Mat test_dst;
    Mat test_resize_img(28, 28, CV_8UC1);
    Mat test_bin;

    Mat ori_bin;
    Mat ori_dst;
    Mat ori_resize_img(28, 28, CV_8UC1);

   // 테스트 이미지//////////////////
for (int test_i =5; test_i < 10; test_i++)
{
    for (int test_j = 0; test_j < test_filelist[test_i].size(); test_j++)
    {
        //int test_data = test_resize_img.data[int(row * 50 + col)];
        Mat test_img = imread(test_filelist[test_i][test_j], IMREAD_GRAYSCALE);

        threshold(test_img, test_bin, 50, 255, THRESH_BINARY);

        resize_img(test_bin, test_dst, test_resize_img);
        for (int i = 0; i < 10; i++)
        {
            //printf("i is %d\n", i);
            int* match_arr = new int[filelist[i].size()]{ 0, };
            max_count = 0;
            for (int j = 0; j < filelist[i].size(); j++)
            {
                //printf("j is %d\n", j);
                Mat ori_data = imread(filelist[i][j], IMREAD_GRAYSCALE);

                threshold(ori_data, ori_bin, 50, 255, THRESH_BINARY);
                resize_img(ori_bin, ori_dst, ori_resize_img);
                //Mat ori_bin;
                //threshold(ori_data, ori_bin, 50, 255, THRESH_BINARY);
                //Mat ori_dst;
                //Mat ori_resize_img(50, 50, CV_8UC1);
                //resize_img(ori_bin, ori_dst, ori_resize_img);
                for (size_t row = 0; row < 28; row++)
                {
                    //printf("row is %d\n", row);
                    for (size_t col = 0; col < 28; col++)
                    {
                        //printf("col is %d\n", col);
                        if ((bool(ori_resize_img.data[row * 28 + col]) == true) && (bool(test_resize_img.data[row * 28 + col]) == true))
                        {
                            match_arr[j]++;
                            //idx_max_arr[i]++;
                        }
                    }
                }

                if (max_count < match_arr[j])
                {
                    max_count = match_arr[j];
                }
                //idx_max_arr[i] = idx_max_arr[i] / filelist[i].size();
            }

            delete[]match_arr;
            idx_max_arr[i] = max_count;
            int z = 10;
        }
        // 성공률 처리 알고리즘 작성하기
        int max_value = 0;
        int max_idx = 0;
        for (int now_idx = 0; now_idx < 10; now_idx++)
        {
            if (max_value < idx_max_arr[now_idx])
            {
                max_value = idx_max_arr[now_idx];
                max_idx = now_idx;
            }
        }

        test_result_arr[max_idx]++;

        printf("tset_i %d, test_j %d end\n", test_i, test_j);
    }
 }
 

    //string fileDir = "D:/Image 모음/MNIST Dataset JPG format/MNIST - JPG - training/";
    //Mat ori_bin;

    //Mat ori_img = imread(fileName, IMREAD_GRAYSCALE);


    int arr_num[10] = { 0, };

    vector<vector<double>> ai;
    vector<unsigned char> al;
    ReadMNIST(10000, 784, ai);                // 훈련데이터를 불러옴
    ReadMNISTLabel(al);                       // 레이블을 읽어 옴

    //string fileDir = "D:/0.수업코드/비전과 AI머신러닝/mnist/";
    //string fileName = fileDir + "61.jpg";


    Mat test = imread(fileName, IMREAD_GRAYSCALE);
    //Mat test_bin;
    threshold(test, test_bin, 50, 255, THRESH_BINARY);

    string fileName_arr[10] = { "", };
    //int i = 0;

    fileDir = "D:/0.수업코드/비전과 AI머신러닝/mnist/origin_Img/";

    for (i = 0; i < 10; i++)
    {
        char tmp[5];
        _itoa_s(i, tmp, 10);
        string fileName = (fileDir + tmp + ".jpg");
        fileName_arr[i] = fileName;
    }
    int z = 3;

    for (i = 0; i < 10; i++)
    {
        Mat ori_img = imread(fileName_arr[i], IMREAD_GRAYSCALE);

        printf("label is %d", ai[0]);

        //for (int i = 0; i < 784; i++)
        //{
        //    if (i % 28 == 0)
        //        printf("\n");
        //    printf("%4.0f ", ai[0][i]);

        //}
        printf("\n");
        std::vector<cv::Mat> trainingVec;
        //std::vector<uchar> labelVec;q
        

        //MnistTrainingDataRead("train-images-idx3-ubyte", trainingVec, 10);
        //MnistLabelDataRead("train-images-idx3-ubyte", labelVec, 10);
        //MatPrint(trainingVec, labelVec);

        //Mat test = trainingVec[9]; 4


        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;

        Mat draw_img = test.clone();
        cvtColor(test, draw_img, COLOR_GRAY2BGR);

        Mat test_dst;
        Mat test_resize_img(50, 50, CV_8UC1);
        Mat test_add_img(50, 50, CV_8UC1);

        resize_img(test_bin, test_dst, test_resize_img);

        Mat ori_bin;
        threshold(ori_img, ori_bin, 50, 255, THRESH_BINARY);
        Mat ori_dst;
        Mat ori_resize_img(50, 50, CV_8UC1);
        resize_img(ori_bin, ori_dst, ori_resize_img); 

        test_add_img.push_back(ori_resize_img);

        for (size_t row = 0; row < 50; row++)
            for (size_t col = 0; col < 50; col++)
            {
                int ori_data = ori_resize_img.data[int(row * 50 + col)];
                int test_data = test_resize_img.data[int(row * 50 + col)];
                if ((bool(ori_data) ==true) && (bool(test_data) == true))
                {
                    arr_num[i] ++;
                }
            }

        /*
        RNG rng(12345);
        Rect roi;
        findContours(test, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

        RotatedRect ellipse = cv::fitEllipse(contours[0]);
        Mat dst;
        if (ellipse.angle < 90)
        {
            Mat M =  getRotationMatrix2D(ellipse.center, ellipse.angle ,1);
            warpAffine(test_bin, dst, M, Size());
        }
        else
            dst = test.clone();

        threshold(dst, dst, 50, 255, THRESH_BINARY);
        //Mat mat1 = Mat::ones(3, 3, CV_8UC1);
        //Mat erode_mat;
        //erode(dst, erode_mat, mat1);
        //Mat dilate_mat;
        //dilate(erode_mat, dst, mat1);

        findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
        roi = cv::boundingRect(contours[0]);
        Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
        //drawContours(draw_img, contours, (int)i, color, 1, LINE_8, hierarchy, 0);

        //RotatedRect r_rt = cv::minAreaRect(contours[0]);
        //cv::rectangle(draw_img, r_rt.boundingRect(), Scalar(128, 128, 255));
        //
        //cv::ellipse(draw_img, ellipse, Scalar(0, 255, 0));
        //cv::ellipse(draw_img, ellipse, Scalar(0, 255,255));
        //uchar data1[] = { 1,1,1, 0,0,0, 1,1,1 };
        //Mat kernel(3, 3, CV_8UC1, data1);
        Mat test_roi_img = dst(roi).clone();

        Mat test_resize_img(50,50, CV_8UC1);

        resize(test_roi_img, test_resize_img, Size(50, 50), 0, 0);



        //for (int row = 0; row < ori_img.row)
        //{

        //}
        */
        vector<vector<Point>> roi_contours;
        vector<Vec4i> roi_hierarchy;

        //findContours(resize_img, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

        //Mat im_floodfill = test_bin.clone();
        //floodFill(im_floodfill, cv::Point(0, 0), Scalar(255));
        //Mat im_floodfill_inv;
        //bitwise_not(im_floodfill, im_floodfill_inv);
        //Mat detect_img_R_fill = (test_bin | im_floodfill_inv);
    }

    int y = 5;
    return 0;
}
int resize_img(Mat &src, Mat &dst, Mat &resize_img)
{
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    //Mat draw_img = test.clone();
    //cvtColor(test, draw_img, COLOR_GRAY2BGR);

    RNG rng(12345);
    Rect roi;
    threshold(src, dst, 50, 255, THRESH_BINARY);
    findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

    RotatedRect ellipse;;
    int max_contours = 0;
    int idX_max_contours = 0;

    if (contours.size() > 0)
    {
        for (int i = 0; i < contours.size(); i++)
        {
            if (max_contours < contours[i].size())
            {
                max_contours = contours[i].size();
                idX_max_contours = i;
            }
        }
    } 

    ellipse = cv::fitEllipse(contours[idX_max_contours]);
    if (ellipse.angle < 90)
    {
        Mat M = getRotationMatrix2D(ellipse.center, ellipse.angle, 1);
        warpAffine(dst, dst, M, Size());
    }
    else
        dst = src.clone();

    //findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    //roi = cv::boundingRect(contours[idX_max_contours]);
    Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
    //Mat tmp_resize_img = dst(roi).clone();

    //resize_img = tmp_resize_img;
    //resize(tmp_resize_img, resize_img, Size(28, 28), 0, 0);
    resize_img = dst;
    return 1;
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