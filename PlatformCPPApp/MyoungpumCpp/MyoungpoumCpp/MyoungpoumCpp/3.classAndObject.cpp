// MyoungpoumCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
//예제 3.1
class Circle
{
public:
    int radius;
    double getArea();
};

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

//예제 3.2
class Rectangle 
{
public:
    int width;
    int heigth;
    int getArea();
};

int Rectangle::getArea()
{
    return width * heigth;
}

class Circle2
{
public:
    int radius;
    Circle2();
    Circle2(int r);
    double getArea();

    //~Circle2();
};

Circle2::Circle2()
{
    radius = 1;
    std::cout << "반지름 " << radius << " 원 생성" << std::endl;
}

Circle2::Circle2(int r)
{
    radius = r;
    std::cout << "반지름 " << radius << " 원 생성" << std::endl;
}

double Circle2::getArea()
{
    return 3.14 * radius * radius;
}

class MyClass
{
public:
    MyClass();
    ~MyClass();
    int ABC();
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
    /*
    // 예제 3.1
    Circle donut;
    donut.radius = 1;

    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza;
    pizza.radius = 30;
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;
    */

    /*
    // 예제 3.2
    Rectangle rect;
    rect.width = 3;
    rect.heigth = 5;
    std::cout << "사각형의 면적은 " << rect.getArea() << endl;
    */

    /*
    //예제 3.3
    Circle2 donut;
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle2 pizza(3);
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;
    */



    return 1;
}

