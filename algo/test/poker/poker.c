#include <stdio.h>
#include <string.h>
#include <assert.h>

#define is_digit(x)	((x)>='0' && (x)<='9')
#define is_upper(x)	((x)>='A' && (x)<='Z')
#define is_lower(x)	((x)>='a' && (x)<='z')
#define is_alpha(x)	(is_upper(x) || is_lower(x))

int poker[16],color[4];

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

int solve() {
    int is_seq=check_is_seq();
    int is_same_color=check_is_
    return 7;
}

int main() {
    char in_size[4],in_color[4];
    while (scanf("%s %s",in_size,in_color)!=EOF) {
	int count=4;
	memset(poker,0,sizeof(poker));
	memset(color,0,sizeof(color));
	printf("1.in_size=%s,in_color=%s\n",in_size,in_color);
	input(in_size,in_color);
	while (count--) {
	    assert(scanf("%s %s",in_size,in_color)!=EOF);
	    printf("2.in_size=%s,in_color=%s\n",in_size,in_color);
	    input(in_size,in_color);
	}
	dump(poker,16);
	dump(color,4);
	printf("%d\n",solve());
    }
    return 0;
}
