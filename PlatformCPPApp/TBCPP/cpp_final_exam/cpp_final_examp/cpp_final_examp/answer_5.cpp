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

	//Circle 클래스를  up-casting
	i = dynamic_cast<IShape*>(&c);
	i->GetShape();

	//Rect 클래스를  up-casting
	i = dynamic_cast<IShape*>(&r);
	i->GetShape();

	int z = 4;

	std::cout << std::endl;
	std::cout << "Q: __vfptr에 파생클래스 멤버함수가 있는 이유" << std::endl;
	std::cout << std::endl;
	std::cout << "R: 가상함수를 사용하면 부모 클래스는 가상함수 포인터 테이블을 만들어 자식 클래스의 멤버함수의 정보를 저장한다." << std::endl;
	std::cout << "그런 다음에 부모클래스는 가상함수 포인터 함수 테이블을 탐색하여 작동한다." << std::endl;

}