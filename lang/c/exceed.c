#include <stdio.h>

int main() {
	int a[5];
	for (int i=0;i<10;++i) a[i]=i;
	for (int i=0;i<10;++i) printf("%d\n",a[i]);
	return 0;
}
