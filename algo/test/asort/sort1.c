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
char _words[MAXN][MAXN];
char ans[MAXN][MAXN];

void dump() {
    int i;
    for (i=0;i<wnum;++i)
	printf("%s\n",words[i]);
    printf("\n");
}

int _cmp(char *a,char *b) {
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

int cmp(char *a,char *b) {
    int i;
    for (i=0;a[i] && b[i];++i) {
	char x=a[i],y=b[i];
	if (is_upper(x)) x=to_lower(x);
	if (is_upper(y)) y=to_lower(y);
	if (x!=y) return x-y;
    }
    if (!a[i] && b[i]) return -1;
    if (a[i] && !b[i]) return 1;
    return 0;
}

void merge_union(char s[MAXN][MAXN],int lefto,int midle,int right,
		 char t[MAXN][MAXN]) {
    int i=lefto,j=midle+1,k=lefto;
    while (i<=midle && j<=right) {
	if (cmp(s[i],s[j])<=0) strcpy(t[k++],s[i++]);
	else strcpy(t[k++],s[j++]);
    }
    while (i<=midle) strcpy(t[k++],s[i++]);
    while (j<=right) strcpy(t[k++],s[j++]);
    for (i=lefto;i<=right;++i) strcpy(s[i],t[i]);
}

void merge_sort(char s[MAXN][MAXN],int lefto,int right,
		char t[MAXN][MAXN]) {
    int midle=(lefto+right)>>1;
    if (lefto>=right) return;
    merge_sort(s,lefto,midle,t);
    merge_sort(s,midle+1,right,t);
    merge_union(s,lefto,midle,right,t);
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
	strcpy(words[wnum++],in);
    }

    //dump();
    merge_sort(words,0,wnum-1,ans);
    //dump();
    remove_dup();
    int i=0;
    for (i=0;i<apos;++i) {
	printf("%s ",ans[i]);
    }
    printf("%s\n",ans[apos]);

    return 0;
}
