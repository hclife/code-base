#include <stdio.h>
#include <string.h>
#include <assert.h>

#define is_digit(x)	((x)>='0' && (x)<='9')
#define is_upper(x)	((x)>='A' && (x)<='Z')
#define is_lower(x)	((x)>='a' && (x)<='z')
#define is_alpha(x)	(is_upper(x) || is_lower(x))

int poker[16],color[4],same[6];

void dump(int s[],int n) {
    int i;
    for (i=0;i<n;++i)
	printf("%d ",s[i]);
    printf("\n");
}

int get_poker_index(char *s) {
    if (strlen(s)==2) {
	assert(s[0]=='1' && s[1]=='0');
	return 10;
    }
    assert(strlen(s)==1);
    if (is_digit(s[0])) return s[0]-'0';

    assert(is_upper(s[0]));
    if (s[0]=='J') return 11;
    if (s[0]=='Q') return 12;
    if (s[0]=='K') return 13;
    if (s[0]=='A') return 14;
    return -1;
}

int get_color_index(char *s) {
    assert(strlen(s)==1);
    if (s[0]=='H') return 0;
    if (s[0]=='S') return 1;
    if (s[0]=='C') return 2;
    if (s[0]=='D') return 3;
    return -1;
}

void input(char *sz,char *col) {
    int pidx=get_poker_index(sz);
    int cidx=get_color_index(col);
    assert(pidx>=0 && cidx>=0);
    ++poker[pidx];
    ++color[cidx];
}

int check_sequential() {
	int p,k;
	for (p=2;p<=10;++p) {
		for (k=0;k<5;++k)
		if (!poker[p+k]) break;
		if (k==5) return 1;
	}
	return 0;
}

int check_same_color() {
	int i;
	for (i=0;i<4;++i)
	if (color[i]==5) return 1;
	return 0;
}

void check_same_pokers() {
	int p,s;
	for (p=2;p<15;++p) {
		for (s=2;s<=4;++s)
		if (poker[p]==s) same[s]=1;
	}
}

int check_poker_type(int seq,int scol) {
	if (seq && scol) return 1;
	if (same[4])	 return 2;
	if (same[3] && same[2]) return 3;
	if (scol)	 return 4;
	if (seq)	 return 5;
	if (same[3])	 return 6;
	return 7;
}

int solve() {
    int is_seq=check_sequential();
    int is_scolor=check_same_color();
    //printf("seq:%d,color:%d\r\n",is_seq,is_scolor);
    same[2]=same[3]=same[4]=0;
    check_same_pokers();
    return check_poker_type(is_seq,is_scolor);
}

int main() {
    char in_size[4],in_color[4];
    while (scanf("%s %s",in_size,in_color)!=EOF) {
	int count=4;
	memset(poker,0,sizeof(poker));
	memset(color,0,sizeof(color));
	//printf("1.in_size=%s,in_color=%s\n",in_size,in_color);
	input(in_size,in_color);
	while (count--) {
	    assert(scanf("%s %s",in_size,in_color)!=EOF);
	    //printf("2.in_size=%s,in_color=%s\n",in_size,in_color);
	    input(in_size,in_color);
	}
	//dump(poker,16);dump(color,4);
	printf("%d\n",solve());
    }
    return 0;
}
