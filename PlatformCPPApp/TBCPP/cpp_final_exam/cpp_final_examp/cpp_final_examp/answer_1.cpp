// 문제 1
//1. C++ 표준 입출력 스트림인 cout << 과 cin >> 을 이용하여 아래 사양에 맞는 입력과 출력의 코드를 작성하고 출력물 화면을 저장하시오.
//각 변수를 표시하는 개발툴 화면인 조사식 화면을 저장하시오.
//(음영부분 - 출력, 나머지 - 입력. char, int 등 자료형으로 코드 기술)

#include <string>
#include <iostream>

int main()
{
    std::string name = "";
    int age(0);
    std::string link_url;

    std::cout << "이름을 입력해주세요 >> ";

    std::cin >> name;

    std::cout << name << "님 안녕하세요~" << std::endl;

    std::cout << name << "님의 나이를 입력해주세요 >> ";

    std::cin >> age;

    std::cout << name << "님의 나이는 " << age << "입니다." << std::endl;

    std::cout << "Link URL을 입력해주세요 >>" << std::endl;

    std::cin >> link_url;

    std::cout << name << "님의 나이는 " << age << "이고 link url은 " << link_url << "입니다" << std::endl;

    int z = 3;

}
