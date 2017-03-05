//process hex string to a decimal number
#include <stdio.h>

#define MAXL	128
#define isd(x)	((x)>='0' && (x)<='9')
#define isa(x)	((x)>='a' && (x)<='f')
#define isA(x)	((x)>='A' && (x)<='F')

long long input_hex(const char *s) {
	long long x,num=0;
	while (*s) {
		if (isd(*s)) x=*s-'0';
		else if (isa(*s)) x=*s-'a'+10;
		else if (isA(*s)) x=*s-'A'+10;
		else return -1;
		num=num*16+x;
		++s;
	}
	return num;
}

int main() {
	char buf[MAXL];scanf("%s",buf);
	printf("%lld\n",input_hex(buf));
}
