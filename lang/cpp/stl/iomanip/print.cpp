#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    double x=12345.127,y=1.23456789;
    cout<<x<<endl<<y<<endl;
    cout<<setprecision(3)<<y<<endl;
    cout<<fixed<<setprecision(3)<<y<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<y<<endl;
    cout<<resetiosflags(ios::fixed)<<setiosflags(ios::scientific)<<x<<endl;

    return 0;
}
