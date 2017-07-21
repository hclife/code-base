//Vector erase
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> v;
    v.push_back(0);
    while (n--) {
        int x;cin>>x;
        v.push_back(x);
    }

    int x;cin>>x;
    v.erase(v.begin()+x);
    int y;cin>>x>>y;
    v.erase(v.begin()+x,v.begin()+y);

    cout<<v.size()-1<<endl;
    for (register int i=1;i<v.size();++i)
        cout<<v[i]<<' ';
    cout<<endl;

    return 0;
}
