#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*
	std::cout<<"Hello\n";
	std::cout<<"안녕하세요\n";
	
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
	
	//예제2.7
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;
	
	cout << song + "를 부른 가수는";
	cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";
	getline(cin, singer);
	if(singer == elvis)
		cout << "맞았습니다.";
	else
		cout << "틀렸습니다. " + elvis + "입니다." << endl; 
	 
	
	return 0;
}
