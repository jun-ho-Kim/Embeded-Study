#include <iostream>
using namespace std;

/*
// 예제 4.7
class Circle 
{
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; };
};

Circle::Circle()
{
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle()
{
	cout << "소멸자 실행 radius = " << radius << endl;
}
*/

class Circle
{
	int radius;
	int test;
public:
	Circle();
	Circle(int r);
	Circle(int r, int tes);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle()
{
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r)
{
	radius = r;
	cout << "생성자 실행 radius = " << radius <<  endl;
}

Circle::Circle(int r, int tes)
{
	radius = r;
	test = tes;

	cout << "생성자 실행 radius = " << radius << ", tes is" << tes << endl;
}

Circle::~Circle()
{
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main()
{
	/*
	// 예제 4.7
	Circle* p, * q;
	p = new Circle();
	q = new Circle(30);
	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q;
	*/

	/*
	// 예제 4.8
	int radius;

	while (true)
	{
		cout << "정수 반지름 입력(음수이면 종료)>>";
		cin >> radius;
		if (radius < 0) break;
		Circle* p = new Circle(radius, 5);

		cout << "p is" << p << endl;
		cout << "&p is" << &p << endl;

		cout << "원의 면적은" << p->getArea() << endl;
		delete p;
	}
	*/


	/*
	//예제 4.9

	Circle* pArray = new Circle[3]; // { Circle(2), Circle(3), Circle(1) };

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
		cout << pArray[i].getArea() << endl;
		//cout << pArray->getArea() << endl;
		pArray++;
	}

	*/


	// 예제 4.10 - 
	cout << "생성하고자 하는 원의 개수? ";
	int n, radius;
	cin >> n;
	if (n <= 0) return 0;
	Circle* pArray = new Circle[n];
	for (int i = 0; i < n; i++)
	{
		cout << "원" << i + 1 << ":";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < n;i++) {
		double circleArea =  pArray[i].getArea();
		cout << "원의 면적은" <<  circleArea << endl;
		if (circleArea >= 100 && circleArea <= 200)
			count++;
	}
	cout << endl << "면적이 100애서 200 사이인 원의 개수는 " << count << endl;

	/*
	// 예제 4.10 - 내가 푼 문제
	int radius;
	int circleCnt = 0;
	int maxCnt, count = 0;
	cout << "입력받을 원의 개수를 적어주세요. >>";
	cin >> maxCnt;
	while (count < maxCnt)
	{
		cin >> radius;

		if (radius < 0) break;
		cout << "원의 넓이는" << endl;
		if (radius >= 100 && radius <= 200)
			++circleCnt;
		count++;
	}
	cout << endl << "면적이 100애서 200 사이인 원의 개수는 " << circleCnt << endl;
	*/

}