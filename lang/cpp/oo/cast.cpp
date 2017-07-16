#include <iostream>
#include <string.h>
using namespace std;
class String{
  char *str;
public:
  String(const char *p=NULL){
    if(p){
      str = new char[strlen(p)+1];
      strcpy(str, p); 
    }else 
      str = NULL;
  }

  ~String (){
    if(str != NULL) delete [] str; 
  }

  operator char *(){    
    return str; 
  }
};

int main() {
	String s1("abcdef");
	char x[40],*p;
	strcpy(x,(char*)s1);
	cout<<"x="<<x<<endl;
	p=s1;
	cout<<p<<endl;
	return 0;
}
