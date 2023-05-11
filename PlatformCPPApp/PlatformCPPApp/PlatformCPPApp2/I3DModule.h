#pragma once
//  C++의 다형성(polymorphism)을 이용한 아키텍쳐를 구현하시오

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class I3dModule
{
public:
	I3dModule()
		: _width(0)
		, _heigth(0)
		, _p3Ddatas(nullptr)
	{
		std::cout << "I3dModul::Ctor" << std::endl;
	}
	~I3dModule()
	{
		if (_p3Ddatas != nullptr)
		{
			delete[] _p3Ddatas;
			_p3Ddatas = nullptr;
		}
		std::cout << "I3dModul::Dtor" << std::endl;
	}
	int Open()
	{
		std::cout << "I3DModule::Open" << std::endl;
		return 1;
	} // Device Open .. Success -1, Fail - 0
	int Close()
	{
		std::cout << "I3DModule::Close" << std::endl;
		return 1;
	};// Device Close .. Success -1, Fail - 0
	int Allocation(int width, int height) // Device Resolution
	{
		_width = width;
		_heigth = height;
		_p3Ddatas = new int[width * height] {0,};
		std::cout << "I3DModule::Allocation" << std::endl;

		return 1;
	} // Device Resolution 생성
	int Stream()
	{
		std::cout << "I3DModule::Stream" << std::endl;
		return 1;
	}//3D, Tx, Rx 구동. Success - 1, Fail - 0
	int Make3DData() // 재구성 reconstruction 3D data ... success - 1, Fail - 0
	{
		std::cout << "I3DModule::Make3DData" << std::endl;
		return 1;
	}
	;//재구성 reconstruction 3D data .. Success - 1, Fail - 0
	virtual int Show3DData()
	{
		std::cout << "I3DModule::Show3DData" << std::endl;
		return 1;
	}// 3D Data Display
	//virtual int* Get3DData() { return _p3Ddatas; }
	virtual int* Get3DData() = 0; // 순수 가상함수
	int Get3DData(int x, int y) { return _p3Ddatas[y*_width+x]; }
	int GetWidth() 
	{
		return _width;
	};	// return allocated width
	int GetHeight()
	{
		return _heigth;
	};
	// return allocated height
private:
	int _width;
	int _heigth;
	int* _p3Ddatas;
};