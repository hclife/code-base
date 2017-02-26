#include <stdio.h>

int is(int x) {
	return x&1;
	if (x<2 || x&1==0) return 0;
	return 1;
}

int main() {
	int x;
	while (scanf("%d",&x)) {
		printf("%d\n",is(x));
	}
	return 0;
}
