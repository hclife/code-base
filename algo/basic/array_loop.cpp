#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN	    1024
#define MAXV(x,y)   ((x)>(y)?(x):(y))
#define rint	    register int

int A[MAXN];

int get_max(int s,int e) {
    if (s>e) return -1;
    if (s==e) return A[s];
    int max=A[s];
    for (rint i=s+1;i<=e;++i)
	max=MAXV(max,A[i]);
    return max;
}

int get_sum(int s,int e) {
    int sum=0;
    for (rint i=s;i<=e;++i)
	sum+=A[i];
    return sum;
}

int main() {
    int T;cin>>T;
    for (rint t=1;t<=T;++t) {
	int N;cin>>N;
	for (rint i=1;i<=N;++i) cin>>A[i];
	int max=get_max(1,N);
	int sum=get_sum(1,N);
	double avg=double(sum)/N;
	printf("Case #%d\n",t);
	printf("max=%d,sum=%d,avg=%.2lf\n",max,sum,avg);
    }

    return 0;
}
