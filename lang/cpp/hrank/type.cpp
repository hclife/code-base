//Basic data types
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    int i;
    long j;
    long long k;
    char c;
    float f;
    double d;
    cin>>i>>j>>k;
    cin>>c>>f>>d;
    cout<<i<<endl;
    cout<<j<<endl;
    cout<<k<<endl;
    cout<<c<<endl;
    cout<<fixed<<setprecision(3)<<f<<endl;
    cout<<fixed<<setprecision(9)<<d<<endl;
    return 0;
}
