//Bit Array
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned int u32;
typedef unsigned long long u64;
const u64 max_div=(1ULL<<31)-1ULL;
#define f(x)    ((P*(x)+Q)&max_div)

int main() {
    u64 N,S,P,Q;cin>>N>>S>>P>>Q;
    if (N==1ULL) {cout<<1;return 0;}
    if (N==2ULL) {
        if (S==f(S)) cout<<1;else cout<<2;
        return 0;
    }
    if (S==f(S)) {cout<<1;return 0;}
    if (S==f(f(S))) {cout<<2;return 0;}
    if (f(S)==f(f(S))) {cout<<2;return 0;}
    
    //1.start tortoise and hare both from S until they meet
    u64 step_tort=1,step_hare=1;
    u64 val_tort=S,val_hare=S;
    bool meet=false;
    while (1) {
        step_tort+=1;step_hare+=2;
        if (step_hare>N || step_tort>N) break;
        val_tort=f(val_tort);val_hare=f(f(val_hare));
        if (val_tort==val_hare) {meet=true;break;}
    }
    //cout<<boolalpha<<meet;
    if (meet==false) {cout<<N;return 0;}
    
    //2.Move tortoise until they meet again
    u64 Ans=0;
    while (1) {
        val_tort=f(val_tort);++Ans;
        if (val_tort==val_hare) break;
    }
    
    //3.Start tortoise from S to find loop beginning point 
    val_tort=S;
    while (val_tort!=val_hare) {
        val_tort=f(val_tort);
        val_hare=f(val_hare);
        ++Ans;
    }
    
    cout<<Ans;
    return 0;
}
