#include <stdio.h>

int main() {
	int x=1;char *p=(char *)&x;
	if (*p) printf("little-endian\n");
	else printf("big-endian\n");
	return 0;
}
