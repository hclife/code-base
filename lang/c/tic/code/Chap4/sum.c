#include <stdio.h>

int main()
{
	int x,evens,odds;
	evens=odds=0;
	while (1) {
		printf("Enter an integer: ");
		scanf("%d",&x);if (!x) break;
		switch (x&1) {
		case 1: odds+=x;break;
		case 0: evens+=x;break;
		default: break;
		}
	}
	printf("sum of evens: %d\n",evens);
	printf("sum of odds: %d\n",odds);
	return 0;
}
