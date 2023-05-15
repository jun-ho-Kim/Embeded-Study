#include <iostream>

using namespace std;

class Animal
{
public: 
	Animal() { cout << "Aniaml::Ctor" << endl; }
	~Animal() { cout << "Aniaml::Dtor" << endl; }
	// virtual function pointer table
	// 부모클래스로 접근을 한 후 virtual 키워드가 있으면 부모클래스와 자식클래스를 탐색하고 자식클래스의 함수가 있으면 그것을 사용

	//동적으로 파생클래스를 하나씩 탐색 후 호출한다.
	virtual void speak()
	{
		cout << "This is an animal." << endl;
	}
};

//
class Dog : public Animal
{
public:
	Dog() { cout << "Dog::Ctor" << endl; }
	~Dog() { cout << "Dog::Dtor" << endl; }

	void speak()
	{
		cout << "This is a dog." << endl;
	}
};

int main()
{
	Dog dog;
	dog.speak();
	
	
	Dog* pDog = nullptr;
	// 1. 새로운 
	pDog = new Dog();
	pDog->speak();
	delete pDog;


	//Dog dog;

	//Animal* animal = new Dog(); // upcasting

	//animal->speak(); // This is Dog

	int z = 4;

	return 0;
}