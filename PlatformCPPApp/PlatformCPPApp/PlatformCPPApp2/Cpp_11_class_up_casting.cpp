#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Snack
{
public:
	Snack() { std::cout << "Snack::Ctor" << std::endl; }
	~Snack() { std::cout << "Snack::Dtor" << std::endl; };
	void SetStatus() { this->_status = "opened"; }
	void SetSnack(std::string snackName)
	{
		this->_name = snackName;
		this->_status = "closed";
	}
	void display() { std::cout << "Name : " << _name << "\t Status : " << _status << std::endl; }
	Snack* GetInstance() { return this; }
	std::string GetName() { return /*this->*/_name; }
private:
	std::string _name, _status;
};

// python
/*
class Snak
{
public:
	Snak() { std::cout << "Snack::Ctor" << std::endl; }
	~Snak() { std::cout << "Snack::Dtor" << std::endl; };
	void SetStatus(self) { this->_status = "opened"; }
	void SetSnack(self, std::string snackName)
	{
		this->_name = snackName;
		this->_status = "closed";
	}
private:
	std::string _name, _status;
};
*/

class SnackA : public Snack
{
	// 함수 재정의가 아님
	SnackA() { SetSnack("SnackA"); }
};


class SnackB : public Snack
{
	// 함수 재정의가 아님
	SnackB() { SetSnack("SnackB"); }
};



int main()
{
	//if (false)
	{
		Snack snack;
		snack.display();
		snack.SetSnack("초콜렛");
		std::cout << "Name : " << snack.GetName() << std::endl;
		snack.display();
		snack.SetStatus();
		snack.display();
	}

	{
		SnackA snack;
		snack.display();
		snack.SetSnack("초콜렛");
		std::cout << "Name : " << snack.GetName() << std::endl;
		snack.display();
		snack.SetStatus();
		snack.display();
	}

	return 1;
}