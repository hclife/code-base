#include <iostream>
using namespace std;

class T {
public:
    T() {cout<<"constructor\n";}
    ~T() {cout<<"destructor\n";}
};

int main() {
    const int num=3;
    T *p1=new T[num];
    cout<<hex<<p1<<endl;
    delete[] p1;

#if 0
    T *p2=new T[num];
    cout<<hex<<p2<<endl;
    delete[] p2;
#endif

    return 0;
}
