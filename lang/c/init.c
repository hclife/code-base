#include <stdio.h>

static int global;

static int func(int x) {
	int tmp;
	static int sin;

	printf("func:tmp=%d\n",tmp); //unexpected value
	printf("func:sin=%d\n",sin); //default zero

	return 0;
}

int main() {
	func(1);
	printf("global=%d\n",global);
	return 0;
}
