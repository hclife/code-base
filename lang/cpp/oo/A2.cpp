#include <iostream>
using namespace std;

class A {
public:
	int a,b;
	A() {cout<<"A Constructor1"<<endl;}
	A(int a,int b) {
		cout<<"A Constructor2"<<endl;
		this->a=a;
		this->b=b;
	}
};

class B:public A {
public:
	int c,d;
	B() {cout<<"B Constructor1"<<endl;}
	B(int c,int d):A(10,20) {
		cout<<"B Constructor2"<<endl;
		this->c=c;
		this->d=d;
	}
};

int main() {
	B b(1,2);
	return 0;
}
