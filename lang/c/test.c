#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char s[10],t[10];
	int i;
	for (i=0;i<10;i++) t[i]='a';
	strcpy(s,t); //omit string terminator
	puts(s);

	void *p=malloc(10);
	printf("sizeof(p)=%u\n",sizeof(p));
	printf("sizeof(*p)=%u\n",sizeof(*p));

	char str[100];
	printf("sizeof(str)=%u\n",sizeof(str));

	i=0;
	int f=0.0f;
	printf("%d\n",i==f);

	return 0;
}
