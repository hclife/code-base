#include <stdio.h>
#include <stdarg.h>

int va_sum(int *a,...);

int main()
{
	int num=1;
	int sum=va_sum(&num,2,3,4,5,6,0);
	printf("sum=%d\n",sum);
	return 0;
}

int va_sum(int *a,...)
{
	int count=0;
	int element=0;
	va_list args;

	va_start(args,a);
	while (element=va_arg(args,int))
		count+=element;
	va_end(args);

	return count;
}
