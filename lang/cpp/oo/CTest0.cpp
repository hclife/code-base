#include <iostream>
using namespace std;

class CTest {
public:
    CTest() {}
    ~CTest() {}
    CTest(const CTest &c) {
	cout<<"copy constructor"<<endl;
    }
    CTest &operator=(const CTest &c) {
	cout<<"operator="<<endl;
    }
    void Test(CTest c) {
	cout<<"Test"<<endl;
    }
    CTest Test2() {
	cout<<"Test2"<<endl;
	CTest c;
	return c;
    }
    void Test3(CTest &c) {
	cout<<"Test3"<<endl;
    }
    CTest &Test4() {
	cout<<"Test4"<<endl;
	CTest *p=new CTest;
	return *p;
    }
};

int main() {
    CTest obj;
    CTest obj1(obj);//copy constructor
    obj1=obj;	    //operator=
    obj.Test(obj1); //copy constructor

    CTest obj2=obj.Test2();
    obj2.Test3(obj);

    CTest obj3;
    obj2.Test4();

    return 0;
}
