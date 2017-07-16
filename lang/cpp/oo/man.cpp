#include <iostream>
using namespace std;

class human {
public:
	virtual ~human() {cout<<"human over\n";}
	virtual void disp() {cout<<"human disp\n";}
};

class man: public human {
public:
	virtual ~man() {cout<<"man over\n";}
	virtual void disp() {cout<<"man disp\n";}
};

int main() {
	human *p=new man;
	p->disp();
	delete p;
	return 0;
}
