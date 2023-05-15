#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	
	void setRadius(int r) { radius = r; }
	
	double getArea();
};


double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main()
{
	/*
	// 예제 4.1
	Circle donut;
	Circle pizza(30);

	cout << donut.getArea() << endl; // 3.14

	Circle* p;
	p = &donut;
	cout << p->getArea() << endl;	// 3.14
	cout << (*p).getArea() << endl; // 3.14

	cout << "------------------------" << endl;

	p = &pizza;
	cout << p->getArea() << endl;	// 2826
	cout << (*p).getArea() << endl; // 2826
	*/

	/*
	//예제 4.2
	
	Circle circleArray[3];

	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl; 
		// Circle 0의 면적은 314
		// Circle 1의 면적은 1256
		// Circle 2의 면적은 2826
	}

	Circle* p;
	p = circleArray;
	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}
	*/
	
	/*
	// 예제 4.3
	Circle circleArra[3] = { Circle(10), Circle(20), Circle() };


	for (int i = 0; i < 3; i++)
		cout << "Circle " << i << "의 면적은 " << circleArra[i].getArea() << endl;
	// Circle 0의 면적은 314
	// Circle 1의 면적은 1256
	// Circle 2의 면적은 3.14
	*/

	Circle circles[2][3];

	circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);

	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);

	for(int i =0; i< 2; i++)
		for (int j = 0;j < 3;j++)
		{
			cout << "Circle [" << i << "," << j << "]의 면적은 ";
			cout << circles[i][j].getArea() << endl;

			//Circle[0, 0]의 면적은 3.14
			//Circle[0, 1]의 면적은 12.56
			//Circle[0, 2]의 면적은 28.26
			//Circle[1, 0]의 면적은 50.24
			//Circle[1, 1]의 면적은 78.5
			//Circle[1, 2]의 면적은 113.04
		}
}
