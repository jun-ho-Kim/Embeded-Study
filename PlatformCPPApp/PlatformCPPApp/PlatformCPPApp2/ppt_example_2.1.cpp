#include <iostream>

using namespace std;

class Shape
{
public:
	virtual double area() = 0;
};

class Rectangle : public Shape {
public:
	double width = 1;
	double height = 1;
	double area() override 
	{
		double result = width * height;

		cout << "Rectangle result is " << result << endl;

		return width * height;
	}
};

class Circle : public Shape
{
public:
	double radius = 1;
	double area() override
	{
		double result = 3.14 * radius * radius;

		cout << "Circle result is " << result << endl;

		return 3.14 * radius * radius;
	}
};

int main()
{
	Shape* shape1 = new Rectangle();
	Shape* shape2 = new Circle();
	double area1 = shape1->area(); // Rectangle result is 1
	double area2 = shape2->area(); // Circle result is 3.14
	delete shape1;
	delete shape2;

	int x = 6;

	return 0;
}