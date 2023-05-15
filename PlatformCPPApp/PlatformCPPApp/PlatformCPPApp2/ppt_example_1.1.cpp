#include <iostream>

using namespace std;

class Animal
{
public: 
	Animal() { cout << "Aniaml::Ctor" << endl; }
	~Animal() { cout << "Aniaml::Dtor" << endl; }
	// virtual function pointer table
	// �θ�Ŭ������ ������ �� �� virtual Ű���尡 ������ �θ�Ŭ������ �ڽ�Ŭ������ Ž���ϰ� �ڽ�Ŭ������ �Լ��� ������ �װ��� ���

	//�������� �Ļ�Ŭ������ �ϳ��� Ž�� �� ȣ���Ѵ�.
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
	// 1. ���ο� 
	pDog = new Dog();
	pDog->speak();
	delete pDog;


	//Dog dog;

	//Animal* animal = new Dog(); // upcasting

	//animal->speak(); // This is Dog

	int z = 4;

	return 0;
}