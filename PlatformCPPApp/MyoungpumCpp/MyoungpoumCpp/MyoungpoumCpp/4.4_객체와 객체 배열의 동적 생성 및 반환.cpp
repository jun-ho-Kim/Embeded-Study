#include <iostream>
using namespace std;

/*
// ���� 4.7
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
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::~Circle()
{
	cout << "�Ҹ��� ���� radius = " << radius << endl;
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
	cout << "������ ���� radius = " << radius << endl;
}
Circle::Circle(int r)
{
	radius = r;
	cout << "������ ���� radius = " << radius <<  endl;
}

Circle::Circle(int r, int tes)
{
	radius = r;
	test = tes;

	cout << "������ ���� radius = " << radius << ", tes is" << tes << endl;
}

Circle::~Circle()
{
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}

int main()
{
	/*
	// ���� 4.7
	Circle* p, * q;
	p = new Circle();
	q = new Circle(30);
	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q;
	*/

	/*
	// ���� 4.8
	int radius;

	while (true)
	{
		cout << "���� ������ �Է�(�����̸� ����)>>";
		cin >> radius;
		if (radius < 0) break;
		Circle* p = new Circle(radius, 5);

		cout << "p is" << p << endl;
		cout << "&p is" << &p << endl;

		cout << "���� ������" << p->getArea() << endl;
		delete p;
	}
	*/


	/*
	//���� 4.9

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


	// ���� 4.10 - 
	cout << "�����ϰ��� �ϴ� ���� ����? ";
	int n, radius;
	cin >> n;
	if (n <= 0) return 0;
	Circle* pArray = new Circle[n];
	for (int i = 0; i < n; i++)
	{
		cout << "��" << i + 1 << ":";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < n;i++) {
		double circleArea =  pArray[i].getArea();
		cout << "���� ������" <<  circleArea << endl;
		if (circleArea >= 100 && circleArea <= 200)
			count++;
	}
	cout << endl << "������ 100�ּ� 200 ������ ���� ������ " << count << endl;

	/*
	// ���� 4.10 - ���� Ǭ ����
	int radius;
	int circleCnt = 0;
	int maxCnt, count = 0;
	cout << "�Է¹��� ���� ������ �����ּ���. >>";
	cin >> maxCnt;
	while (count < maxCnt)
	{
		cin >> radius;

		if (radius < 0) break;
		cout << "���� ���̴�" << endl;
		if (radius >= 100 && radius <= 200)
			++circleCnt;
		count++;
	}
	cout << endl << "������ 100�ּ� 200 ������ ���� ������ " << circleCnt << endl;
	*/

}