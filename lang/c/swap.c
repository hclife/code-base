#include <stdio.h>

void swap(int *p1,int *p2) {
	int *p;
	*p=*p1;
	*p1=*p2;
	*p2=*p;
}

int main() {
	int x=1,y=2;
	swap(&x,&y);
	printf("%d,%d\n",x,y);
	return 0;
}
