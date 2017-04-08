#include <stdio.h>
#include "mystuff.h"

int main()
{
	int x,y;
	puts("Enter the first number:");scanf("%d",&x);
	puts("Enter the second number:");scanf("%d",&y);
	printf("The average is %.2f\n",avg(x,y));
	return 0;
}
