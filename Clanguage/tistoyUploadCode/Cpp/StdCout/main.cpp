#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	
	//2.3 키 입력받기 
	//예제 2.3 
	/*
	cout << "너비를 입력하세요>> ";
	int width;
	std::cin >> width;
	std::cout << "높이를 입력하세요>> " ;
	
	int heigth;
	std::cin >> heigth;
	
	int area = width * heigth;
	cout << "면적은 " << area << "\n"; 
	*/
	// >> 연산자
	// >> 연산자는 스트림ㅁ추출 연산자(stream extraction operator)로 불리며 왼쪽 피연산자인 스트림 객체로부터
	//	데이터를 읽어 오른쪽 피연산자에 지정된 변수에 삽입한다. 
	//	스트림 추출  연산자는 본래 정수를 시프트하는 C++의 기본 연산자이지만, <iostream> 헤더 파일에 스트림 추출 연산자로
	//	재정의(operator overloading) 되어있다. 
	
	//2.4 키보드로 문자열 입력
	
	//C++에서 문자열을 표현하는 방법
	//	1. C-스트링 - C언어에서 문자열을 표현하는 방법 
	//	2. string 클래스 - 문자열을 객첼 다루는 방법, 권장하는 방법
	
	// C-string은 널 문자(null string)로 끝나는 char 배열이며 C 언어에서 사용하는 문자열 방식이다.
	// C++에서는 C와의 호환성 때문에 C-string을 그대로 사용한다.
	// + C와 마찬가지로 문자열이 끝날 때는 null string이 있어야 한다. 
	//	그래서 문자열은 문자수보다 최소 1은 커야하며 그보다 더 커도 상관없다.
	//  c++ 문자열이 문자수 +1 이상의 크기가 되지 않는 경우 컴파일에러가 발생하며
	// 	설령 프로그램이 작동하더라도 메모리 주소에 null string이 있는 곳까지 출력하여 원하는 값이 나오지 않을 수 있다. 
	
	char name[6] = "Hello"; 
	std::cout << "Hello is " << name << std::endl;
	
	// cin 객체의 문제점은 white space를 만나는 경우 white space까지의 문자열만 입력을 받는다.
	/*
	char yourName[100];
	std::cout << "당신의 이름을 입력해주세요: "; 
	std::cin >> yourName; // 고 길 동 
	std::cout << "당신의 이름은 " << yourName << "입니다."; // 당신의 이름은 고입니다.
	 */
	// std::cin.getline() 멤버 함수를 사용하면 이 문제를 해결할 수 있다. 
	// std::cin.getline(char buf[], int size, char delimitChar)
	// buf: 키보드로부터 읽은 문자열을 저장할 배열
	// size: buf[] 배열의 크기
	// delimetChar : 문자열 입력 끝을 지정하는 구분 문자. 

	/*
	char yourName[100];
	std::cout << "당신의 이름을 입력해주세요: "; 
	std::cin.getline(yourName, 100, '\n'); // 고 길 동 
	std::cout << "당신의 이름은 " << yourName << "입니다."; // 당신의 이름은 고 길 동입니다.
	*/

	// 또 string 클래스를 사용하는 방법이 있다.
	// string 클래스는 C-string과 다르게 크기에 제약이 없다.
	// 또한 string 클래스는 문자열 복사, 비교, 수정등 다양한 문자열 연산을 위한 멤버함수와 연산자를 제공하여 문자열을 쉽게 다룰 수 있게 해준다.

	string yourName;
	 
	std::cout << "당신의 이름을 입력해주세요: "; 
	std::getline(cin, yourName); // 고 길 동 
	std::cout << "당신의 이름은 " << yourName << "입니다."; // 당신의 이름은 고 길 동입니다.
	// 여기서 cin.getline이 아니라 getline() 함수를 사용했는데 
	//	getline() 는 string 라이브러리에 속하고 cin.getline()은 iostream 라이브러리에 속한다. 
	
	/*
	std::cout<<"Hello\n";
	std::cout<<"안녕하세요\n";
	
	//예제 2.3
	
	// cin을 이용한 문자열 입력
	 
	char name[100];
	std::cin.getline(name, 100, '\n');
	//std::cin >> name;
	
	std::cout << "name is " << name <<std::endl;
	
	for(int i=0; i<6;i++)
	{
		std::cout <<i << "- name is " << name[i] <<std::endl;
	}
	std::cout << "name2 is " << name <<std::endl;
	 
	*/
	
	/*
	//예제 2.5
	char password[11];
	std::cout << "프로그램을 종료하려면 암호를 입력하세요" << std::endl;
	while(true)
	{
		std::cout << "암호>>";
		std::cin >> password;
		if(strcmp(password, "C++") == 0)
		{
			std::cout << "v프로그램을 정상 종료합니다." << endl;
			break;
		}	
		else
			std::cout << "암호가 틀립니다~~" << std::endl; 
	} 
	*/
	
	/*
	//예제2.7
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;
	
	cout << song + "를 부른 가수는";
	cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";
	getline(cin, singer);
	if(singer == elvis)
		cout << "맞았습니다.";
	else
		cout << "틀렸습니다. " + elvis + "입니다." << endl; 
	 
	*/
	
	//https://kyu9341.github.io/C-C/2020/01/17/C++getline()/
	return 0;
}
