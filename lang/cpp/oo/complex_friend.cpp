#include <iostream>
using namespace std;
class Complex{
private:double real, image;
public: Complex(double a=0, double b=0)
	{ real=a; image=b;}
	void print() { cout<<real<<' '<<image<<endl;}
	friend Complex operator+(Complex &,Complex &); //prototype
	friend Complex operator++(Complex &); //++x
	friend Complex operator++(Complex &,int); //x++
};

Complex operator+(Complex &a,Complex &b){ //definition
	Complex t;
	t.real = a.real + b.real;
	t.image = a.image + b.image;
	return t;
}

Complex operator++(Complex &x) {
	x.real++;
	x.image++;
	return x;
}

Complex operator++(Complex &x,int) {
	Complex t=x;
	x.real++;
	x.image++;
	return t;
}

int main() {
	Complex a(1,2),b(3,4);
	Complex c=a+b; //c=operator+(a,b);
	c.print();
	Complex x=++c;
	x.print();
	x=c++;
	x.print();
	c.print();
	return 0;
}

