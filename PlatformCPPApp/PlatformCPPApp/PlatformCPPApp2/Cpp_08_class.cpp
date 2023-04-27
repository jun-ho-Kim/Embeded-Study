#include <iostream>
//객체지향 언어 C++가 가지는 Class에 대해 알아봅시다.
//객체 - object 개념을 중심으로 소프트웨어 시스템을 구축하는 것

//객체지향의 특징:
/*
추상화(abstraction) : 정보은닉의 수단 중 하나로 공통의 속성 / 기능을 묶어서 클래서로 정의한 것
	휴대폰 : 전화기의 속성...아이폰/갤럭시
	전화기 == 객체
	전화 걸기 == 객체,속성/기능
	전화 받기 == 객체,속성/기능
	전화 울림 == 객체,속성/기능
	전화 UI	  == 객체,속성/기능 123-1234-1234
	class Phone:
		send()
		recv()
		bell()
		comm()
		input()
		//Phone에 공통적으로 들어가 있는 기능들을 정의

캡슐화(encapsulation) : 실제로 구현 및 동작되는 부분에 데이터를 처리함에 있어 객체의 데이터에
	직접 접근할 수 없고 메소드(method, function)을 통해서만 가능하다.
	class Phone:
	public:
		기능/입력/출력/화면/통신...
		send()
		recv()
		bell()
		comm()
		input()...123-1234-1234
	private:
		데이터 123-1234-1234

상속성(inheritance) : 상속...기존 클래서 확장한 파생 클래스를 정의하는 것
	class IPhone: public Phone
		input()...button -> audio"siri"

다형성(polimorphism) : "오버라이딩"으로 다양한 형태로 나타날 수 있는 특징
	class Iphone: public Phone
		input...button->audio"siri"

객체(object)
...소프트웨어 시스템을 나누는 단위
	int/char/...struct student
	특성과 행위를 가지는 어떠한 실체...
	특성(attribute) : 해당 객체에 저장된 정보, 행위(behavior) : 객체가 행동/반응하는 방법
	ex) 자동차 객체의 특성 : 차체/엔진/스티어링힐/변속기/바퀴...등 부품을 가지고 있다.
		자동차 객체의 행위 : 전진/후진/좌회전/우회전/가속/정지 행위를 가지고 있음

객체간 소통:
자동차를 운전하기 위해서 명령을 보내는 상대객체(인스턴스화 한 객체)
행위 주체자가 (운전자)는 자동차 객체에 메세지를 보내기(호출)을 합니다.
*/

// struct + 추상화, 캡슐화 => 클래스


/*
클래스(class) : 유사한 특징화 행위를 갖는 객체를 표현하는 모형(틀, 설계) 혹은 템플릿
				관념을 표현한 것을 추상화한 것으로 클래스라고 합니다.
				모든 객체는 클래스를 기반으로 생성, 객체를 인스턴스(변수)라고 합니다.
				class student
				student person;
추상적인 데이터 타입
typedef struct Date
{ int year, month, day;} Date
struct _Date
{ int year, month, day;} 초기화 = year = month = day = 0 ?? 0xCCCC - 8563234+1
*/

/*
클래스와 구조체의 차이점
C << C++ 향상된 기능을 제공함
C++ 구조체는 멤버함수, 클래스를 가질 수 있으며 접근지정자{public, protected, private) 캡슐화가 가능
C++ 구조체/Class 구현하면 객체지향언어의 특징이 모호해짐
명백한 차이점
1. 클래스는 접근지정자가 default - private가 있다. // 구조체가 public
2. 클래스는 상속을 통한 객체지향이 구현가능
*/

class CDate
{
public:		//접근지정자 - 공통허용

	// 1. 생성자로 멤버변수를 지정하는 방법
	CDate()//디폴트 생성자..ctor
	{
		year = 0;
		month = 0;
		day = 0;
		
		std::cout << "CDate::ctor" << std::endl;
	}
	CDate(int yy, int mm, int dd) // 함수 오버로딩, 생성자 오버로딩
	{
			year = yy;
			month = mm;
			day = dd;
	}
	~CDate()//소명자..dtor
	{
		std::cout << "CDate::dtor" << std::endl;
	}
protected:	//접근지정자-너만

public:
	// 2. 함수로 멤버변수를 지정하는 방법
	void setDate(int yy, int mm, int dd)
	{
		year = yy;
		month = mm;
		day = dd;
	}
	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
	void displayDate() { std::cout << year << "년" << month << "월" << "일" << std::endl; }
private:	//접근지정자-나만
	int year, month, day;//멤버변수...데이터를 담는 그릇
	void privateFunction() {}
};

int main()
{
	{
		CDate date(2023,04,26);
		date.displayDate();
		date.setDate(2023, 05, 26);
		date.displayDate();
	}
}