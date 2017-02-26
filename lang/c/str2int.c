#include <stdio.h>
#include <stdlib.h>

#define is_digit(x)	((x)>='0' && (x)<='9')

int str2int(const char *s)
{
	int sign=1;
	if (*s=='+') {
		++s;
	} else if (*s=='-') {
		++s;
		sign=-1;
	}

#if 0
	int value=0;
	while (*s) {
		if (is_digit(*s)) {
			value=value*10+*s-'0';
			++s;
		} else {
			break;
		}
	}
#endif
	int value=0;
	while (*s && is_digit(*s)) {
		value=value*10+*s-'0';
		++s;
	}

	return sign*value;
}

int main()
{
	char *s1="+128";
	char *s2="-128";
	char *s3="128";

	printf("%d\n",str2int(s1));
	printf("%d\n",str2int(s2));
	printf("%d\n",str2int(s3));

	return 0;
}
