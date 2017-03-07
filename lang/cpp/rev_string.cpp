#include <iostream>
using namespace std;

#define SWAP(x,y,T)	{T t=x;x=y;y=t;}
#define rint		register int

void reverse(string &s) {
    size_t sz=s.size();
    for (rint i=0,j=sz-1;i<j;++i,--j)
	SWAP(s[i],s[j],char);
}

int main() {
    string s;cin>>s;
    reverse(s);
    cout<<s<<endl;
    return 0;
}
