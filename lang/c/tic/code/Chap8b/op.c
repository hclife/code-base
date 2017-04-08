/* op.c: Implement the menu functions */
#include <stdio.h>

void retrieve()
{
	printf("retrieve\n");
}

void insert()
{
	printf("insert\n");
}

void update()
{
	printf("update\n");
}

int show_menu()
{
	int x;
	printf("Enter your choice:\n");
	printf("(1) retrieve\n");
	printf("(2) insert\n");
	printf("(3) update\n");
	printf("(4) quit\n");
	scanf("%d",&x);
	return x;
}
