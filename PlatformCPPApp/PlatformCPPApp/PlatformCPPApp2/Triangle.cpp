#include "Common.h"
#include "Triangle.h"

Triangle::Triangle()
{
	cout << "Triangle::Ctor" << endl;
}

Triangle::~Triangle()
{
	cout << "Triangle::Dtor" << endl;
}

void Triangle::ShowShapeInfo()
{
	cout << "Triangle::ShowShapeInfo is " << GetVertexCnt() << endl;
}