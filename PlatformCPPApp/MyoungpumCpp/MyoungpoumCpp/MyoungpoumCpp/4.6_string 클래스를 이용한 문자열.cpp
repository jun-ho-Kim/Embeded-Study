#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*
	// 예제 4.11
	// 스트링 생성
	string str; // 빈 문자열을 가진 스트림 객체 생성
	string address("서울시 성북구 삼선동 389");
	string copyAddress(address);

	char text[] = { 'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0' }; // C-스트링
	string title(text);  // "Love C++" 문자열을 가진 스트링 객체 생성

	cout << str << endl; // 
	cout << address << endl; // 서울시 성북구 삼선동 389
	cout << copyAddress << endl; // 서울시 성북구 삼선동 389
	cout << title << endl; // Love C++
	*/
	int z = 4;

	//예제 4.12
	string name[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "이름 >>";
		getline(cin, name[i], '\n');
	}

	string latter = name[0];

	for (int i = 1; i < 5; i++)
	{
		cout << "name " << i << "is" << name[i] << endl;;
		if (latter < name[i])
			latter = name[i];
	}

	cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;

	return 1;
}
