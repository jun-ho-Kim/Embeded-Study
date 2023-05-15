#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void makeSound() = 0;
};

class Dog : public Animal
{
public:
	void makeSound() override
	{
		cout << "The dog bakrs.\n";
	}
};

int main()
{
	Animal* animal = new Dog();
	animal->makeSound();
	delete animal;

	return 0;
}