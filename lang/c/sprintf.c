#include <stdio.h>

int main() {
	char str[256]={0};
	int data=1024;
	sprintf(str,"%d",data);puts(str);
	sprintf(str,"0x%x",data);puts(str);
	sprintf(str,"0%o",data);puts(str);

	const char *s1="Hello";
	const char *s2="World";
	sprintf(str,"%s %s",s1,s2);puts(str);

	return 0;
}
