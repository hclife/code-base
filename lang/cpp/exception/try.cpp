#include <iostream>
#include <string>
using namespace std;

int main() {
	string ex="This is an exception";
	try {
		cout<<"before throw"<<endl;
		throw ex;
		cout<<"after throw"<<endl;
	} catch (string &e) {
		cout<<e<<endl;
	}
	cout<<"main end"<<endl;
	return 0;
}
