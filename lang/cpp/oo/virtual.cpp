#include <iostream>
using namespace std;

class AbsBase {
public: virtual void who() {cout<<"AbsBase\n";}
};

class Base:public AbsBase {
public: void who() {cout<<"Base\n";}
};

class Derive1:public Base {
public: void who() {cout<<"Derive1\n";}
};

class Derive2:public Base {
public: void who() {cout<<"Derive2\n";}
};

void f(AbsBase &A) {A.who();}
void f(Base *B) {B->who();}

int main() {
	Base obj;
	Derive1 obj1;
	Derive2 obj2;
	f(obj);f(obj1);f(obj2);
	f(&obj);f(&obj1);f(&obj2);

	Derive1 *pd1=&obj1;
	pd1->who();f(pd1);

	Base *pb=pd1;
	pb->who();

	pd1=(Derive1*)pb;
	pd1->who();

	Derive2 *pd2=(Derive2*)pd1;
	pd2->who();
	return 0;
}
