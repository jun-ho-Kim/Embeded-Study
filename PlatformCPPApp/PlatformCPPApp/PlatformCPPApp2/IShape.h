#pragma once
#include "Common.h"

class IShape
{
public:
	IShape()
	{
		cout << "IShape::Ctor" << endl;
	}; //ctor
	virtual ~IShape() 
	{
		cout << "IShape::Dtor" << endl;
	} //dtor
	//Set Vertex Count
	//virtual void SetVertexCnt(int point) = 0;
	void SetVertexCnt(int point)
	{
		_point = point;
	}
	//Get Vertex Count
	//virtual int GetVertexCnt() = 0;
	virtual int GetVertexCnt()
	{
		return _point;
	}
	//Show Shape Information
	virtual void ShowShapeInfo() = 0;
private:
	//variables
	int _point = 0;
};
// 상기 추상클래스를 기반으로 
// 파생 클래스 Rectangle, Circle, Triangle, Polygon 과 같은  
// 도형에 대한 파생클래스를 만드시오.
// 형식 rectangle.h/cpp
