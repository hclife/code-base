/* mem_copy.c: memory copy */
#include <stdio.h>

void mem_copy(void *target, const void *source, size_t n)
{
	char *tp=(char *)target;
	const char *sp=(char *)source;
	while (n--) *tp++=*sp++;
}

int main()
{
	float x=1.0f,y=2.0f;
	mem_copy(&x,&y,sizeof(x));
	printf("%f\n",x);
	return 0;
}
