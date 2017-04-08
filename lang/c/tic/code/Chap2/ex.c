#include <stdio.h>

void main()
{
	int x;
	float f;
	printf("Enter a float number:");
	scanf("%f",&f);
	x=(int)f;f-=x;
	if (f>=0.5f) ++x;
	printf("%d\n",x);
}
