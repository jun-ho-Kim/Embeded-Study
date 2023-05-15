#include <iostream>

using namespace std;

class Shape
{
public:
	virtual int area()
	{
		return 0;
	}
 };

class Retangle : public Shape
{
public:
	int area() override
	{
		return 4 * 5;
	}
};

class Triangle : public Shape
{
public:
	int area() override
	{
		return 0.5 * 3 * 4;
	}
};

// Shape로 파생된 모든 클래스는 area()를 출력할 수 있다. 단, 재정의가 되어을 경우에 가능
void printArea(Shape& shape)
{
	cout << "Area: " << shape.area() << endl;
}

int main()
{
	// exam 2.
	Shape* s;
	Retangle r;
	Triangle t;
	s = &r;
	cout << s->area() << endl; // 20
	s = &t;
	cout << s->area() << endl; // 6

	// exam 3.
	//Retangle r;
	//Triangle t;
	//printArea(r); // Area:  20
	//printArea(t); // Area:  6

	return 0;
}
