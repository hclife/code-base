#include <iostream>
using namespace std;
class Complex{
	double real, image;
	public:
	Complex(double a=0, double b=0) {real=a; image=b;}
	void print() {cout<<real<<' '<<image<<endl;}
	friend Complex operator +(Complex &,Complex &); //prototype
};

Complex operator +(Complex &a,Complex &b){ //definition
	Complex t;
	t.real = a.real + b.real;
	t.image = a.image + b.image;
	return t;
}

int main() {
	Complex a(1,2),b(3,4);
	Complex c=a+b; //c=operator+(a,b);
	c.print();
	return 0;
}

