#include "Common.h"

#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

int main()
{


	IShape* pShape = nullptr;
	Circle* pCircle = new Circle();
	pCircle->SetVertexCnt(0);
	pCircle->ShowShapeInfo();
	pShape = dynamic_cast<IShape*>(pCircle);
	pCircle->SetVertexCnt(10000);
	pCircle->ShowShapeInfo();
	pShape->SetVertexCnt(123);
	pShape->ShowShapeInfo();
	if (pCircle) { delete pCircle; pCircle = nullptr; }

	//pShape->ShowShapeInfo(); // Error

	Triangle* pTriangle = new Triangle();
	pTriangle->SetVertexCnt(3);
	pTriangle->ShowShapeInfo();
	pShape = dynamic_cast<IShape*>(pTriangle);
	pShape->SetVertexCnt(3);
	pShape->ShowShapeInfo();
	if (pTriangle) { delete pTriangle; pTriangle = nullptr; }

	Rectangle* pRectangle = new Rectangle();
	pRectangle->SetVertexCnt(4);
	pRectangle->ShowShapeInfo();
	pShape = dynamic_cast<IShape*>(pRectangle);
	pShape->SetVertexCnt(4);
	pShape->ShowShapeInfo();
	if (pRectangle) { delete pRectangle; pRectangle = nullptr; }

	


	return 1;
}