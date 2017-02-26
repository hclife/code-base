#include <stdio.h>

int main() {
	char s[15]="123.432,432";
	int n;
	double f1;
	int f2;
	sscanf(s,"%lf,%d%n",&f1,&f2,&n);
	printf("%lf %d %d\n",f1,f2,n);
	return 0;
}
