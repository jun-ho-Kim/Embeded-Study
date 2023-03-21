//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main()
{
	char c;

	// _getche를 사용하면 한글자입력하면 한글자가 나온다.
	// buffer를 통하지 않으면 원래 이렇게 작동하는 것이 맞다.
	/*
	while ((c = _getche()) != '.') //getCharEcho //입력하면 바로 입력 값이 출력된다.
		putchar(c);
	*/

	while ((c = _getch()) != '.') //입력하면 입력한 값이 출력이 안됨
		putchar(c);

	//getch(), getche()는 현재 사용되지 않음(이름 앞에 _를 붙여주어야 함)
	return 0;
}