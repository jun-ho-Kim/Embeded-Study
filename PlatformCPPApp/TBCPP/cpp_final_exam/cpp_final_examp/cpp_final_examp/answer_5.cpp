#include <iostream>
#include <string>

class IShape
{
public: 
	IShape()
	{
		std::cout << "IShape::Ctor" << std::endl;
	};
	~IShape()
	{
		std::cout << "IShape::Dtor" << std::endl;
	}

	virtual int GetShape() = 0; // circle-1
};

class Circle : public IShape
{
public:
	Circle()
	{
		std::cout << "Circle::Ctor" << std::endl;
	};
	~Circle()
	{
		std::cout << "Circle::Dtor" << std::endl;
	}

	int GetShape()
	{
		std::cout << "circle-1" << std::endl;
		
		return 1;
	}
};

class Rect : public IShape
{
public:
	Rect()
	{
		std::cout << "Rect::Ctor" << std::endl;
	};
	~Rect()
	{
		std::cout << "Rect::Dtor" << std::endl;
	}

	int GetShape()
	{
		std::cout << "rect-2" << std::endl;

		return 4;
	}
};


int main()
{
	Circle c;
	Rect r;

	IShape* i;

	//Circle Ŭ������  up-casting
	i = dynamic_cast<IShape*>(&c);
	i->GetShape();

	//Rect Ŭ������  up-casting
	i = dynamic_cast<IShape*>(&r);
	i->GetShape();

	int z = 4;

	std::cout << std::endl;
	std::cout << "Q: __vfptr�� �Ļ�Ŭ���� ����Լ��� �ִ� ����" << std::endl;
	std::cout << std::endl;
	std::cout << "R: �����Լ��� ����ϸ� �θ� Ŭ������ �����Լ� ������ ���̺��� ����� �ڽ� Ŭ������ ����Լ��� ������ �����Ѵ�." << std::endl;
	std::cout << "�׷� ������ �θ�Ŭ������ �����Լ� ������ �Լ� ���̺��� Ž���Ͽ� �۵��Ѵ�." << std::endl;

}