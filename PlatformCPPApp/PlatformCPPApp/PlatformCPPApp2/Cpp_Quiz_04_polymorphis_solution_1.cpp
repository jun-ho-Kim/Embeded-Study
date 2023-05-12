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
	IShape() :_name(""), _points(0) { cout << "IShape::Ctor" << endl; }
	~IShape() { cout << "IShape::Dtor" << endl; }

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
		nullptr,	//9 구각형
	};
	int points = 0;
	for (int i=0; i<10; i++)
	{
		cout << "Input Shape Points : "; 
		cin >> points;
		
		if (pShape[points] != nullptr)
		{
			pShape[points]->SetPolyPoints(points);
			pShape[points]->Display();
		}
	}

	
}


