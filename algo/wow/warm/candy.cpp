#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define rint		register int
#define to_upper(c)	('A'+(c)-'a')
#define to_lower(c)	('a'+(c)-'A')
#define is_digit(c)	((c)>='0' && (c)<='9')
#define is_lower(c)	((c)>='a' && (c)<='z')
#define is_upper(c)	((c)>='A' && (c)<='Z')
#define is_alpha(c)	(is_lower(c) || is_upper(c))
#define maxv(x,y)	((x)>(y)?(x):(y))
#define minv(x,y)	((x)<(y)?(x):(y))

//N:The number of coins
//M:The number of groups
//Ans:The maximum number of candies
int N,M,Ans;

//n:The number of current total coints
//m:The number of current total groups
//b:The number of coins divided by last group
//s:The number of candies to the entry moment
void visit(int n,int m,int b,int s) {
    if (n<=0 || m<=0) return;
    if (m==1) {
	if (n>=b) Ans=maxv(Ans,s*n);
	return;
    }
    for (int i=b;i<=n/m;++i)
	visit(n-i,m-1,i,s*i);
}

int solve() {
    Ans=0;
    visit(N,M,1,1);
    return Ans;
}

int main() {
    int T;scanf("%d",&T);
    for (int t=1;t<=T;++t) {
	scanf("%d %d",&N,&M);
	printf("#%d %d\n",t,solve());
    }
    return 0;
}
