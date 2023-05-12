/*
	C++ 특징인 다형성(Polymorphism) 활용 문제

	아럐는 Psudo-code 인터페이스 입니다.
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
	//virtual ~IShape() // 소멸자에 virtual 키워드를 붙여주어야 자식 클래스 생성 시 자식 클래스를 소멸할 수 있다.
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
};//원

class Triangle : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Triangle");
	}
};// 삼각형

class Rectangle : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Rectangle");
	}
};//사각형

class Point : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Point");
	}
};// 점

class Line : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Line");
	}
};//선
class Pentagon : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Pentagon");
	}
};//5각형
class Hexagon : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("Hexagon");
	}
};///6각형
class SevenSideFigure : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("a seven-sided figure");
	}
};//칠각형

class octagon : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("octagon");
	}
};//8각형
class sphericalShape : public IShape
{
	void SetPolyPoints(int& points) override
	{
		_points = points;
		Set("spherical shape");
	}
};//9각형

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
		new Pentagon(), //5 오각형
		new Hexagon(), //6 육각형
		new SevenSideFigure(), //7
		new octagon(), //8
		new sphericalShape() //9 구각형
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