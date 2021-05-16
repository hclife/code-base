#include <stdlib.h>
#include <stdio.h>

void fun(int *p1,int *p2,int *s) {
	//s=(int*)malloc(sizeof(int));
	*s=*p1+*(p2++);
}

int main() {
	int a[2]={1,2};
	int b[2]={10,20};
	int *s=a;
	fun(a,b,s);
	printf("%d\n",*s);
	return 0;
}
