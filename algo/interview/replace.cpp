#include <string>
#include <iostream>
using namespace std;

#define rint	register int

bool is_match(string &s,string &t,int x) {
    if (x>s.size()-t.size()) return false;
    for (rint i=0;t[i];++i,++x)
    if (s[x]!=t[i]) return false;
    return true;
}

//replace all t in s with string v
string replace(string &s,string &t,string &v) {
    string now;
    for (rint i=0;s[i];++i) {
	if (!is_match(s,t,i)) now+=s[i];
	else {now+=v;i+=(t.size()-1);}
    }
    return now;
}

int main() {
    int T;cin>>T;
    string s,t,v;
    while (T--) {
	cin>>s>>t>>v;
	s=replace(s,t,v);
	cout<<s<<endl;
    }
    return 0;
}
