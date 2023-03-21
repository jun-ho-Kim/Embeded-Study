//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	// 관계 연산자를 사용하면서 주의해야할 점
	int i;
	//i = 5; // 할당
	//i == 5; //비교
	//5 = i; // 5가 lvalue가 아니라서 에러 발생
	//5 == i // 비교라서 에러가 발생 안함

	//_Bool은 기존에 사용자들이 bool타입을 사용했기 때문에 충돌날 것을 우려하여 _Bool로 이름을 명명함
	_Bool boolean_true = (2 > 1);
	_Bool boolean_false = (1 > 2);
	//C에서 _Bool 타입은 정수형으로 처리한다.
	printf("True is %d\n", boolean_true);
	printf("False is %d\n", boolean_false);

	printf(boolean_true ? "true" : "false");
	printf("\n");
	printf(boolean_false ? "true" : "false");

	//아래와 같이 bool 타입을 사용할 수 있다. 
	//헤더에 #include <stdbool.h>를 추가해주자.
	//C에서는 bool 타입과 true와 false는 예약어가 아니다. 전처리기(#define)를 사용하여 명시해주는 것이다.
	//(C++에서는 bool과 true, false가 예약어이다.)
	bool bt = true;
	bool bf = false;

	printf("\n");
	printf("True is %d\n", bt);
	printf("False is %d\n", bf);


	return 0;
}