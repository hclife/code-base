#include <iostream>
using namespace std;

void print() {cout<<"empty\n";}

template <class T>
void print(T t) {cout<<t<<endl;}

template <typename T,typename... Args>
void print(T head,Args... args) {
    static const int size=sizeof...(Args);
    cout<<"size="<<size<<endl;
    cout<<head<<endl;
    print(args...);
}

int main() {
    print(1,2,3,4);
    return 0;
}
