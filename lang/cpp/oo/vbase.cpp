#include <iostream>
using namespace std;

class A {
private: char c;
public: A(char i) {cout<<"A constructor i="<<i<<endl;c=i;}
	~A() {cout<<"A destructor\n";}
};

class B:virtual public A {
private: char b;
public: B(char i,char j):A(i)
	{cout<<"B constructor i="<<i<<" j="<<j<<endl;}
	~B() {cout<<"B destructor\n";}
};

class C:virtual public A {
public: C(char i):A(i)
	{cout<<"C constructor i="<<i<<endl;}
	~C() {cout<<"C destructor\n";}
};

class D:public B,public C {
private: A aa;
public:
	D(char i,char j,char k):C(j),B(i,j),A(i),aa(k)
	{cout<<"D constructor\n";}
	~D() {cout<<"D destructor\n";}
};

int main() {
	D obj('a','b','c');
	return 0;
}
