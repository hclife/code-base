#include <stdio.h>
#include <limits.h>

int main() {
	unsigned short limit=(USHRT_MAX+1)/2;
	unsigned short a=0;
	char name[1];
	printf("Please input 2-byte string:");
	gets(name);
	if (a>=limit) printf("big-endian\n");
	else printf("little-endian\n");
	return 0;
}
