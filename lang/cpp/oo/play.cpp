#include <iostream>
using namespace std;

class B {
public:
	B() {cout<<"default constructor"<<endl;}
	~B() {cout<<"destructed"<<endl;}
	B(int i):data(i) {
		cout<<"constructed by parameter "<<data<<endl;
	}
private:
	int data;
};

B play(B b) {
	return b;
}

int main() {
	B temp=play(5);
	return 0;
}
