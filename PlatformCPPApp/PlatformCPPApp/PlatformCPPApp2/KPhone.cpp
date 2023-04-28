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
		std::cout << "�߸��� ��ȭ��ȣ �Դϴ�." << std::endl;
	}

	return success
}

int KPhone::Numbers()
{
	int success = 1;
	//��ư ���
	//��ȣ�� �Է� �޾ƾ� �մϴ�.

	std::cout << "��ȭ��ȣ�� �Է��ϼ��� (010-1234-1234) : ";

	std::cin >> strNumber;

	std::cout << "����� �Է��� ������ȣ�� " << strNumber << " �Դϴ�." << std::endl;

	//��ȭ��ȣ ��ȿ�� ����

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