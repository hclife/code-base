//Vector sort
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> v;
    while (n--) {
        int x;cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for (register int i=0;i<v.size();++i)
        cout<<v[i]<<' ';
    cout<<endl;
    return 0;
}
