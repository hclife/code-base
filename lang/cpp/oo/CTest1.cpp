#include <cstring>
#include <iostream>
using namespace std;

const int MAXSIZE=260;

class CTest {
private:
    char *pValue;
public:
    CTest(const char *pInitValue) {
	cout<<"constructor"<<endl;
	pValue=new char[MAXSIZE];
	memset(pValue,0,sizeof(char)*MAXSIZE);
	memcpy(pValue,pInitValue,MAXSIZE);
    }
    ~CTest() {
	if (pValue) {
	    delete[] pValue;
	    pValue=NULL;
	}
    }
    CTest(const CTest &c) {
	cout<<"copy constructor1"<<endl;
	pValue=new char[MAXSIZE];
	memset(pValue,0,sizeof(char)*MAXSIZE);
	memcpy(pValue,c.pValue,MAXSIZE);
    }
    CTest(CTest &c) {
	cout<<"copy constructor2"<<endl;
	pValue=new char[MAXSIZE];
	memset(pValue,0,sizeof(char)*MAXSIZE);
	memcpy(pValue,c.pValue,MAXSIZE);
    }
    CTest(volatile CTest &c) {
	cout<<"copy constructor3"<<endl;
    }
    CTest(const volatile CTest &c) {
	cout<<"copy constructor4"<<endl;
    }
    CTest(const CTest &c,int x=1,int y=2) {
	cout<<"copy constructor5"<<endl;
    }
    CTest &operator=(const CTest &c) {
	cout<<"operator="<<endl;
	//This is very important
	if (this==&c) return *this;
	if (pValue) delete[] pValue;
	pValue=new char[MAXSIZE];
	memset(pValue,0,sizeof(char)*MAXSIZE);
	memcpy(pValue,c.pValue,MAXSIZE);
	return *this;
    }
    void Print() {
	wcout<<pValue<<endl;
    }
};

int main() {
    CTest obj("obj");
    obj.Print();

    CTest obj2("obj2");
    obj2.Print();
    obj2=obj;
    obj2.Print();

    obj2=obj2;
    obj2.Print();

    CTest obj3(obj2);
    obj3.Print();

    return 0;
}
