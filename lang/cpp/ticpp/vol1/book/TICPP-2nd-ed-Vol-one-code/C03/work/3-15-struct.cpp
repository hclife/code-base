#include <string>
#include <iostream>
using namespace std;

typedef struct Point {
    string s,t;
    int a;
} Point;

int main() {
    Point p;
    p.s="string1";
    p.t="string2";
    p.a=10;
    cout<<p.s<<" "<<p.t<<" "<<p.a<<endl;

    Point *pt=&p;
    pt->s="cstring1";
    pt->t="cstring2";
    pt->a=20;
    cout<<pt->s<<" "<<pt->t<<" "<<pt->a<<endl;

    return 0;
}
