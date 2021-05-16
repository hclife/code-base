#include <iostream>
using namespace std; 

class A {  
    virtual void g()  {   cout << "A::g" << endl;  } 

private:  virtual void f()  {   cout << "A::f" << endl;  } 

}; 
class B : public A {  
    void g()  {   cout << "B::g" << endl;  }  

virtual void h()  {   cout << "B::h" << endl;  } 

}; 
typedef void( *Fun )( void ); 

int  main() {
	B b; Fun pFun;  
	cout<<"vtable addr = "<<(int*)&b<<endl;
	for(int i = 0; i < 3; i++)  {   
		pFun = ( Fun )*( ( int* ) * ( int* )( &b ) + i );   
		pFun();  
	}
	return 0;
} 
