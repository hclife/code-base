#include <stdio.h>
#include <stdarg.h>

#define MAXBUF_SIZE	1024

int my_printf(const char *str,...);

int main()
{
	my_printf("Hello_world\n");
	return 0;
}

int my_printf(const char *str,...)
{
	char buf[MAXBUF_SIZE];
}
