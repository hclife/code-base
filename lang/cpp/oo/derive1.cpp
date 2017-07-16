#include <iostream>
using namespace std;

class A{
public:
	char * str;
	A(){str = "Base";}
	virtual void f(){cout<<str<<endl;}
};
class B : public A{
public:
	char * str ;
	B(){str = "Derived";}
	void f(){cout<<str<<endl;}
};
int main(){
	B a, *pb = &a, &rb = a;
	A *pa = &a, &ra = a;
	cout<<pa->str<<endl;		//1
	pa->f();			//2
	cout<<pb->str<<endl;		//3
	pb->f();			//4
	cout<<ra.str<<endl;		//5
	ra.f();				//6
	cout<<rb.str<<endl;		//7
	rb.f();				//8
	return 0;
}

