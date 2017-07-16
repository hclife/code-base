#include <iostream>
using namespace std;

class X {
public:
	virtual void f() {cout<<10<<' ';}
	void g() {cout<<20<<endl;}
};

class Y:public X {
public:
	void f() {cout<<30<<' ';}
	void g() {cout<<40<<endl;}
};

int main() {
	Y y;
	X *x=&y;
	x->f();
	x->g();
	return 0;
}
