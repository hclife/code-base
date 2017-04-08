/* inspect.c: inspect the contents of each byte in hex. */
#include <stdio.h>

void inspect(const void *s, size_t n)
{
	const char *p=(char *)s;
	while (n--) printf("0x%02x ",*p++);
	printf("\n");
}

int main()
{
	int x=0x0302;
	inspect(&x,sizeof(x));
	return 0;
}
