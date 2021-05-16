#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char q[10];
    char *p=new char[10];
    memcpy(p,"newstring",10);
    cout<<"sizeof(*p)="<<sizeof(*p)<<endl;
    cout<<"sizeof(*q)="<<sizeof(*q)<<endl;
    cout<<"sizeof(p)="<<sizeof(p)<<endl;
    cout<<"strlen(p)="<<strlen(p)<<endl;
    cout<<"sizeof(q)="<<sizeof(q)<<endl;
    if (p) delete[] p;
    return 0;
}
