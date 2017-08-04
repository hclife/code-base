#include <stdio.h>

char *mystrcat(char *s1,char *s2) {
	char *t=s1;
	while (*s1++);
	while (*s1++=*s2++);
	return t;
}

int main() {
	char s1[4]="abc";
	char s2[]="def";
	char *s3=mystrcat(s1,s2);
	puts(s3);
	return 0;
}
