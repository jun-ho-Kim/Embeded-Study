//  C++의 다형성(polymorphism)을 이용한 아키텍쳐를 구현하시오
#pragma once
#include <iostream>
#include <string>
#include "I3DModule.h"

class Module3D_Apple : public I3dModule
{
public:
	Module3D_Apple(){ std::cout << "Module 3D_Apple::Ctor" << std::endl; }
	~Module3D_Apple() { std::cout << "Module 3D_Apple::Dtor" << std::endl; }
	int Stream()
	{
		std::cout << "Module3D_Apple::Ipone" << std::endl;
		return 1;
	}//3D, Tx, Rx 구동. Success - 1, Fail - 0
	int Make3DData() // 재구성 reconstruction 3D data ... success - 1, Fail - 0
	{
		std::cout << "Module3D_Apple::Make3DData" << std::endl;
		int* pData = Get3DData();
		pData[0] = 2;
		return 1;
	}
};

class Module3D_Intel : public I3dModule
{
public:
	Module3D_Intel() { std::cout << "Module 3D_Intel::Ctor" << std::endl; }
	~Module3D_Intel() { std::cout << "Module 3D_Intel::Dtor" << std::endl; }
	int Stream()
	{
		std::cout << "Module3D_Intel::RELASENSE*******" << std::endl;
		return 1;
	}//3D, Tx, Rx 구동. Success - 1, Fail - 0
	int Make3DData() // 재구성 reconstruction 3D data ... success - 1, Fail - 0
	{
		std::cout << "Module3D_Intel::Make3DData" << std::endl;
		int* pData = Get3DData();
		pData[0] = 5;
		return 1;
	}
private:
};

class Module3D_OpenCv : public I3dModule
{
public:
	Module3D_OpenCv() { std::cout << "Module Module3D_OpenCv::Ctor" << std::endl; }
	~Module3D_OpenCv() { std::cout << "Module Module3D_OpenCv::Dtor" << std::endl; }
	int Stream()
	{
		std::cout << "Module3D_OpenCv::OpenAI*******" << std::endl;
		return 1;
	}//3D, Tx, Rx 구동. Success - 1, Fail - 0
	int Make3DData() // 재구성 reconstruction 3D data ... success - 1, Fail - 0
	{
		std::cout << "Module3D_OpenCv::Make3DData" << std::endl;
		int* pData = Get3DData();
		pData[0] = 7;
		return 1;
	}

private:
};

// 함수의 재정의
// function overloading
int sum(int a, int b)
{
	return a + b;
}

double sum(double a, double b)
{
	return a + b;
}

// 2. function overriding - 상속관계
class A
{
public:
	int sum(int a, int b) { 
		std::cout << "A:sum" << endl;
		return 0; 
	}
};

class B : public A
{
public:
	int sum(int a, int b) 
	{ 
		std::cout << "B:sum" << endl;
		return a + b; 
	};
};

int main()
{
	int c = sum(10, 10);
	std::cout << "c=" << c << std::endl;	// c=20
	double d = sum(10.1, 10.1);

	std::cout << "d=" << d << std::endl;	// d=20
	A a;
	c = a.sum(10, 10);	//A:sum
	std::cout << "c=" << c << std::endl;	// c=0
	B b;
	d = b.sum(10, 10);	//B:sum
	std::cout << "d=" << c << std::endl;	// d=0




	{
		I3dModule i3d;
		i3d.Open();

		int w = 10000, h = 1000;
		i3d.Allocation(w, h);
		std::cout << "I3DModule::Width = " << i3d.GetWidth() << std::endl;
		std::cout << "I3DModule::Height = " << i3d.GetHeight() << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			i3d.Stream();
		}
		i3d.Make3DData();
		i3d.Show3DData();
		int value = i3d.Get3DData(0, 0);
		std::cout << "I3dModule (0,0) = " << value << std::endl;
		i3d.Close();
	}

	{
		Module3D_Apple i3d;
		i3d.Open();

		int w = 120, h = 120;
		i3d.Allocation(w, h);
		std::cout << "Module3D_Apple::Width = " << i3d.GetWidth() << std::endl;
		std::cout << "Module3D_Apple::Height = " << i3d.GetHeight() << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			i3d.Stream();
		}
		i3d.Make3DData();
		i3d.Show3DData();

		int value = i3d.Get3DData(0, 0);
		std::cout << "Module3D_Apple (0,0) = " << value << std::endl;

		i3d.Close();
	}

	{
		Module3D_Intel i3d;
		i3d.Open();

		int w = 50, h = 50;
		i3d.Allocation(w, h);
		std::cout << "Module3D_Apple::Width = " << i3d.GetWidth() << std::endl;
		std::cout << "Module3D_Apple::Height = " << i3d.GetHeight() << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			i3d.Stream();
		}
		i3d.Make3DData();
		i3d.Show3DData();

		int value = i3d.Get3DData(0, 0);
		std::cout << "Module3D_Intel (0,0) = " << value << std::endl;
		i3d.Close();
	}

	{
		Module3D_OpenCv i3d;
		i3d.Open();

		int w = 640, h = 48;
		i3d.Allocation(w, h);
		std::cout << "Module3D_OpenCv::Width = " << i3d.GetWidth() << std::endl;
		std::cout << "Module3D_OpenCv::Height = " << i3d.GetHeight() << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			i3d.Stream();
		}
		i3d.Make3DData();
		i3d.Show3DData();

		int value = i3d.Get3DData(0, 0);
		std::cout << "Module3D_OpenCv (0,0) = " << value << std::endl;

		i3d.Close();
	}

	return 1;
}