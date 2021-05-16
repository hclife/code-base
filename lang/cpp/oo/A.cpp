#include <iostream>
using namespace std;

class A {
public:
	int a,b;
	A() {cout<<"A Constructor"<<endl;}
};

class B:public A {
public:
	int c,d;
	B() {cout<<"B Constructor"<<endl;}
};

int main() {
	B b;
	return 0;
}
