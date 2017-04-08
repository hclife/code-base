//deep constructor
#include <cstring>
#include <iostream>
using namespace std;

class CA {
private:
	int a;
	char *s;
public:
	CA(int b,const char *cs) {
	    a=b;
	    s=new char[b];
	    strcpy(s,cs);
	}
	CA(const CA &c) {
	    a=c.a;
	    s=new char[a];
	    if (s) strcpy(s,c.s);
	}
	void show() {cout<<s<<endl;}
	~CA() {delete s;}
};

int main() {
    CA a(10,"Hello");
    CA b=a;
    b.show();
    return 0;
}
