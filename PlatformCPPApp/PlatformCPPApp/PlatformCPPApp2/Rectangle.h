#pragma once
#include "IShape.h"

class Rectangle : public IShape
{
public:
	Rectangle();
	~Rectangle();

	void SetVertexCnt(int point);

	void ShowShapeInfo() override;
	//{
	//	int getPoint = GetVertexCnt();
	//	cout << "Rectangle Shape Info is " << getPoint << endl;
	//}
};