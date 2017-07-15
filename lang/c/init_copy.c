#include <stdio.h>

int main() {
	int x=10;
	int y(x); //gcc build error, g++ build okay
	printf("x=%d,y=%d\n",x,y);
	return 0;
}
