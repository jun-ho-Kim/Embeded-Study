#include "KPhone.h"
#include <iostream>

KPhone::KPhone()
	: strNumber()
	, isConnected(false)
{
	std::cout << "KPhone::Ctor" << std::endl;
}

KPhone::~KPhone()
{
	std::cout << "KPhone::Dtor" << std::endl;
}

int KPhone::Send()
{
	int success = 1;
	if (strNumber == "")
	{
		success = -1;
		std::cout << "잘못된 전화번호 입니다." << std::endl;
	}

	return success
}

int KPhone::Numbers()
{
	int success = 1;
	//버튼 방식
	//번호를 입력 받아야 합니다.

	std::cout << "전화번호를 입력하세요 (010-1234-1234) : ";

	std::cin >> strNumber;

	std::cout << "당신이 입력한 연락번호는 " << strNumber << " 입니다." << std::endl;

	//전화번호 유효성 검증

	const int validNumberSize = 13;

	if(strNumber.size() != validNumberSize)
	{ 
		int success = 1;
	}

	return success
}

int main()
{
	//
	char phoneNum[11] = { '0', '1', '0','1' };
	KPhone kpone;
		kpone.Numbers(phoneNum);
	kpone.Send();
	kpone.Recevie();
	kpone.Cancel();
;}