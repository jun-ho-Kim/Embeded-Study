//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <float.h> 

int main()
{
    double d = 3.141592653589793238462643383279502884197169399375105082097494459230;

   printf("%c\n", 'A');
   printf("%s", "I love you\n");
   printf("Even if there`s a small chance, \
we owe this to everyone who`s not in this room to try\n");

   printf("\n");
   printf("%d %i %i %i\n", 1004, 1234, INT_MAX, UINT_MAX); // 1004 1234 2147483647 -1
   // %i는 sign int이기 때문에 UINT_MAX를 사용할 경우 overflow가 발생

   printf("\n");
   printf("%f %f %lf\n", 3.141592f, d, d); // 3.141592 3.141593 3.141593
   //%f는 출력할 때 내부에서 %d로 변환해서 사용, 그래서 %lf = %f는 같다.
   printf("%a %A\n", d, d); // 0x1.921fb54442d18p+1 0X1.921FB54442D18P+1
   printf("%e %E\n", d, d); // 3.141593e+00 3.141593E+00
   printf("%e %E\n", d, d); // 3.141593e+00 3.141593E+00

   printf("\n");
   printf("%g %g\n", 123456.789, 1234567.89); // 123457 1.23457e+06
   printf("%G %G\n", 123456.789, 1234567.89); // 123457 1.23457E+06
   printf("%g %g\n", 0.00012345, 0.000012345); // 0.00012345 1.2345e-05
   printf("%G %G\n", 0.00012345, 0.000012345); // 0.00012345 1.2345E-05

   printf("\n");
   printf("%o\n", 9); // 11
   printf("%p\n", &d); // 0000006C315FF6D0 // 메모리가 저장된 주소 출력
   
   printf("\n");
   printf("%x %X\n", 11, 11); // b B  // 16진수로 출력
   printf("%%\n", d); // % // Note the warnig. d is ignored.

   printf("\n");
   printf("%9d\n", 12345); //     12345 // d 앞에 숫자가 있으면 숫자의 자릿수를 채워줌
   printf("%09d\n", 12345); // 000012345 // d 앞에 0+숫자가 있으면 출력하는 숫자 앞에 0 자릿수를 채워줌
   printf("%.2f\n", 3.141592); // 3.14
   printf("%.20f %.20lf\n", d, d); // 3.14159265358979311600 3.14159265358979311600

   printf("\n");
   int n_printed = printf("Counting!");
   printf("%u\n", n_printed); // Counting!9 
   //printf("Counting!") 함수 호출 후 Counting! 문자열 길수 출력

   return 0;
}