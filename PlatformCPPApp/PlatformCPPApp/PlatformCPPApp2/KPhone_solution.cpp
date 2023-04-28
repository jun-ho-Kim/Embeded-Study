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
		std::cout << "��ȭ��ȣ�� �Է��ϼ���." << std::endl;
		return success;
	}

	std::cout << "���� ����ó�� ��ȭ�� �մϴ�." << std::endl;

	std::string tmp = "=";
	for (size_t i = 0; i < 30; i++)
	{
		tmp += "=";
		std::cout << tmp;
	}
	std::cout << std::endl;

	std::cout << "����� ������ �Ǿ����ϴ�." << std::endl;
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
		std::cout << "������ ��ȭ ���Դϴ�." << std::endl;
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

	//��ư ���
	//��ȣ�� �Է� �޾ƾ� �մϴ�.
	std::cout << "��ȭ��ȣ�� �Է��ϼ��� (010-1234-1234) : ";
	std::cin >> strNumber;

	std::cout << "����� �Է��� ������ȣ�� " << strNumber << " �Դϴ�." << std::endl;

	//��ȭ ��ȣ�� ��ȿ�� ����
	const int validNumberSize = 13;
	if (strNumber.size() != validNumberSize)
	{
		success = -1;
		std::cout << "�߸��� ��ȭ��ȣ �Դϴ�." << std::endl;
		return success;
	}
	success = 1;
	return success;
}

int KPhone::Cancel()
{
	if (isConnected == true)
	{
		std::cout << "��ȭ ������ �����մϴ�." << std::endl;
		isConnected = false;
	}
	return 0;
}
