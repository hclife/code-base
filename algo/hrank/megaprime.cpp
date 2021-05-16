#include <bits/stdc++.h>
using namespace std;

//#define MAXN	32000000ULL
#define MAXN	32000000ULL
#define MAXL	18
#define rint	register int
typedef long long int s64;
typedef unsigned long long int u64;

static u64 firstd,lastd,Ans=0;
static string firsts,lasts;
static stringstream ss;
static int firstl,lastl;
static const char *prime="2357";
static char data[MAXL];

int is_primex(u64 x) {
	if (x==2 || x==3 || x==5 || x==7) return 1;
	if (x<=10 || (x&1)==0) return 0;
	if (x%5==0 || x%11==0) return 0;
	if (x%6!=1 && x%6!=5) return 0;
	for (u64 i=5;i*i<=x;i+=6)
	if (x%i==0 || x%(i+2)==0) return 0;
	return 1;
}

void solve() {
	u64 num;ss.clear();ss<<data;ss>>num;
	if (num<firstd || num>lastd) return;
	if (is_primex(num)) ++Ans;
}

void visit(int x,int n) {
	if (x>=n) {
		solve();
		return;
	}
	for (rint i=0;i<4;++i) {
		data[x]=prime[i];
		visit(x+1,n);
	}
}

int main() {
	cin>>firstd>>lastd;
	ss.clear();ss<<firstd;ss>>firsts;
	ss.clear();ss<<lastd;ss>>lasts;
	firstl=firsts.size();
	lastl=lasts.size();
	//cout<<firsts<<' '<<firstl<<endl;
	//cout<<lasts<<' '<<lastl<<endl;
	//cout<<prime<<endl;
	for (rint i=firstl;i<=lastl;++i) {
		data[i]=0;visit(0,i);
	}
	cout<<Ans<<endl;
	return 0;
}
