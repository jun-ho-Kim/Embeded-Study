#include "Common.h"
#include "Rectangle.h"

Rectangle::Rectangle()
{
	cout << "Rectagle::Ctor" << endl;
}

Rectangle::~Rectangle()
{
	cout << "Rectagle::Dtor" << endl;
}

void Rectangle::ShowShapeInfo()
{
	cout << "Rectangle::ShowShapeInfo is " << GetVertexCnt() << endl;
}
