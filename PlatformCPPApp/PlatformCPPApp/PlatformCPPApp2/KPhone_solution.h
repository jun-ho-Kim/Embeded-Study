#pragma once

#include <iostream>
/*���� Ŭ������ ��ȭ �Ͻð� Ŭ������ ���� �� �����ϼ���.

Send() : ��ȭ�� �ɴ�
Receive() : ��ȭ�� �޴�
Numbers() : ��ȭ��ȣ�� �Է��Ѵ�.
Cancel() : ��ȭ�� ����

*/
class KPhone
{
public:
	KPhone();
	~KPhone();
public:
	int Send();//success, fail
	int Receive();
	int Numbers();
	int Cancel();
private:
	std::string strNumber;	// : ��ȭ��ȣ
	bool isConnected;		// : ��ȭ���ΰ� ?
	int success;
};


//LOL....
//objects...���� �ɸ���...HP...      POWER....
//                       |||||||    ||
//                       |||        ||||||||  +20
//                                  ********
//          ������/�ڷ�/�·�/���/����/�ݴ�
//
// ������                 ||         ||    +10
// /.....
