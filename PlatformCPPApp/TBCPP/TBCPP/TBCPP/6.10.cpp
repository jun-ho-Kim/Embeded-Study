#include <iostream>
using namespace std;

const char* getName()
{
	return "jackjack";
}

int main()
{
	//char name[] = "Jack Jack"; // Jack Jack

	// char *name = "Jack Jack"; // Error

	/*
	const char *name = "Jack Jack";
	const char *name2 = "Jack Jack";
	//const char* name = getName();	//���� ��
	//const char* name2 = getName();//���� ��
	// ���ڿ� ������ �տ� const�� ���̸� ���ڿ��� ��ȣ�� ����� ����� �� ����

	//char name[] = "Jack Jack";

	cout << (uintptr_t)name << endl;	//3250992
	cout << (uintptr_t)name2 << endl;	//3250992
	*/

	int int_arr[5] = { 1,2,3,4,5 };
	char char_arr[] = "Hello, World";
	const char* name = "jackjack";

	cout << int_arr << endl;	// 00B3FA94
	cout << char_arr << endl;	// Hello, World
	cout << name << endl;		// jackjack
	// ����: cout�� ���ڿ� �����ʹ� Ư���� null character������ ���� ��ȯ�Ѵ�.()

	char c = 'Q';
	cout << &c << endl; //Q��������0�y 
	// cout�� ���ڿ� �����͸� ���� �о���� ������ null character������ ���� �о�� Q �ڿ� ���� ��µȴ�.

	char d = 'A';

	//cout�� ���ڿ� �����͸� ���� �о���� ������ null character������ ���� �о�� Q �ڿ� ����
	//cout�� ����ڵ��� ���ϰ� ����ϰ� �ϱ� ���ؼ� �̷��� �ۼ��Ͽ���.
	//���߿� ��� std ���̺귯���� ����ִ� string�̳� stdarray�� ���� �ȴ�.

	return 0;
}