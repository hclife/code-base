//A->a,a->A,0-9->0-9
//others->deletion
#include <stdio.h>

void test(char *s)
{
	register int i,j,c;
	for (i=j=0;c=s[i];++i) {
		if (c>='A' && c<='Z') s[j++]=c+('a'-'A');
		else if (c>='a' && c<='z') s[j++]=c-('a'-'A');
		else if (c>='0' && c<='9') s[j++]=c;
	}
	s[j]=0;
}

int main()
{
	char s[128];
	gets(s);test(s);puts(s);
	return 0;
}
