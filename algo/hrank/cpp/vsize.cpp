//Variable sized arrays
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,q;cin>>n>>q;
    vector<vector<int>> A(n);
    for (register int i=0;i<n;++i) {
        int k;cin>>k;
        for (register int j=0;j<k;++j) {
            int x;cin>>x;
            A[i].push_back(x);
        }
    }
    while (q--) {
        int i,j;cin>>i>>j;
        cout<<A[i][j]<<endl;
    }
    return 0;
}

