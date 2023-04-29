#include <iostream>
using namespace std;

const char* getName()
{
	return "jackjack";
}

int main()
{
	//char name[] = "Jack Jack"; // Jack Jack

	// char *name = "Jack Jack"; // Error

	/*
	const char *name = "Jack Jack";
	const char *name2 = "Jack Jack";
	//const char* name = getName();	//위와 상동
	//const char* name2 = getName();//위와 상동
	// 문자열 포인터 앞에 const을 붙이면 문자열을 기호적 상수로 사용할 수 있음

	//char name[] = "Jack Jack";

	cout << (uintptr_t)name << endl;	//3250992
	cout << (uintptr_t)name2 << endl;	//3250992
	*/

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World";
	const char* name = "jackjack";

	cout << int_arr << endl;	// 00B3FA94
	cout << char_arr << endl;	// Hello, World
	cout << name << endl;		// jackjack
	// 주의: cout은 문자열 포인터는 특별히 null character까지의 값을 반환한다.()

	char c = 'Q';
	cout << &c << endl; //Q儆儆儆儆0썌 
	// cout은 문자열 포인터를 값을 읽어오기 때문에 null character까지의 값을 읽어와 Q 뒤에 값이 출력된다.

	char d = 'A';

	//cout은 문자열 포인터를 값을 읽어오기 때문에 null character까지의 값을 읽어와 Q 뒤에 값이
	//cout은 사용자들이 편하게 사용하게 하기 위해서 이렇게 작성하였다.
	//나중에 배울 std 라이브러리에 들어있는 string이나 stdarray를 배우면 된다.

	return 0;
}