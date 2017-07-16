#include <iostream>
using namespace std;
class Complex{
  double real,image;
public:
  Complex(double a=0,double b=0)
    {real=a; image=b;}
  //x+y
  Complex operator+(Complex &x){
      Complex t;
      t.real=real+x.real;
      t.image=image+x.image;
      return t; 
  }
  //++x
  Complex operator++(){
     real++;
     image++;
     return *this; 
  }
  //x++
  Complex operator++(int){
     Complex t=*this;
     real++;
     image++;
     return t; 
  }
  void print(){
     cout<<real<<' '<<image<<endl;
  };
};

int main(){
     Complex a(1,2),b(3,4),c,x;
     c=a+b;
     c.print();
     x=++c;
     x.print();
     x=c++;
     x.print();
     c.print();
     return 0;
}

