#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	/*
		string to integer, double, long
		atoi(), atof(), atol()
	*/
	if (argc < 3)
		printf("Wrong Usage of %s\n");
	else
	{
		/* Example 1 */
		int times = atoi(argv[1]);
		for (int i = 0; i < times; i++)
			puts(argv[2]);

		/* Example 2 */
		printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
	}	

	/*
	string to long, unsigned long, double
	strtol(), stroul(), strtod()

	strtod() converts base 10 only
	*/

	//char str1[] = "1024Hello";
	//char* end;
	//long l = strtol(str1, &end, 10);
	//printf("%s %ld %s %d", str1, l, end, (int)*end); // 1024Hello 1024 Hello 72
	// strtol()는 string을 long을 변경해준다. String은 따로 분리해 두번째 변수(&end)에 넣어준다.


	//char str2[] = "1024Hello";
	//char* end;
	//long l = strtol(str2, &end, 16);
	//printf("%s %ld %s %d", str2, l, end, (int)*end); // 1024Hello 4132 Hello 72
	// 16진수로 변경하는 경우에는 문자(A~F)를 숫자로 바꾸는 경우가 생길 수 있다.

	/*
		Numbers to strings
		Use sprintf() instead of itoa(), ftoa()
		itoa()와 ftoa()는 표준이 아니다. 그러므로 사용을 권장하지 않는다.
		itoa()와 ftoa() 함수 대신에 sprintf()를 사용하자.
	*/

	//char temp[100];
	//
	//puts(_itoa(10, temp, 16));

	//sprintf("temp", "%x", 10);
	//puts(temp);

	return 0;
}