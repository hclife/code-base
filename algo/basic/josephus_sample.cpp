#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

void josephus(int a[],int n,int s,int m) {
    if (n<=0 || m<=0) {
	printf("input n/m failed:n=%d,m=%d\n",n,m);
	return;
    }
    if (s<1 || s>n) {
	printf("input start failed:s=%d\n",s);
	return;
    }
    int i,j,k,t;
    for (i=0;i<n;++i) a[i]=i+1;
    i=s-1;
    for (k=n;k>1;--k) {
	if (i==k) i=0;
	i=(i+m-1)%k;
	if (i!=k-1) {
	    t=a[i];
	    for (j=i;j<k-1;++j)
		a[j]=a[j+1];
	    a[k-1]=t;
	}
    }
    for (k=0;k<n/2;++k) {
	t=a[k];
	a[k]=a[n-k-1];
	a[n-k-1]=t;
    }
    for (i=0;i<n;++i) cout<<a[i]<<' ';
    cout<<endl;
}

int main() {
    int T;cin>>T;
    int n,s,m;
    while (T--) {
	cin>>n>>s>>m;
	int a[n+10];
	josephus(a,n,s,m);
    }
    return 0;
}
