/*
	C++ Ư¡�� ������(Polymorphism) Ȱ�� ����

	�Ǝm�� Psudo-code �������̽� �Դϴ�.
*/
#include <string>
#include <iostream>
using namespace std;

class IShape
{
private:
	string _name;private:
protected:
public:
	size_t _points;
	IShape() : _name(""), _points(0) { cout << "IShape::Ctor" << endl; }
	~IShape() { cout << "IShape::Ctor" << endl; }
	//virtual ~IShape() // �Ҹ��ڿ� virtual Ű���带 �ٿ��־�� �ڽ� Ŭ���� ���� �� �ڽ� Ŭ������ �Ҹ��� �� �ִ�.
	void Set(string nameOfShape)
	{
		_name = nameOfShape; // Circle, Triangle, Retangle..etx
	}
	void Display()
	{
		cout << "Shape Name : " << _name << endl;
		cout << "Shape : " << _name << "Points : " << _points << endl;
	}
public:
	virtual void SetPolyPoints(int& points) = 0;
};

class Circle : public IShape
{
	int* pData = nullptr;
public:
	Circle()
	{
		pData = new int[9999];
		cout << "Circle::Ctor" << endl;
	}
	~Circle()
	{
		if (pData != nullptr) { delete pData; pData = nullptr; }
		cout << "Circle::Dtor" << endl;
	}
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Circle");
	}
};//��

class Triangle : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Triangle");
	}
};// �ﰢ��

class Rectangle : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Rectangle");
	}
};//�簢��

class Point : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Point");
	}
};// ��

class Line : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Line");
	}
};//��
class Pentagon : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Pentagon");
	}
};//5����
class Hexagon : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Hexagon");
	}
};///6����
class SevenSideFigure : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("a seven-sided figure");
	}
};//ĥ����

class octagon : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("octagon");
	}
};//8����
class sphericalShape : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("spherical shape");
	}
};//9����

int main()
{
	int data[5] = { 2,3,1,2,2 };
	int histo[4] = { 0, };
	for (size_t i = 0; i < 5; i++)
	{
		histo[data[i]]++;
	}

	IShape* pShape[10] =
	{
		new Circle(), // 0
		new Point(), //1..point
		new Line(), //2..line
		new Triangle(), //3
		new Rectangle(),//4
		new Pentagon(), //5 ������
		new Hexagon(), //6 ������
		new SevenSideFigure(), //7
		new octagon(), //8
		new sphericalShape() //9 ������
	};
	int points = 0;

	//IShape* pShape[3] = {new Circle(), new Triangle(), new Rectangle()};

	for (int i = 0; i < 10; i++)
	{
		cout << "Input Shpae Point : ";
		cin >> points;

		if (pShape[points] != nullptr)
		{
			pShape[points]->SetPolyPoints(points);
			pShape[points]->Display();
		}

		//cout << "Input Shape Points"; cin >> points;
		//if (points == 4)
		//{
		//	pShape[2]->SetPolyPoints(points);
		//	pShape[2]->Display();
		//}
		//else if (points == 3)
		//{
		//	pShape[1]->SetPolyPoints(points);
		//	pShape[1]->Display();
		//}
		//else
		//{
		//	pShape[0]->SetPolyPoints(points);
		//	pShape[0]->Display();
		//}
		//pShape[i]->SetPolyPoints(points)
		//pShape[i]->Display()

	}

	if (true)
	{
		//case 1
		{
			//ctor
			Circle shape;
		} // dtor
		//case 1
		{
			//ctor
			Circle* pShape = new Circle();
			//dtor
			if (pShape != nullptr) { delete pShape; pShape = nullptr; }
		}
		//case 2
		{
			//ctor+
			IShape* pShape = new Circle();
			//dtor
			if (pShape != nullptr) { delete pShape; pShape = nullptr; }
		}
		int x = 5;
	}

}




/*
class IShape
{
private:
	string _name;
protectd:
	size_t _points;
public:
	void Set(string nameOfShape)
	{
		_name = nameOfShape; // Circle, Triangle, Retangle..etx
	}
	virtual void SetPolyPoints(int& points) = 0;
	virtual void Display() = 0;
	virtual void Display_name()
	{
		cout << "Shape Name : " << name << endl;
	}
	{
		cout << "Shape Name : " << name << endl;
		if (_points == 4)
			cout << "Shape : " << "Rectangle" << "Points : " << _points << endl;
		else if (_points == 3)
			cout << "Shape : " << "Rectangle" << "Points : " << _points << endl;
		else
			cout << "Shape : " << "Rectangle" << "Points : " << _points << endl;
	}


private:
	string name;
	int _points;
};

class Circle : public IShape
{
	int SetPolyPoints(int& points)
	{
		_points = points;
		Set("Circle");

		return GetPolyPoints();
	}

	void Display()
	{
		Display_name();
		//cout << "Shape Name : " << name << endl;
		cout << "Shape : " << "Circle" << "Points : " << GetPolyPoints() << endl;
	}
};

class Triangle : public IShape
{
	int SetPolyPoints(int& points)
	{
		_points = points;
		Set("Triangle");

		return GetPolyPoints();
	}
	void Display()
	{
		Display_name();
		//cout << "Shape Name : " << name << endl;
		cout << "Shape : " << "Triangle" << "Points : " << GetPolyPoints() << endl;
	}
};

class Rectangle : public IShape
{
	int SetPolyPoints(int& points)
	{
		_points = points;
		Set("Rectangle");

		return GetPolyPoints();
	}
	void Display()
	{
		Display_name();
		//cout << "Shape Name : " << name << endl;
		cout << "Shape : " << "Rectangle" << "Points : " << GetPolyPoints() << endl;
	}
};
*/