#include <stdio.h>

union test {
	short a;
	char b;
};

int main() {
	union test t;t.a=1;
	if (t.b) printf("little-endian\n");
	else printf("big-endian\n");
	return 0;
}
