#include <stdio.h>

const char *a="This is good.";
const char *b="This is good.";

void check(const char *x,const char *y) {
    if (x==y) printf("same\n");
    else printf("not same\n");
}

int main() {
	char s[]="test func.";
	char t[]="test func.";

	check(a,b);
	check(s,t);

	return 0;
}
