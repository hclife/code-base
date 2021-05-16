//Prevent pass value in function call
#include <iostream>
using namespace std;

class CExample {
private: int a;
	 CExample(const CExample &C);
public:	 CExample(int b) {a=b;}
	 ~CExample() {}
	 void show() {cout<<a<<endl;}
};

void gfunc(CExample C) {cout<<"test\n";}

int main() {
    CExample test(1);test.show();
    //Passing value results compile error
    //gfunc(test);
    return 0;
}
