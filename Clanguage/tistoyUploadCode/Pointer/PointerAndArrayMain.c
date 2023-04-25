#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//변수를 선언한다는 것은 변수의 이름을 통해서 메모리공간을 사용하는 것이다.
		//프로그램을 효율적으로 짜기 위해서는 메모리가 어디에 위치해 있고 얼마나 많은 메모리를 사용해야하는지 알아야 한다. 
		// 크기가 큰 프로그램을 만들어서 많은 양의 데이터를 사용하면 많은 양의 데이터를 복사해서 여러 곳에서 사용하는 것은 낭비이다.
			// 이렇게 하면 데이터를 복사하는데 시간도 걸리고 메모리도 낭비된다.
			// 데이터가 어디에 있는지 알고 프로그램을 작성하면 프로그램이 효율적으로 작동할 것이다.
 
	//포인터는 메모리 주소를 저장하여 가리키는 /*간접적*/으로 역활을 한다.
	//포인터를 선언해줄 때는  아래와 같이 변수 명 앞에 *를 붙여 사용한다.
	int a = 7; 
	int *a_ptr = &a;
	
	double b = 2;
	double *b_ptr = &b;
	
	printf("a variable address is %d\n", a_ptr); // 6487564
	printf("b variable address is %d\n", b_ptr); // 6487552
	
	//간접 참조 연산자 *
	printf("a pointer value is %d\n", *a_ptr); // a pointer value is 7
	printf("b pointer value is %.1lf\n", *b_ptr); // b pointer value is 2.0
	
	printf("a pointer is %d byte\n", sizeof(*a_ptr)); // a pointer is 4 byte
	printf("b pointer is %d byte\n", sizeof(*b_ptr)); // b pointer is 8 byte
	
	double c = 4;
	int *c_ptr = &c;
	printf("c pointer value is %f\n", *c_ptr); // c pointer value is 0.000000
	// 만약 포인터 변수 타입 크기보다 큰 변수를 할당해주면 값이 0으로 나온다. 
	
	int d = 9;
	double *d_ptr = &d;
	printf("d pointer value is %d\n", *d_ptr); // d pointer value is 9
	// 그렇다면 포인터 변수 타입 크기보다 작은 변수를 할당해주면 값이 잘 나오지만 포인터 변수와 이에 할당하려는 변수에 크기를 맞춰주자.. 
	
	// 여기서 포인터 변수에 변수 a의 주소를 저장하는데 a 앞에 &를 붙여 사용한다.
	// 포인터 변수의 크기는 int로 할당했으면 4byte double로 할당했으면 8byte가 할당된다. 
	
	//참고로 포인터의 초기값을 설정하지 않는 경우에는 NULL 값으로 초기화 해주는 것이 기본이라고한다.
	// 그 이유는 포인터 값이 NULl인 경우에 예외처리가 수월하기 때문이다.
	 
	double *e_ptr = NULL; // 만약 초기화를 해주지 않으면 쓰레기 값이 들어간다. 
	
	printf("e_ptr is %d", e_ptr); 
	
	if(e_ptr == NULL)
	{
		printf("e_ptr is NULL\n");
	}
	
	// const	
	// const 지정 시 포인터의 값은 바꿀 수 없다.
	// 포인터 왼쪽에 붙은 const는 값을 변경할 수 없다.
	// 포인터 오른쪽에 붙은 const는 다른 포인터 변수에 할당이 안된다.
	const int arr[10] = { 456, 459, 465, 472, 474 };
	const int* f_cstprt = &arr;
	printf("f_cstprt is %d\n", f_cstprt);
	
	//f_cstprt = &a;

	
	printf("f_cstprt is %d, value is %d\n", f_cstprt, *f_cstprt);
	printf("f_cstprt is %d, value is %d\n", f_cstprt, *++f_cstprt);
	
	int* const g_cstprt = &arr;
	//*g_cstprt = 11; // Error

	
	// *g_cstprt++ //Error
	printf("g_cstprt is %d, value is %d\n", g_cstprt, *g_cstprt);
	
	printf("g_cstprt is %d, value is %d\n", g_cstprt, *g_cstprt);
	 
	return 0;
}
