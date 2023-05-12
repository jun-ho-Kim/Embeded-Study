#pragma once
#include <iostream>
#include <string>


// Object // 데이터와 기능을 출력해주는 기능
// 객체라는 개념을 프로그램 언어로 구현하는데 이때 사용하는 키워드가 클래스이다.
// // 클래스는 obect라는 개념을 문법으로 구현할 때 사용한다..
// Frined: name, address, age, height, weight

// 

class Frined
{

//멤버변수의 코딩스타일 _name or name_
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
	//클래스를 사용하는 경우
	Frined jj{ "Jack Jack","Uptown", 2, 30, 5 }; // 메모리를 차지하도록 정의해주는 것을 instanciation, instance
	//jj.name = "Jack Jack";
	//jj.age = 2;
	//jj.address "Uptown";
	print(jj.name, jj.address, jj.age, jj.height, jj.weigth);
	
	// 데이터와 기능이 묶여있는 것을 object라고 한다. struct에도 많은 객체지향 기법들을 다룰 수 있게 만들어주는 것이 class이다.
	jj.printf();
	

	vector<Frined> my_friends;
	my_friends.resize(2);

	for(auto &ele: my_friends)
		ele.printf();


	// 클래스를 사용하지 않는 경우
	string name;
	string address;
	int age;
	double height;
	double weigth;

	// 하나의 데이터만 넣는 경우
	print(name, address, age, height, weigth);

	vector <string> name_vec;
	vector <string> addr_vec;
	vector <int> age_vec;
	vector <double> height_vec;
	vector <double> weigth_vec;

	print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weigth_vec[0]);

	// 클래스를 사용하면 코드가 간결해지고 깔끔해진다.
	// 자바는 프로그래밍을 시작할 때 클래스부터 시작한다.
	return 0;
}