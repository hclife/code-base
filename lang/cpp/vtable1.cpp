#include <iostream>
#include <cstdio>
typedef void (*fun_pointer)(void);

using namespace std;
class Test {
public:
	Test() {
		cout<<"Test()."<<endl;
	}
	virtual void print() {
		cout<<"Test::Virtual void print1()."<<endl;
	}
	virtual void print2() {
		cout<<"Test::virtual void print2()."<<endl;
	}
};

class TestDrived:public Test {
public:
	static int var;
	TestDrived() {
		cout<<"TestDrived()."<<endl;
	}
	virtual void print() {
		cout<<"TestDrived::virtual void print1()."<<endl;
	}
	virtual void print2() {
		cout<<"TestDrived::virtual void print2()."<<endl;
	}
	void GetVtblAddress() {
		cout<<"vtbl address:"<<(int*)this<<endl;
	}
	void GetFirstVtblFunctionAddress() {
		cout<<"First vbtl funtion address:"<<(int*)*(int*)this+0 << endl;
	}
	void GetSecondVtblFunctionAddress() {
		cout<<"Second vbtl funtion address:"<<(int*)*(int*)this+1 << endl;
	}
	void CallFirstVtblFunction() {
		fun = (fun_pointer)* ( (int*) *(int*)this+0 );
		cout<<"CallFirstVbtlFunction:"<<endl;
		fun();
	}
	void CallSecondVtblFunction() {
		fun = (fun_pointer)* ( (int*) *(int*)this+1 );
		cout<<"CallSecondVbtlFunction:"<<endl;
		fun();
	}
private:
	fun_pointer fun;
};


int TestDrived::var = 3;

int main() {
	cout<<"sizeof(int):"<<sizeof(int)<<"sizeof(int*)"<<sizeof(int*)<<endl;
	fun_pointer fun = NULL;
	TestDrived a;
	a.GetVtblAddress();
	cout<<"The var's address is:"<<&TestDrived::var<<endl;
	a.GetFirstVtblFunctionAddress();
	a.GetSecondVtblFunctionAddress();
	a.CallFirstVtblFunction();
	a.CallSecondVtblFunction();
	return 0;
}
