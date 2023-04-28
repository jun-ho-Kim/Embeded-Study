#include "KPhone_solution.h"

KPhone::KPhone()
	: strNumber("")
	, isConnected(false)
	, success(0)
{
	std::cout << "KPhone::Ctor" << std::endl;
}

KPhone::~KPhone()
{
	std::cout << "KPhone::Dtor" << std::endl;
}

int KPhone::Send()
{
	if (success != 1) 
	{
		return 0;
	}

	//isConnected = false;
	if (strNumber == "")
	{
		success = -1;
		std::cout << "전화번호를 입력하세요." << std::endl;
		return success;
	}

	std::cout << "상대방 연락처에 전화를 합니다." << std::endl;

	std::string tmp = "=";
	for (size_t i = 0; i < 30; i++)
	{
		tmp += "=";
		std::cout << tmp;
	}
	std::cout << std::endl;

	std::cout << "상대방과 연결이 되었습니다." << std::endl;
	isConnected = true;
	success = 1;
	return success;
}

int KPhone::Receive()
{
	//int success = 1;

	if (isConnected == true)
	{
		success = -2;
		std::cout << "지금은 통화 중입니다." << std::endl;
		return success;
	}

	isConnected = true;
	success = 1;
	return success;
}

int KPhone::Numbers()
{
	//int success = 1;

	isConnected = false;

	//버튼 방식
	//번호를 입력 받아야 합니다.
	std::cout << "전화번호를 입력하세요 (010-1234-1234) : ";
	std::cin >> strNumber;

	std::cout << "당신이 입력한 연락번호는 " << strNumber << " 입니다." << std::endl;

	//전화 번호의 유효성 검증
	const int validNumberSize = 13;
	if (strNumber.size() != validNumberSize)
	{
		success = -1;
		std::cout << "잘못된 전화번호 입니다." << std::endl;
		return success;
	}
	success = 1;
	return success;
}

int KPhone::Cancel()
{
	if (isConnected == true)
	{
		std::cout << "전화 연결을 종료합니다." << std::endl;
		isConnected = false;
	}
	return 0;
}
