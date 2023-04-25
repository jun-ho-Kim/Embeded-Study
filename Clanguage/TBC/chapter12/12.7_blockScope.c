#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count()
// int* count() // 자동변수의 포인터 주소를 return 하는 것은 올바르지 않다. 왜냐하면 주소값은 함수 블록 안에서 사용되어지다가 함수가 끝나면 사용하지 않기 때문이다.
{
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//return &ct;
}

void static_count() // Static with no Linkage
// int * static_count() // static variable의 포인터 주소값을 return 해주는 경우는 종종 있다.
{
	static int ct = 0; // initialized only once!
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	// return &ct;
}

void counter_caller()
{
	count();
}

void static_counter_caller()
{
	static_count();
}

int func(static int i) // Warning (Error in GCC)
{
	// 함수가 시작될 때 함수는 Stack frame이 배정이 된다.
	// 파라미터 변수는 사실상 함수가 실행이 될 때 메모리가 배정을 받는데 파라미터에 static을 선언하는 것은 앞뒤가 안 맞는다.
	// (static은 프로그램이 실행될 때 메모리 공간을 고정, 함수는 함수 실행되는 과정에서만 실행)
}

int main()
{
	count();			// count = 0 11533008
	count();			// count = 0 11533008 // 위 함수와 같은 메모리 공간을 사용하고 있지만 함수가 끝나면 사라지기 때문에 static이 아니다.
	counter_caller();	// count = 0 11532796
	

	static_count();			// static count = 0 12296504
	static_count();			// static count = 1 12296504
	static_counter_caller();// static count = 2 12296504
	 
	return 0;
}