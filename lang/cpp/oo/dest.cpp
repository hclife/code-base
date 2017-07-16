#include <iostream>
using namespace std;

class A {
public: ~A() {cout<<"A destructor\n";}
};

class B:public A {
public: ~B() {cout<<"B destructor\n";}
};

int main() {
	A *a=new B;
	delete a;

	B *b=new B;
	delete b;

	return 0;
}
