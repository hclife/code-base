//complex class with operators overload
#include <iostream>
using namespace std;

class Complex {
private:
    double real,virt;
public:
    Complex(double real=0.0,double virt=0.0):
    real(real),virt(virt) {};
public:
    friend Complex operator+(const Complex &A,const Complex &B);
    friend Complex operator-(const Complex &A,const Complex &B);
    friend Complex operator*(const Complex &A,const Complex &B);
    friend Complex operator/(const Complex &A,const Complex &B);
    friend istream &operator>>(istream &in,Complex &A);
    friend ostream &operator<<(ostream &out,Complex &A);
};

Complex operator+(const Complex &A,const Complex &B) {
    Complex C;
    C.real=A.real+B.real;
    C.virt=A.virt+B.virt;
    return C;
}

Complex operator-(const Complex &A,const Complex &B) {
    Complex C;
    C.real=A.real-B.real;
    C.virt=A.virt-B.virt;
    return C;
}

Complex operator*(const Complex &A,const Complex &B) {
    Complex C;
    C.real=A.real*B.real-A.virt*B.virt;
    C.virt=A.virt*B.virt+A.virt*B.real;
    return C;
}

Complex operator/(const Complex &A,const Complex &B) {
    Complex C;
    double square=A.real*A.real+A.virt*A.virt;
    C.real=(A.real*B.real+A.virt*B.virt)/square;
    C.virt=(A.virt*B.real-A.real*B.virt)/square;
    return C;
}

istream &operator>>(istream &in,Complex &A) {
    in>>A.real>>A.virt;
    return in;
}

ostream &operator<<(ostream &out,Complex &A) {
    out<<A.real<<'+'<<A.virt<<'i';
    return out;
}

int main() {
    Complex c1,c2,c3;
    cin>>c1>>c2;

    c3=c1+c2;
    cout<<"c1+c2="<<c3<<endl;

    c3=c1-c2;
    cout<<"c1-c2="<<c3<<endl;

    c3=c1*c2;
    cout<<"c1*c2="<<c3<<endl;

    c3=c1/c2;
    cout<<"c1/c2="<<c3<<endl;
    return 0;
}
