// ������ �̸��� ���� �Լ��� ���� �� ���� ���� �Լ� �����ε��̶�� �Ѵ�.
// �Լ� �����ε��� ��� ����ϴ��� ��������, ������ �˾ƺ���.
// ������ ���ڴ� �ٸ��� �����ϴ� ����� ����� �� �Լ� �����ε��� ����� �� �ִ�.
#include <iostream>
using namespace std;

void getRandom(int &value) {}

void getRandom(double& value) {}

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

// �Ű������� �ٸ��� �̸��� ���Ƶ� �ٸ� �Լ�ó�� ó���ϰ� 
// �־��� ���ڿ� �Ű������� ���� ������ ���� �Լ��� ã�� ��������ִ� ���̴�.
// �̰� �������� �� ������ �Ǿ�����.
// �Ķ���Ͱ� ���� �̸��� ������ ������ �߻��Ѵ�.
// (return Ÿ�Ը� �ٸ��� �Ķ���Ϳ� �̸��� ���� ��쿡�� ������ �߻��Ѵ�.

// typedef�� �������� �ص� print�Լ����� ���� Ÿ������ �Ű������� �޾� ���� �� ������ �߻�
typedef int my_int;

void print(int x) {}
void print(my_int x) {}

void printA(unsigned int x) {}
void printA(float x) {}

int main()
{
	add(1, 2);
	add(3.0, 4.0);

	int x;
	// �̷��� �ڵ带 �ۼ��ϸ� �Լ��� ������ �ϴ��� �� �� ����.
	// (������ ���ڸ� ������ void�� ������ �������־ ���ڸ� �������ִ� ȿ���� �ִ�.)
	getRandom(x); 

	//int x = getRandom(x); //Error // ���̽� ���

	// �Լ������ε��� �������� ���� �Ű������� ������ ���� �߻�
	//add("a");

	// �Ű������� ��ȣ�ϰ� �����ϴ� ���
	//printA('a') -> printA((unsigned int )'a');
	//printA(0); -> printA(0u);
	//printA(3.14592) -> printA(3.14592f);
	printA(0u);
}