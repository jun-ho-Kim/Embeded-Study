// 동일한 이름을 갖는 함수를 여러 개 같는 것을 함수 오버로딩이라고 한다.
// 함수 오버로딩을 어디에 사용하는지 주의할점, 단점을 알아보자.
// 들어오는 인자는 다른데 수행하는 기능이 비슷할 때 함수 오버로딩을 사용할 수 있다.
#include <iostream>
using namespace std;

void getRandom(int &value) {}

void getRandom(double& value) {}

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

// 매개변수가 다르면 이름이 같아도 다른 함수처럼 처리하고 
// 주어진 인자와 매개변수가 가장 조합이 좋은 함수를 찾아 실행시켜주는 것이다.
// 이건 컴파일할 때 결정이 되어진다.
// 파라미터가 같고 이름도 같으면 에러가 발생한다.
// (return 타입만 다르고 파라미터와 이름만 같은 경우에도 에러가 발생한다.

// typedef로 눈속임을 해도 print함수들은 같은 타입으로 매개변수를 받아 실행 시 에러가 발생
typedef int my_int;

void print(int x) {}
void print(my_int x) {}

void printA(unsigned int x) {}
void printA(float x) {}

int main()
{
	add(1, 2);
	add(3.0, 4.0);

	int x;
	// 이렇게 코드를 작성하면 함수가 리턴을 하는지 알 수 없다.
	// (참조로 인자를 받으면 void로 리턴을 지정해주어도 인자를 리턴해주는 효과가 있다.)
	getRandom(x); 

	//int x = getRandom(x); //Error // 파이썬 방식

	// 함수오버로딩에 지정되지 않은 매개변수를 넣으면 에러 발생
	//add("a");

	// 매개변수를 모호하게 지정하는 경우
	//printA('a') -> printA((unsigned int )'a');
	//printA(0); -> printA(0u);
	//printA(3.14592) -> printA(3.14592f);
	printA(0u);
}