#pragma once

#include "./Common/Common.h"
class ISP // Image Sinal Processing
{
public:
	ISP();
	~ISP();
	void Convert_BGR2Gray(uchar* pDataBRG, size_t& w, size_t& h, uchar* pY);
	void Get_Histogram(uchar* pDataGray, size_t& length, int* pHisto);
	void Get_LSF(uchar* pDataGray, size_t& w, size_t& h, uchar* plpf_img);
	void Get_HPF(uchar* pDataGray, size_t& w, size_t& h, uchar* sobel_img);
	void Get_HPF2(uchar* pDataGray, size_t& w, size_t& h, uchar* laplace_img); // 이차 미분
	//void Get_RAPLACE(uchar* pDataGray, size_t& w, size_t& h, uchar* laplace_img); // 이차 미분
private:

};

