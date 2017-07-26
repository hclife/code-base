//using standard exceptions
#include <iostream>
#include <exception>
using namespace std;

class myexception: public exception {
	virtual const char *what() const throw() {
		return "My exception happened";
	}
} myexp;

int main()
{
	try {
		throw myexp;
	} catch (exception &e) {
		cout<<e.what()<<endl;
	}
	return 0;
}
