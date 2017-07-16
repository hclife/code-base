#include <iostream>
using namespace std;

class A {
public: virtual ~A() {cout<<"A destructor\n";}
};

class B:public A {
public: virtual ~B() {cout<<"B destructor\n";}
};

int main() {
	A *a=new B;
	delete a;

	B *b=new B;
	delete b;

	return 0;
}
