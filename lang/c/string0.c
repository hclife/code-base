//delete all spaces from string
#include <stdio.h>

void test(char *s) {
	register int i,j,c;
	for (i=j=0;c=s[i];++i)
	if (c!=' ') s[j++]=c;
	s[j]=0;
}

int main() {
	char s[128];
	gets(s);test(s);puts(s);
	return 0;
}
