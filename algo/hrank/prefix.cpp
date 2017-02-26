#include <bits/stdc++.h>
using namespace std;

#define MAXS	16
#define MAXZ	26
#define MAXN	400005
#define MAXB	5000006
#define isd(x)	((x)>='0' && (x)<='9')
#define isA(x)	((x)>='A' && (x)<='Z')
#define MAXV(x,y)	((x)>=(y)?(x):(y))
#define TLEN	sizeof(struct trie)
#define rint	register int
#define log	printf

typedef struct trie {
	struct trie *next[MAXZ];
	int id,value,max[2];
} trie;

int N;
char buf[MAXB];
char s[MAXN][MAXS];

void dump()
{
	log("N=%d\n",N);
	for (rint i=1;i<=N;++i) {
		log("%d:",i);
		puts(s[i]);
	}
}

int inputn()
{
	rint c,k=0;fgets(buf,16,stdin);
	for (rint i=0;c=buf[i];++i) {
		if (isd(c)) k=k*10+c-'0';
		else break;
	}
	return k;
}

int inputs()
{
	rint c,x=1,y=0;
	fgets(buf,sizeof(buf),stdin);
	for (rint i=0;c=buf[i];++i) {
		if (isA(c)) s[x][y++]=c;
		else s[x++][y]=0,y=0;
	}
	return --x;
}

int cost(const char *s)
{
	int v=0;
	for (rint i=0;s[i];++i) v+=s[i];
	return v;
}

struct trie *trie_create()
{
	struct trie *t=(trie *)malloc(TLEN);
	assert(t);
	for (rint i=0;i<MAXZ;++i) t->next[i]=NULL;
	t->id=t->value=0;t->max[0]=t->max[1]=-1;
	return t;
}

void trie_insert(trie *root,const char *s,int id)
{
	assert(root && *s);
	struct trie *t;
	for (rint c,i=0;c=s[i];++i,root=t)
	if (!(t=root->next[c-'A'])) {
		t=root->next[c-'A']=trie_create();
	}
	if (root->id) root->value+=cost(s);
	else root->id=id,root->value=cost(s);
}

void trie_dfs(trie *root,int pid)
{
	assert(root);
	if (pid && root->id) log("%d->%d\n",pid,root->id);
	if (root->id) log("id=%d,value=%d\n",root->id,root->value);
	for (rint i=0;i<MAXZ;++i)
	if (root->next[i]) trie_dfs(root->next[i],root->id);
}


int trie_visit(trie *root,int mod)
{
	assert(root && mod<2);
	if (root->max[mod]>=0) return root->max[mod];
	if (!mod) {
		int ret=0;
		for (rint i=0;i<MAXZ;++i)
		if (root->next[i]) {
			int ret0=trie_visit(root->next[i],0);
			int ret1=(root->next[i]->id)?trie_visit(root->next[i],1):0;
			ret+=MAXV(ret0,ret1);
		}
		return root->max[0]=ret;
	}
	for (rint i=0;i<MAXZ;++i)
	if (root->next[i]) trie_visit(root->next[i],root->id);
}

void trie_free(trie **root)
{
	if (!*root) return;
	for (rint i=0;i<MAXZ;++i)
	if ((*root)->next[i]) trie_free(&(*root)->next[i]);
	free(*root);*root=NULL;
}

int solve()
{
	struct trie *root=trie_create();
	assert(root);
	for (rint i=1;i<=N;++i) trie_insert(root,s[i],i);
	//trie_dfs(root,0);
	int ret0=trie_visit(root,0);
	trie_free(&root);
	return 0;
}

int main()
{
	N=inputn();
	int ret=inputs();
	assert(N==ret);
	dump();
	int Ans=solve();
	cout<<Ans<<endl;
	return 0;
}
