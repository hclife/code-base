//Set STL
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int T;cin>>T;
    set<int> s;
    while (T--) {
        int cmd,x;cin>>cmd>>x;
        switch (cmd) {
        case 1: s.insert(x);break;
        case 2: s.erase(x);break;
        case 3:
            set<int>::iterator it=s.find(x);
            if (it!=s.end()) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            break;
        }
    }
    return 0;
}
