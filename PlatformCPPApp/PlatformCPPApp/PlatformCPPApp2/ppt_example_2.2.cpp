#include <iostream>

using namespace std;

// ���� �Լ��� ����ϴ� ����?
// Ʋ�� ���س��� �ش� �Լ��� �ڽ� Ŭ���� ���� �������ϱ� ���ؼ� 

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