#include<iostream>
using namespace std;

class Base
{
public:
	virtual void f(float x)
	{
		cout<<"Base::f(float)"<< x <<endl;
	}
	void g(float x)
	{
		cout<<"Base::g(float)"<< x <<endl;
	}
	void h(float x)
	{
		cout<<"Base::h(float)"<< x <<endl;
	}
};
class Derived : public Base
{
public:
	virtual void f(float x)
	{
		cout<<"Derived::f(float)"<< x <<endl;   //override
	}
	void g(int x)
	{
		cout<<"Derived::g(int)"<< x <<endl;     //hide
	}
	void h(float x)
	{
		cout<<"Derived::h(float)"<< x <<endl;   //hide
	}
};
int main(void)
{
	Base b;
	Derived d;
	Base *pb = &d;
	Derived *pd = &d;
	// Good : behavior depends solely on type of the object
	pb->f(3.14f);   // Derived::f(float) 3.14
	pd->f(3.14f);   // Derived::f(float) 3.14

	// Bad : behavior depends on type of the pointer
	pb->g(3.14f);   // Base::g(float)  3.14
	pd->g(3.14f);   // Derived::g(int) 3 

	// Bad : behavior depends on type of the pointer
	pb->h(3.14f);   // Base::h(float) 3.14
	pd->h(3.14f);   // Derived::h(float) 3.14

	// Check
	pb=&b;
	pb->f(3.12f);
	return 0;
}
