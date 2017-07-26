//bad_alloc standard exception
#include <iostream>
#include <exception>
using namespace std;

int main() {
	try {
		long long size;cin>>size;
		int *myarray=new int[size];
		throw myarray;
	} catch (std::bad_alloc) {
		cout<<"alloc failed"<<endl;
	} catch (exception &e) {
		cout<<"standard exception: "<<e.what()<<endl;
	} catch (...) {
		cout<<"non-standard exception"<<endl;
	}
	return 0;
}
