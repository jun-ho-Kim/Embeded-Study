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
	//		std::cout << "��ȭ ���̶� ��ȭ �Ұ�" << std::endl;
	//	else
	//		std::cout << "��ȭ �Ŵ� ��" << std::endl;
	//	
	//};
	void Recevie()
	{
		isConnected = true;
		std::cout << "��ȭ�� �޾ҽ��ϴ�." << std::endl;
	};
	void Numbers(char phoneNum[11])
	{
		strNumber = phoneNum;
		std::cout << strNumber << " ��ȣ�� �Է� �޾ҽ��ϴ�." << std::endl;
	};
	void Cancel()
	{
		isConnected = false;
		std::cout << "��ȭ�� �������ϴ�.." << std::endl;
	};
private:
	std::string strNumber;
	bool isConnected;
};



