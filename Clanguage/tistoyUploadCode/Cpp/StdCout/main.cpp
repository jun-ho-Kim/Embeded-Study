#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	
	//2.3 Ű �Է¹ޱ� 
	//���� 2.3 
	/*
	cout << "�ʺ� �Է��ϼ���>> ";
	int width;
	std::cin >> width;
	std::cout << "���̸� �Է��ϼ���>> " ;
	
	int heigth;
	std::cin >> heigth;
	
	int area = width * heigth;
	cout << "������ " << area << "\n"; 
	*/
	// >> ������
	// >> �����ڴ� ��Ʈ�������� ������(stream extraction operator)�� �Ҹ��� ���� �ǿ������� ��Ʈ�� ��ü�κ���
	//	�����͸� �о� ������ �ǿ����ڿ� ������ ������ �����Ѵ�. 
	//	��Ʈ�� ����  �����ڴ� ���� ������ ����Ʈ�ϴ� C++�� �⺻ ������������, <iostream> ��� ���Ͽ� ��Ʈ�� ���� �����ڷ�
	//	������(operator overloading) �Ǿ��ִ�. 
	
	//2.4 Ű����� ���ڿ� �Է�
	
	//C++���� ���ڿ��� ǥ���ϴ� ���
	//	1. C-��Ʈ�� - C���� ���ڿ��� ǥ���ϴ� ��� 
	//	2. string Ŭ���� - ���ڿ��� ��ÿ �ٷ�� ���, �����ϴ� ���
	
	// C-string�� �� ����(null string)�� ������ char �迭�̸� C ���� ����ϴ� ���ڿ� ����̴�.
	// C++������ C���� ȣȯ�� ������ C-string�� �״�� ����Ѵ�.
	// + C�� ���������� ���ڿ��� ���� ���� null string�� �־�� �Ѵ�. 
	//	�׷��� ���ڿ��� ���ڼ����� �ּ� 1�� Ŀ���ϸ� �׺��� �� Ŀ�� �������.
	//  c++ ���ڿ��� ���ڼ� +1 �̻��� ũ�Ⱑ ���� �ʴ� ��� �����Ͽ����� �߻��ϸ�
	// 	���� ���α׷��� �۵��ϴ��� �޸� �ּҿ� null string�� �ִ� ������ ����Ͽ� ���ϴ� ���� ������ ���� �� �ִ�. 
	
	char name[6] = "Hello"; 
	std::cout << "Hello is " << name << std::endl;
	
	// cin ��ü�� �������� white space�� ������ ��� white space������ ���ڿ��� �Է��� �޴´�.
	/*
	char yourName[100];
	std::cout << "����� �̸��� �Է����ּ���: "; 
	std::cin >> yourName; // �� �� �� 
	std::cout << "����� �̸��� " << yourName << "�Դϴ�."; // ����� �̸��� ���Դϴ�.
	 */
	// std::cin.getline() ��� �Լ��� ����ϸ� �� ������ �ذ��� �� �ִ�. 
	// std::cin.getline(char buf[], int size, char delimitChar)
	// buf: Ű����κ��� ���� ���ڿ��� ������ �迭
	// size: buf[] �迭�� ũ��
	// delimetChar : ���ڿ� �Է� ���� �����ϴ� ���� ����. 

	/*
	char yourName[100];
	std::cout << "����� �̸��� �Է����ּ���: "; 
	std::cin.getline(yourName, 100, '\n'); // �� �� �� 
	std::cout << "����� �̸��� " << yourName << "�Դϴ�."; // ����� �̸��� �� �� ���Դϴ�.
	*/

	// �� string Ŭ������ ����ϴ� ����� �ִ�.
	// string Ŭ������ C-string�� �ٸ��� ũ�⿡ ������ ����.
	// ���� string Ŭ������ ���ڿ� ����, ��, ������ �پ��� ���ڿ� ������ ���� ����Լ��� �����ڸ� �����Ͽ� ���ڿ��� ���� �ٷ� �� �ְ� ���ش�.

	string yourName;
	 
	std::cout << "����� �̸��� �Է����ּ���: "; 
	std::getline(cin, yourName); // �� �� �� 
	std::cout << "����� �̸��� " << yourName << "�Դϴ�."; // ����� �̸��� �� �� ���Դϴ�.
	// ���⼭ cin.getline�� �ƴ϶� getline() �Լ��� ����ߴµ� 
	//	getline() �� string ���̺귯���� ���ϰ� cin.getline()�� iostream ���̺귯���� ���Ѵ�. 
	
	/*
	std::cout<<"Hello\n";
	std::cout<<"�ȳ��ϼ���\n";
	
	//���� 2.3
	
	// cin�� �̿��� ���ڿ� �Է�
	 
	char name[100];
	std::cin.getline(name, 100, '\n');
	//std::cin >> name;
	
	std::cout << "name is " << name <<std::endl;
	
	for(int i=0; i<6;i++)
	{
		std::cout <<i << "- name is " << name[i] <<std::endl;
	}
	std::cout << "name2 is " << name <<std::endl;
	 
	*/
	
	/*
	//���� 2.5
	char password[11];
	std::cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���" << std::endl;
	while(true)
	{
		std::cout << "��ȣ>>";
		std::cin >> password;
		if(strcmp(password, "C++") == 0)
		{
			std::cout << "v���α׷��� ���� �����մϴ�." << endl;
			break;
		}	
		else
			std::cout << "��ȣ�� Ʋ���ϴ�~~" << std::endl; 
	} 
	*/
	
	/*
	//����2.7
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;
	
	cout << song + "�� �θ� ������";
	cout << "(��Ʈ : ù���ڴ� " << elvis[0] << ")?";
	getline(cin, singer);
	if(singer == elvis)
		cout << "�¾ҽ��ϴ�.";
	else
		cout << "Ʋ�Ƚ��ϴ�. " + elvis + "�Դϴ�." << endl; 
	 
	*/
	
	//https://kyu9341.github.io/C-C/2020/01/17/C++getline()/
	return 0;
}
