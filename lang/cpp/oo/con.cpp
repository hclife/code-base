#include <iostream>
#include <cstdio>
using namespace std;

class B
{
	B(){}
	//B(int i){}
};

class A
{
public:
	A(){}
	B b;
};

int main(void) 
{ 
	// error C2512: 'B' : no appropriate default constructor available
	A a();  // error now

	getchar() ; 
	return 0 ; 
}


