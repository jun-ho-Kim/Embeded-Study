#include <iostream>

using namespace std;

// 가상 함수를 사용하는 이유?
// 틀은 정해놓고 해당 함수를 자식 클래스 별로 재정의하기 위해서 

class Animal
{
public:
	virtual void makeSound()
	{
		std::cout << "The animal makes a sound.\n";
	}
};

class Dog : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "The dog barks.\n";
	}
};

class Cat : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "The cat meows.\n";
	}
};

int main()
{
	Animal* animal1 = new Dog();
	Animal* animal2 = new Cat();
	animal1->makeSound(); // The dog barks.
	animal2->makeSound(); // The cat meows.
	delete animal1;
	delete animal2;

	return 0;
}