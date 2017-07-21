//Map STL
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int T;cin>>T;
    std::map<string,int> m;
    int cmd,score;string name;
    while (T--) {
       cin>>cmd>>name;
       map<string,int>::iterator it=m.find(name);
       switch (cmd) {
       case 1:
           cin>>score;
           if (it!=m.end()) it->second+=score;
           else m.insert(make_pair(name,score));
           break;
       case 2:
           if (it!=m.end()) m.erase(name);
           break;
       case 3:
           if (it==m.end()) cout<<'0'<<endl;
           else cout<<it->second<<endl;
           break;
       }
    }
    return 0;
}
