//Arrays introduction
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;cin>>N;
    vector<int> A(N);
    for (register int i=0;i<N;++i) cin>>A[i];
    for (register int i=N-1;i>=0;--i) cout<<A[i]<<' ';
    cout<<endl;
    return 0;
}

