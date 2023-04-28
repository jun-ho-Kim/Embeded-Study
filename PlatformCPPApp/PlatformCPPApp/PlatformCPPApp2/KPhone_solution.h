#pragma once

#include <iostream>
/*이제 클래스로 명세화 하시고 클래스를 설계 및 구현하세요.

Send() : 전화를 걸다
Receive() : 전화를 받다
Numbers() : 전화번호를 입력한다.
Cancel() : 전화를 끊다

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
	std::string strNumber;	// : 전화번호
	bool isConnected;		// : 전화중인가 ?
	int success;
};


//LOL....
//objects...게임 케릭터...HP...      POWER....
//                       |||||||    ||
//                       |||        ||||||||  +20
//                                  ********
//          앞으로/뒤로/좌로/우로/점프/줍다
//
// 마법사                 ||         ||    +10
// /.....
