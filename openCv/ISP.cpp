#include "ISP.h"


ISP::ISP()
{
	cout << "ISP::Ctor" << endl;
}

ISP::~ISP()
{
	cout << "ISP::Dtor" << endl;
}

void ISP::Convert_BGR2Gray(uchar* pDataBRG, size_t& w, size_t& h, uchar* pY)
{
	for (size_t row = 0; row < h; row++)
	{
		for (size_t col = 0; col < w; col++)
		{
			int index = row * w + col;
			index *= 3;
			int b = pDataBRG[index + 0];
			int g = pDataBRG[index + 1];
			int r = pDataBRG[index + 2];
			int band_index = row * w + col;
			pY[band_index] = 0.299 * r + 0.587 * g + 0.114 * b;
		}
	}
}

void ISP::Get_Histogram(uchar* pDataGray, size_t& length, int* pHisto)
{
	for (size_t i = 0; i < length; i++)
	{
		pHisto[pDataGray[i]]++;
	}
}

void ISP::Get_LSF(uchar* pDataGray, size_t& w, size_t& h, uchar* plpf_img)
{
	float lpf_kenel[9] = 
	{
	1. / 9, 1. / 9, 1. / 9 ,
	1. / 9, 1. / 9, 1. / 9 ,
	1. / 9, 1. / 9, 1. / 9 ,
	};

	for (size_t row = 1; row < h - 1; row++)
	{
		for (size_t col = 1; col < w - 1; col++)
		{
			int temp = lpf_kenel[0] * pDataGray[(row - 1) * w + (col - 1)];
			temp += lpf_kenel[1] * pDataGray[(row - 1) * w + (col + 0)];
			temp += lpf_kenel[2] * pDataGray[(row - 1) * w + (col + 1)];

			temp += lpf_kenel[3] * pDataGray[(row - 0) * w + (col - 1)];
			temp += lpf_kenel[4] * pDataGray[(row - 0) * w + (col + 0)];
			temp += lpf_kenel[5] * pDataGray[(row - 0) * w + (col + 1)];

			temp += lpf_kenel[6] * pDataGray[(row + 1) * w + (col - 1)];
			temp += lpf_kenel[7] * pDataGray[(row + 1) * w + (col + 0)];
			temp += lpf_kenel[8] * pDataGray[(row + 1) * w + (col + 1)];

			plpf_img[(row)*w + col] = temp;
			//pDataLPF[(row)*width + col] - temp;
		}
	}
}

void ISP::Get_HPF(uchar* pDataGray, size_t& w, size_t& h, uchar* sobel_img)
{
	int soble_x[3 * 3] =
	{
		-1, -2, -1,
		0, 0, 0,
		1, 2, 1
	};

	int soble_y[3*3] = 
	{
		-1, 0, 1,
		-2, 0, 2,
		-1, 0, 1
	};

	for (size_t row = 1; row < h - 1; row++)
	{
		for (size_t col = 1; col < w - 1; col++)
		{
			int gx = soble_x[0] * pDataGray[(row - 1) * w + (col - 1)];
			gx += soble_x[1] * pDataGray[(row - 1) * w + (col + 0)];
			gx += soble_x[2] * pDataGray[(row - 1) * w + (col + 1)];

			gx += soble_x[3] * pDataGray[(row - 0) * w + (col - 1)];
			gx += soble_x[4] * pDataGray[(row - 0) * w + (col + 0)];
			gx += soble_x[5] * pDataGray[(row - 0) * w + (col + 1)];

			gx += soble_x[6] * pDataGray[(row + 1) * w + (col - 1)];
			gx += soble_x[7] * pDataGray[(row + 1) * w + (col + 0)];
			gx += soble_x[8] * pDataGray[(row + 1) * w + (col + 1)];

			int gY = soble_y[0] * pDataGray[(row - 1) * w + (col - 1)];//¢Ø
			gY += soble_y[1] * pDataGray[(row - 1) * w + (col + 0)];//¡è
			gY += soble_y[2] * pDataGray[(row - 1) * w + (col + 1)];//¢Ö
			gY += soble_y[3] * pDataGray[(row + 0) * w + (col - 1)];//¡ç
			gY += soble_y[4] * pDataGray[(row + 0) * w + (col + 0)];//
			gY += soble_y[5] * pDataGray[(row + 0) * w + (col + 1)];//¡æ
			gY += soble_y[6] * pDataGray[(row + 1) * w + (col - 1)];//¢×
			gY += soble_y[7] * pDataGray[(row + 1) * w + (col + 0)];//¡é
			gY += soble_y[8] * pDataGray[(row + 1) * w + (col + 1)];//¢Ù

			sobel_img[(row)*w + col] = abs(gx) + abs(gY);
			//sobel_img[(row)*w + col] = gx;
			//pDataLPF[(row)*width + col] - temp;
		}
	}
}

void ISP::Get_HPF2(uchar* pDataGray, size_t& w, size_t& h, uchar* laplace_img)
{
	int laplace_x[3 * 3] =
	{
		0, 1, 0,
		1, -4, 1,
		0, 1, 0
	};

	for (size_t row = 1; row < h - 1; row++)
	{
		for (size_t col = 1; col < w - 1; col++)
		{
			int gx = laplace_x[0] * pDataGray[(row - 1) * w + (col - 1)];
			gx += laplace_x[1] * pDataGray[(row - 1) * w + (col + 0)];
			gx += laplace_x[2] * pDataGray[(row - 1) * w + (col + 1)];

			gx += laplace_x[3] * pDataGray[(row - 0) * w + (col - 1)];
			gx += laplace_x[4] * pDataGray[(row - 0) * w + (col + 0)];
			gx += laplace_x[5] * pDataGray[(row - 0) * w + (col + 1)];

			gx += laplace_x[6] * pDataGray[(row + 1) * w + (col - 1)];
			gx += laplace_x[7] * pDataGray[(row + 1) * w + (col + 0)];
			gx += laplace_x[8] * pDataGray[(row + 1) * w + (col + 1)];

			laplace_img[(row)*w + col] = abs(gx);
			//pDataLPF[(row)*width + col] - temp;
		}
	}
}