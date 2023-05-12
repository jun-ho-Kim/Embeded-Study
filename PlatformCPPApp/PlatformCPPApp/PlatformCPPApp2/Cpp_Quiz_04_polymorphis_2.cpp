//C++특징인 다형성(Polymorphism) 활용 문제
//아래는 Psudo-Code 인터페이스 입니다.
#include <string>
#include <iostream>
using namespace std;
class IShape
{
private:
	string _name;
protected:
	size_t _points;
public:
	IShape() :_name(""), _points(0) 
	{ 
		cout << "IShape::Ctor" << endl; 
	}
	virtual ~IShape()
	{ 
		cout << "IShape::Dtor" << endl; 
	}

	void Set(string nameOfShape) {
		_name = nameOfShape;//Circle, Triangle, Rectangle..etc
	}
	void Display()
	{
		cout << "Shape Name : " << _name << endl;
		cout << "Shape : " << _name << " Points : " << _points << endl;
	}
public:
	virtual void SetPolyPoints(int& points) = 0;
};
class Circle : public IShape
{
private:
	int* pData = nullptr;
public:
	Circle()
	{ 
		pData = new int[99999999];
		cout << "Circle::Ctor" << endl; 
	}
	~Circle() 
	{ 
		if (pData != nullptr) { delete[] pData; pData = nullptr; }
		cout << "Circle::Dtor" << endl; 
	}
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Circle");
	}
};
class Triangle : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Triangle");
	}
};
class Rectangle : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Rectangle");
	}
};
void main () {

	int data[5] = { 2,3,1,2,2 };
	int histo[4] = {0,};
	for (size_t i = 0; i < 5; i++)
	{
		histo[data[i]]++;
		/*
		histo[0]
		histo[1] = 
		histo[2] = = = 
		histo[3] = 
		*/
	}

	if (true)
	{
		//case 1
		{
			//ctor
			Circle Shape;
		}//dtor
		//case 1
		{
			//ctor
			Circle* pShape = new Circle();
			//dtor
			if (pShape != nullptr) { delete pShape; pShape = nullptr; }
		}
		//case 2
		{
			//ctor
			IShape* pShape = new Circle();
			//dtor
			if (pShape != nullptr) { delete pShape; pShape = nullptr; }
		}
	}

	if(false)
	{


		IShape* pShape[10] =
		{
			new Circle(),//0
			nullptr,	//1...point
			nullptr,	//2...line
			new Triangle(),//3 
			new Rectangle(),//4
			nullptr,	//5 오각형
			nullptr,	//6 육각형
			nullptr,	//7
			nullptr,	//8
			nullptr	//9 구각형
		};
		int points = 0;
		for (int i = 0; i < 1; i++)
		{
			cout << "Input Shape Points : ";
			cin >> points;

			if (pShape[points] != nullptr)
			{
				pShape[points]->SetPolyPoints(points);
				pShape[points]->Display();
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if (pShape[points] != nullptr)
			{
				delete pShape[points];
				pShape[points] = nullptr;
			}
		}
	}
	int a = 0;
}


