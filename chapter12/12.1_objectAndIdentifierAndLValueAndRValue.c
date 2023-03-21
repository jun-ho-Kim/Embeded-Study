#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	/*
		Object(객체)
		- "An Object is a simply a block of memeory that can store a value." (KNK p.487)
		- Object has more develped in C++ and object Oriented Programming (OOP)

		Identifiers(식별자)
		- Names for variables, functions, macros, and other entities (KNK p.25)

		변수의 메모리 주소를 Object, Object의 이름이, 변수의 이름이	Identifier이다.
	*/

	int var_name = 3; // creates an object called 'var_name';

	int* pt = &var_name; // pt is an identifier
	*pt = 1; // *pt is not an identifier. *pt designates an object. (expresion)

	
	int arr[100]; // arr is an identifier. Is arr an object? No. arr은 첫 원소의 메모리 주소이며, 메모리 주소 공간을 갖는 Obejct는 아니다.
	arr[0] = 7; // arr[0] is an object and expression.
	
	/*
		lvalue is an expression 'referring' to an obejct. (K&R p.197)
		// referring : 다른 방식으로 값을 가져온다. 또 다른 이름처럼 사용한다.

		L-value : left side of an assignment
		R-value : right side, varible, constant, expressions (KNK p. 67)

		L-value는 메모리 공간을 가지고 있다. 그리고 값을 대입할 수 있다.
		R-value는 값만 가져온다.
	*/

	var_name = 3; //modifiable lvalue
	int* temp = var_name;
	temp = 1 + 2;

	pt = &var_name;
	int* ptr = arr;
	*pt = 7; // *pt is not an identifier but an modifiable lvalue expression.

	int* ptr2 = arr + 2 * var_name; // address rvalue
	*(arr + 2 * var_name) = 456; // lvalue expression

	const char* str = "Constant string"; // string is a modifiable lvalue.
	str = "Second string"; // "Constant string" = "Second String" // impossible
	// str[0] = 'A'; // Error
	// puts(str);

	char str2[] = "String in an array";
	str2[0] = 'A'; // OK
	//puts(str2);

	/*
		Identifiers have scope.
		Objects have storage duration.
		Variable and functions have one of the following linkages:
			external linkage, internal linkage, or no linkage.
	*/




	return 0;
}