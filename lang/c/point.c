#include <stdio.h>

int main() {
	char s[]="abc";
	char t[]={'a','b','c'};
	char p[10][10];
	printf("sizeof(s)=%lu\n",sizeof(s));
	printf("sizeof(t)=%lu\n",sizeof(t));
	printf("sizeof(p)=%lu\n",sizeof(p));
	return 0;
}
