#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXN		256
#define is_digit(x)	((x)>='0' && (x)<='9')
#define is_upper(x)	((x)>='A' && (x)<='Z')
#define is_lower(x)	((x)>='a' && (x)<='z')
#define is_alpha(x)	(is_upper(x) || is_lower(x))
#define to_lower(x)	((x)-'A'+'a')
#define to_upper(x)	((x)-'a'+'A')

int wnum,apos;
char words[MAXN][MAXN];
char ans[MAXN][MAXN];

void dump() {
    int i;
    for (i=0;i<wnum;++i)
	printf("%s\n",words[i]);
    printf("\n");
}

void str_to_lower(char *s) {
    int i;
    for (i=0;s[i];++i) {
	if (is_upper(s[i])) s[i]=to_lower(s[i]);
    }
}

int cmp(char *a,char *b) {
    int alen=strlen(a),blen=strlen(b);
    int i;
    char x,y;
    for (i=0;i<alen && i<blen;++i) {
	x=a[i];y=b[i];
	if (is_upper(x)) x=to_lower(x);
	if (is_upper(y)) y=to_lower(y);
	if (x!=y) return x-y;
    }
    if (alen==blen) return 0;
    if (i==alen) return -1;
    if (i==blen) return 1;
    return 0;
}

void quick_sort(int l,int r) {
    if (l>=r) return;
    int i=l,j=r;
    char x[MAXN];
    strcpy(x,words[l]);
    while (i<j) {
	while (i<j && cmp(words[j],x)>=0) --j;
	if (i<j) {strcpy(words[i],words[j]);++i;}
	while (i<j && cmp(words[i],x)<=0) ++i;
	if (i<j) {strcpy(words[j],words[i]);--j;}
    }
    strcpy(words[i],x);
    quick_sort(l,i-1);
    quick_sort(i+1,r);
}

void remove_dup() {
    int i;
    apos=0;
    strcpy(ans[0],words[0]);
    for (i=1;i<wnum;++i) {
	if (cmp(words[i],ans[apos])) {
	    strcpy(ans[++apos],words[i]);
	}
    }
}

int main() {
    char in[MAXN];
    wnum=0;
    memset(words,0,sizeof(words));
    memset(ans,0,sizeof(ans));
    while (scanf("%s",in)!=EOF) {
	//str_to_lower(in);
	strcpy(words[wnum++],in);
    }

    //dump();
    quick_sort(0,wnum-1);
    //dump();
    remove_dup();
    int i=0;
    for (i=0;i<apos;++i) {
	printf("%s ",ans[i]);
    }
    printf("%s\n",ans[apos]);

    return 0;
}
