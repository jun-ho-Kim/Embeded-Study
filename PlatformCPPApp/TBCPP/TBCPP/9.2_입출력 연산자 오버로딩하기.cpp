#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z= 0.0)
		: m_x(x), m_y(y), m_z(z)
	{}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }

	void print()
	{
		cout << m_x << " " << m_y << " " << m_z << endl;
	}

	//첫번째 파라미터가 포인터가 아니라 outputstream이기 때문에 멤버 함수로 할 수 없다.
	//응답이 output stream이기 때문에 연쇄적으로 출력이 가능하다.
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		out << "(" << point.m_x << " " << point.m_y << " " << point.m_z << ")";

		return out;
	}

	friend std::istream& operator >> (std::istream& in, Point& point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;

		return in;
	}


};

int main()
{

	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	//p1.print();
	//cout << " ";
	//p2.print();
	//cout << endl;


	cout << p1 << " " << p2 << endl; // Error
	//output stream을 사용할 때 장점이 더 있는데 파일 출력이 stream으로 되기 때문에 파일출력을 그대로 사용할 수 있다.

	ofstream of("out.txt");

	of << p1 << " " << p2 << endl;

	of.close();

	cin >> p1 >> p2; // intput stream을 사용
	of << p1 << " " << p2 << endl;
 
	//과제: 파일 인풋도 오버로딩해서 사용해보자.

	int z = 5;
}