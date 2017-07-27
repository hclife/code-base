#include <functional>
#include <iostream>
using namespace std;

std::function<int(int)> Functional;

// Normal Function
int TestFunc(int a)
{
	return a;
}

// Lambda Expression
auto lambda = [](int a)->int{return a;};

// Simulate function
class Functor
{
public:
	int operator()(int a)
	{
		return a;
	}
};

// Class Member Function and Static Function
class TestClass
{
public:
	int ClassMember(int a) {return a;}
	static int StaticMember(int a) {return a;}
};

int main()
{
	Functional=TestFunc;
	int result=Functional(10);
	std::cout<<"Normal Function:"<<result<<std::endl;

	Functional=lambda;
	result=Functional(20);
	cout<<"Lambda expression:"<<result<<endl;

	Functor testFunctor;
	Functional=testFunctor;
	result=Functional(30);
	cout<<"Simulate function:"<<result<<endl;

	TestClass testObj;
	Functional=std::bind(&TestClass::ClassMember,testObj,std::placeholders::_1);
	result=Functional(40);
	cout<<"Class member function:"<<result<<endl;

	Functional=TestClass::StaticMember;
	result=Functional(50);
	cout<<"Class static function:"<<result<<endl;

	return 0;
}
