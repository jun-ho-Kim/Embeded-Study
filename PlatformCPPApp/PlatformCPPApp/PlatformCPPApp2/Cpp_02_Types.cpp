#include <iostream>

int main()
{
	std::cout << "Cpp_02_Types.cpp" << std::endl;
	//��� �Լ��� �߰�ȣ�� ����� �ڿ���(���� ��)�� �޸𸮿� �ö󰬴ٰ� } �Ŀ� �����´�.
	//scope�� {} ������ �۵��Ѵ�.

	std::cout << "static_cast<>" << std::endl;
	if (0)
	{
		//c-style
		int a = 10;
		double b = (double)a; // ����� ǥ��

		b = b + 123456;
		a = (int)b; // ����� ǥ�� // a=b �Ͻ��� ǥ��

		//c++ style
		int c = 10;
		double d = static_cast<double>(c); // i want to Python!!
		d = d + 0.123456;
		c = static_cast<int>(d);
		// c++�� �Ѿ����鼭 �� ��ٷο�����.

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
		//�Ʒ��� ���� ���� ���� �� lvalue Error �߻�
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