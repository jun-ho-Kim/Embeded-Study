#pragma once

#include <iostream>
#include <string>

class KPhone
{
public:
	KPhone()
		:strNumber()
		, isConnected(false)
	{
		std::cout << "C" << std::endl;
	};
	~KPhone()
	{
		std::cout << "D" << std::endl;
	};

	void Send();
	//{
	//	if (isConnected == true)
	//		std::cout << "전화 중이라 통화 불가" << std::endl;
	//	else
	//		std::cout << "전화 거는 중" << std::endl;
	//	
	//};
	void Recevie()
	{
		isConnected = true;
		std::cout << "전화를 받았습니다." << std::endl;
	};
	void Numbers(char phoneNum[11])
	{
		strNumber = phoneNum;
		std::cout << strNumber << " 번호를 입력 받았습니다." << std::endl;
	};
	void Cancel()
	{
		isConnected = false;
		std::cout << "전화를 끊었습니다.." << std::endl;
	};
private:
	std::string strNumber;
	bool isConnected;
};



