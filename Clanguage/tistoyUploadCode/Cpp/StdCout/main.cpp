#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*
	std::cout<<"Hello\n";
	std::cout<<"�ȳ��ϼ���\n";
	
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
	 
	
	return 0;
}
