#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAXN	1003
#define rint	register int
#define LEN	sizeof(struct list)

struct list {
	struct list *next;
	int v;
};

int N,M,Ans;char vis[MAXN];
struct list *map[MAXN];

void write_to_map(int x, int y)
{
	if (!map[x]) {
		map[x]=(struct list *)malloc(LEN);
		map[x]->v=y;map[x]->next=NULL;
		return;
	}
	struct list *p;
	for (p=map[x];p->next;p=p->next);
	p->next=(struct list *)malloc(LEN);
	p=p->next;p->v=y;p->next=NULL;
}

void visit(int x)
{
	struct list *p;vis[x]=1;
	for (p=map[x];p;p=p->next)
	if (!vis[p->v]) visit(p->v);
}

int main()
{
	int x,y,T;cin>>T;
	while (T--) {
		scanf("%d%d",&N,&M);
		for (rint i=1;i<=N;++i) map[i]=NULL;
		for (rint i=1;i<=M;++i) {
			scanf("%d%d",&x,&y);
			write_to_map(x,y);
			write_to_map(y,x);
		}
		Ans=0;memset(vis,0,sizeof(vis));
		for (rint i=1;i<=N;++i) {
			if (!map[i]) ++Ans;
			else if (!vis[i]) {++Ans;visit(i);}
		}
		cout<<Ans<<endl;
	}
	return 0;
}
