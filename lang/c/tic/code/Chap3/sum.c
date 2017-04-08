#include <stdio.h>

void main()
{
	int x,y,z;
	int evens,odds;

	evens=odds=0;
	printf("Enter three integers: ");
	scanf("%d %d %d",&x,&y,&z);
	if (x&1) odds+=x;else evens+=x;
	if (y&1) odds+=y;else evens+=y;
	if (z&1) odds+=z;else evens+=z;
	printf("sum of evens: %d\n",evens);
	printf("sum of odds: %d\n",odds);
}
