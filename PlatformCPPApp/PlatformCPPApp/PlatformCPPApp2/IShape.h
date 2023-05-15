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
// ��� �߻�Ŭ������ ������� 
// �Ļ� Ŭ���� Rectangle, Circle, Triangle, Polygon �� ����  
// ������ ���� �Ļ�Ŭ������ ����ÿ�.
// ���� rectangle.h/cpp
