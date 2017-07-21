//Lower bound STL
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;cin>>N;vector<int> vec(N);
    for (register int i=0;i<N;++i) cin>>vec[i];
    int Q;cin>>Q;
    while (Q--) {
        int val;vector<int>::iterator low;
        cin>>val;low=std::lower_bound(vec.begin(),vec.end(),val);
        if (*low==val) cout<<"Yes "<<(low-vec.begin()+1)<<endl;
        else cout<<"No "<<(low-vec.begin()+1)<<endl;
    }
    return 0;
}
