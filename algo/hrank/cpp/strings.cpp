//Strings
#include <iostream>
#include <string>
using namespace std;

#define swap(x,y,T)    {T t=x;x=y;y=t;}

int main() {
    string a,b;
    cin>>a>>b;
    cout<<a.size()<<' '<<b.size()<<endl;
    cout<<a+b<<endl;
    swap(a[0],b[0],char);
    cout<<a<< ' '<<b<<endl;

    return 0;
}

