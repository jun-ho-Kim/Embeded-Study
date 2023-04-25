#include <iostream>

int main()
{
	std::cout << "Cpp_02_Types.cpp" << std::endl;
	//모든 함수와 중괄호에 선언된 자원들(변수 등)이 메모리에 올라갔다가 } 후에 내려온다.
	//scope가 {} 에서만 작동한다.

	std::cout << "static_cast<>" << std::endl;
	if (0)
	{
		//c-style
		int a = 10;
		double b = (double)a; // 명시적 표헌

		b = b + 123456;
		a = (int)b; // 명시적 표현 // a=b 암시적 표현

		//c++ style
		int c = 10;
		double d = static_cast<double>(c); // i want to Python!!
		d = d + 0.123456;
		c = static_cast<int>(d);
		// c++로 넘어어오면서 더 까다로워졌다.

		char cNum = 'a';
		int* pNum = nullptr;
		pNum = (int*)(&cNum); //c-style compile ok
		//pNum = static_cast<int*>(&cNum); //cpp-style complie error
		pNum = reinterpret_cast<int*>(&cNum); // cpp - style complie ok
		*pNum = 5;

		int aaa = 0;
	}

	std::cout << "const_cast<>" << std::endl;

	{
		const char msg[] = "error"; //" "  - string, ' ' - char
		char* m_msg = const_cast<char*>(msg);
		std::cout << msg << std::endl;
		/*
		//아래와 같이 직접 대입 시 lvalue Error 발생
		msg[0] = 'o';
		msg[1] = 'k';
		msg[2] = ' ';
		msg[3] = ' ';
		msg[4] = ' ';
		*/

		m_msg[0] = 'o';
		m_msg[1] = 'k';
		m_msg[2] = ' ';
		m_msg[3] = ' ';
		m_msg[4] = ' ';

		std::cout << msg << std::endl;
	} 

	return 1;
}