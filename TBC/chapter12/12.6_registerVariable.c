#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void temp(register int r)
{
	// do something with r
}
int main()
{
	register int r; // 자료형 앞에 register를 붙이면 가급적이면 register에 올라가게 해달라고 한다.
	r = 123;

	// 임베디다나 특수한 경우가 아닌 경우에는 register를 잘 사용하지 않는다.
	// GPU, 분산처리, 병렬처리, SIMD, 인라인으로 어셈블리 사용(C++) 등을 사용
	// 임베디드를 할 때, 딥한 하드웨어를 만지는 경우에 사용한다.

	//printf("%p\n", &r);
	int* ptr = &r;
	//레지스터에 있는 변수의 주소를 가져올 수 없다. // address of operator 사용 불가, 포인터 주소는 메모리에 저장되어 있기 때문에

	return 0;
}