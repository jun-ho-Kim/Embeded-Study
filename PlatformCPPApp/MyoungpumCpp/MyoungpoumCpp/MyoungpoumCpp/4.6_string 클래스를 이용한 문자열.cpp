#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*
	// ���� 4.11
	// ��Ʈ�� ����
	string str; // �� ���ڿ��� ���� ��Ʈ�� ��ü ����
	string address("����� ���ϱ� �Ｑ�� 389");
	string copyAddress(address);

	char text[] = { 'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0' }; // C-��Ʈ��
	string title(text);  // "Love C++" ���ڿ��� ���� ��Ʈ�� ��ü ����

	cout << str << endl; // 
	cout << address << endl; // ����� ���ϱ� �Ｑ�� 389
	cout << copyAddress << endl; // ����� ���ϱ� �Ｑ�� 389
	cout << title << endl; // Love C++
	*/
	int z = 4;

	//���� 4.12
	string name[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "�̸� >>";
		getline(cin, name[i], '\n');
	}

	string latter = name[0];

	for (int i = 1; i < 5; i++)
	{
		cout << "name " << i << "is" << name[i] << endl;;
		if (latter < name[i])
			latter = name[i];
	}

	cout << "�������� ���� �ڿ� ������ ���ڿ��� " << latter << endl;

	return 1;
}
