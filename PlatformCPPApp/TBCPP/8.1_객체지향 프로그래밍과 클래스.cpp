#pragma once
#include <iostream>
#include <string>


// Object // �����Ϳ� ����� ������ִ� ���
// ��ü��� ������ ���α׷� ���� �����ϴµ� �̶� ����ϴ� Ű���尡 Ŭ�����̴�.
// // Ŭ������ obect��� ������ �������� ������ �� ����Ѵ�..
// Frined: name, address, age, height, weight

// 

class Frined
{

//��������� �ڵ���Ÿ�� _name or name_
public: // access specifier (public, private, protected)
	string name;
	string address;
	int age;
	double height;
	double weigth;

	
	void printf()
	{
		cout << name << " " << address << " " << age << " " << height << " "
			<< weight << endl;
	}
};



void printf(const string& name, const string& address, const int& age, const double& height, const double& weight)
{
	cout << name << " " << address << " " << age << " " << height << " "
		<< weight << endl;
}
int main()
{	
	//Ŭ������ ����ϴ� ���
	Frined jj{ "Jack Jack","Uptown", 2, 30, 5 }; // �޸𸮸� �����ϵ��� �������ִ� ���� instanciation, instance
	//jj.name = "Jack Jack";
	//jj.age = 2;
	//jj.address "Uptown";
	print(jj.name, jj.address, jj.age, jj.height, jj.weigth);
	
	// �����Ϳ� ����� �����ִ� ���� object��� �Ѵ�. struct���� ���� ��ü���� ������� �ٷ� �� �ְ� ������ִ� ���� class�̴�.
	jj.printf();
	

	vector<Frined> my_friends;
	my_friends.resize(2);

	for(auto &ele: my_friends)
		ele.printf();


	// Ŭ������ ������� �ʴ� ���
	string name;
	string address;
	int age;
	double height;
	double weigth;

	// �ϳ��� �����͸� �ִ� ���
	print(name, address, age, height, weigth);

	vector <string> name_vec;
	vector <string> addr_vec;
	vector <int> age_vec;
	vector <double> height_vec;
	vector <double> weigth_vec;

	print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weigth_vec[0]);

	// Ŭ������ ����ϸ� �ڵ尡 ���������� ���������.
	// �ڹٴ� ���α׷����� ������ �� Ŭ�������� �����Ѵ�.
	return 0;
}