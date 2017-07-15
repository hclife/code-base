//shift and loop the string towards right
#include <stdio.h>
#include <string.h>

#define SIZE	1024
#define rint	register int

void shift0(char *s,int n) {
	if (n<=0) return;
	int len=strlen(s);
	if (n>=len) {
		shift0(s,n%len);
		return;
	}
	char c=s[len-1];
	for (rint i=len-1;i>0;--i)
		s[i]=s[i-1];
	s[0]=c;
	shift0(s,n-1);
}

void shift1(char *s,int n) {
	int len=strlen(s);
	if (n>=len) n%=len;
	if (n<=0) return;
	while (n--) {
		char c=s[len-1];
		for (rint i=len-1;i>0;--i)
			s[i]=s[i-1];
		s[0]=c;
	}
}

void shift2(char *s,int n) {
	int len=strlen(s);
	if (n>=len) n%=len;
	if (n<=0) return;
	register int j=0;char t[len+1];
	for (rint i=len-n;i<len;++i) t[j++]=s[i];
	for (rint i=0;i<len-n;++i) t[j++]=s[i];
	t[j]=0;
	char *p=s,*q=t;
	while (*p++=*q++);
}

int main() {
	freopen("string_shift.txt","r",stdin);
	int T;scanf("%d",&T);
	int n;char buf[SIZE];
	while (T--) {
		scanf("%s %d",buf,&n);
		shift0(buf,n);
		puts(buf);
	}
	return 0;
}
