//Functions
#include <iostream>
#include <cstdio>
using namespace std;

#define MAXV(x,y)    ((x)>(y)?(x):(y))

int max_of_four(int a,int b,int c,int d) {
    int max=a;
    max=MAXV(max,b);
    max=MAXV(max,c);
    max=MAXV(max,d);
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}


