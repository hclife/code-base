#include <vector>
#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

#define rint	    register int
#define is_valid(x) ((x)>=1 && (x)<=n)

struct link {
    int prev,next;
};

int round(int x,int n) {
    if (x<1) return n;
    if (x>n) return 1;
    return x;
}

int kill(vector<link> &data,int &s,int m,int n) {
    assert(is_valid(data[s].prev));
    assert(is_valid(data[s].next));
    int man=s;
    for (rint i=2;i<=m;++i) {
	man=data[man].next;
    }
    int prev=data[man].prev;
    int next=data[man].next;
    data[next].prev=prev;
    s=data[prev].next=next;
    data[man].prev=data[man].next=-1;
    return man;
}

void josephus(int n,int s,int m) {
    if (n<=0 || m<=0) {
	printf("input n/m failed:n=%d,m=%d\n",n,m);
	return;
    }
    if (!is_valid(s)) {
	printf("input start failed:s=%d\n",s);
	return;
    }
    vector<link> data(n+10);
    for (rint i=1;i<=n;++i) {
	data[i].prev=round(i-1,n);
	data[i].next=round(i+1,n);
    }
    for (rint i=1;i<=n;++i) {
	int x=kill(data,s,m,n);
	assert(is_valid(x));
	cout<<x<<' ';
    }
    cout<<endl;
}

int main() {
    int T;cin>>T;
    int n,s,m;
    while (T--) {
	cin>>n>>s>>m;
	josephus(n,s,m);
    }
    return 0;
}
