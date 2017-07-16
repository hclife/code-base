#include <iostream>
using namespace std;

class A {
public:
	A() {func();}
	virtual void func() {cout<<"A::func\n";}
};

class B:public A {
public:
	B() {func();}
	void func() {cout<<"B::func\n";}
	void g() {func();}
};

class C:public B {
public:
	C() {func();}
	void func() {cout<<"C::func\n";}
};

int main() {
	C c;
	c.g();
	return 0;
}
