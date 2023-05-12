#pragma once

#include <iostream>
using namespace std;

//class A
//{
//public:
//	A() {}
//	~A() {}
//	int sum(int a, int b) { return a + b; }
//};
//
//class B
//{
//public:
//	B() {}
//	~B() {}
//	int sum(int a, int b) { return a + b; }
//	int mul(int a, int b) { return a * b; }
//};

int person1_sum(int a, int b) { return a + b; }
int person2_sum(int a, int b) { return a + b; }
int person2_mul(int a, int b) { return a * b; }

//person 1,2 -> enter company -> group working
//any -> sum()...mul()...수정...person 1,2 angry
// staff x -> super sw engineer
class IArithmetic
{
public: //  every body
	virtual int sum(int a, int b) { return 0; }
	virtual int sub(int a, int b) { return 0; }
	virtual int mul(int a, int b) { return 0; }
	virtual int div(int a, int b) { return 0; }
	virtual int mat(int a, int b) = 0;
protected: // only you
private: //only me
};


class CArithmetic  : IArithmetic
{
public: //  every body
	int sum(int a, int b) { 
		cout << "CArithmetic::sum -Integral" << endl;
		return a + b; 
	}
	int mul(int a, int b) { 
		cout << "CArithmetic::mul -Integral" << endl;
		return a * b; 
	}
	int mat(int a, int b) override
	{
		cout << "CArithmetic::mat" << endl;
		return 0;
	}
protected: // only you
private: //only me
};
//person1,2 -> out...


class CAnyArith : public CArithmetic
{
public: //  every body
	int sum(int a, int b) { 
		cout << "CAnyArith::sum -Integral" << endl;
		return a + b; 
	
	} // 적분 - Ingral
	int sub(int a, int b) {
		cout << "CAnyArith::sub" << endl;
		return a - b; 
	} // 함수 추가
	//int mul(int a, int b) { return a * b; }
	int div(int a, int b) { 
		cout << "CAnyArith::mul" << endl;
		return a / b; 
	} // 함수 추가
	int mat(int a, int b) override
	{
		cout << "CAnyArith::mat" << endl;
		return 0;
	}
};

// ------------- class A : 부모
struct IA
{
	void* __vfptr = nullptr; // hidden, virtual
	int a;
};
// ------------- class B : 자식
struct B
{
	void* __vfptr = nullptr; // hidden, virtual
	IA Ia; // 상속...class B + public A

	int b;

};

int main()
{
	B b;			// 파생클래스 B
	//b.ptr = (IA*) & b.Ia;	// 파생클래스 B -> 부모클래스 A로 접근가능한 상태
	b.__vfptr = &b.Ia;
	IA* pa = reinterpret_cast<IA*>(&b.__vfptr);
	b.__vfptr = reinterpret_cast<IA*>(b.__vfptr);
	pa->__vfptr = &b;


	if (true)
	{
		CArithmetic artith;

		// person1 vs person2 -> 코드 중복 발생? 어떻게 개선할까?
		//cout << "person1_sum = " << person1_sum(1, 2) << endl;
		//cout << "person2_sum = " << person2_sum(1, 2) << endl;
		//cout << "person2_mul = " << person2_mul(3, 4) << endl;

		//cout << "person1_sum = " << artith.sum(1, 2) << endl;
		//cout << "person2_sum = " << artith.sum(1, 2) << endl;
		//cout << "person2_mul = " << artith.mul(1, 2) << endl;

		CAnyArith arith_any;
		cout << "any_sum = " << arith_any.sum(1, 2) << endl;
		cout << "any_sub = " << arith_any.sub(1, 2) << endl;
		cout << "any_mul = " << arith_any.mul(1, 2) << endl;
		cout << "any_div = " << arith_any.div(1, 2) << endl;

		//super sw enginneer // person 1, 2
		//IArithmetic *arth_any = new CAnyArith();
		//동적할당을 할 때 객체의 최상위 계층을 가지고 할 수 있다.
		// 맵을 가지고 upcasting 부모클래스로 하여 다시 자식 클래스로 내려간다??
		// 부모클래스는 저장되지 않는다??
	}
	/*
	if (false)
	{
		A a;
		B b;
		cout << "class A::sum" << a.sum(1, 2) << endl;
		cout << "class B::sum" << b.sum(1, 2) << endl;
		cout << "class B::mul" << b.mul(3, 4) << endl;
	}
	*/

	//struct A { int a; }; // class A
	//struct B { int b; }; // class B ... class B : public A

	//struct B // class B
	//{
	//	struct A // class A
	//	{
	//		int a;
	//	};
	//	int b;
	//};

	//A* a = new A;
	//B* b = new B;
	//a->a = 10;
	//b->b = 10;
	//delete a;
	//delete b;

}

