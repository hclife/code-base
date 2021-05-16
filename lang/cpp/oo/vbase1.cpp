#include <iostream>
using namespace std;

class X {
public: int x;
	X(int a) {x=a;}
};

class A:virtual public X {
public: A(int a):X(a) {}
};

class B:virtual public X {
public: B(int a):X(a) {}
};

class C:public A,public B {
public: C(int a):A(20),B(30),X(40) {}
};

int main() {
	C c(30);
	cout<<c.x<<endl;
	return 0;
}
